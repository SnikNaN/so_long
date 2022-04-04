/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eggs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:21:52 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 08:33:38 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_create_egg(t_game *g, int x, int y)
{
	t_list	*new_elem;
	t_egg	*egg;

	egg = malloc(sizeof(t_egg));
	if (!egg)
		return (-1);
	egg->egg = ft_rnd(&g->seed, 4);
	egg->i = 1 + ft_rnd(&g->seed, 7);
	egg->x = x;
	egg->y = y;
	egg->mlx = g->mlx_ptr;
	egg->win = g->window;
	egg->img = g->egg_img[egg->egg][egg->i].ptr;
	egg->cnt_dir = 1;
	new_elem = ft_lstnew(egg);
	if (!new_elem)
	{
		free(egg);
		return (-1);
	}
	ft_lstadd_back(&g->eggs, new_elem);
	return (0);
}

int	ft_create_eggs_list(t_game *g)
{
	int	x;
	int	y;

	y = 1;
	while (y < g->y_size - 1)
	{
		x = 1;
		while (x < g->x_size - 1)
		{
			if ((g->map)[y][x] == 'C')
			{
				if (ft_create_egg(g, x, y) == -1)
				{
					ft_putstr_fd("Error\nMalloc error on creating eggs\n", 2);
					return (-1);
				}
				g->map[y][x] = (char)ft_rnd(&g->seed, 8);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_delete_node(t_list **begin_list, t_list **curr, t_list **prev)
{
	if (*begin_list != *prev)
		(*curr)->next = (*prev)->next;
	else
		*begin_list = (*prev)->next;
	*curr = *prev;
	*prev = (*curr)->next;
	free((*curr)->content);
	free(*curr);
}

void	ft_check_collected(t_list **begin_list, t_character pl)
{
	t_list	*curr;
	t_list	*prev;
	t_egg	*egg;

	prev = *begin_list;
	while (prev)
	{
		egg = prev->content;
		if ((ft_abs(egg->x * TILE - pl.prev_x) < (pl.speed * 2))
			&& (ft_abs(egg->y * TILE - pl.prev_y) < (pl.speed * 2)))
		{
			ft_delete_node(begin_list, &curr, &prev);
		}
		else
		{
			curr = prev;
			prev = curr->next;
		}
	}
}
