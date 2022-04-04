/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:43:45 by eshana            #+#    #+#             */
/*   Updated: 2021/10/08 23:24:05 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	ft_put_error(char *s)
{
	ft_putstr_fd(s, 2);
	return (-1);
}

static int	ft_get_line(int fd, int *val, t_list **lst, char **line)
{
	t_list	*new_elem;

	*val = get_next_line(fd, line);
	if (*val >= 0)
	{
		new_elem = ft_lstnew(*line);
		if (!new_elem)
		{
			ft_put_error("Error\nGNL is failed\n");
			*val = -1;
			return (-1);
		}
		ft_lstadd_back(lst, new_elem);
		return (*val);
	}
	return (*val);
}

static int	ft_copy_lines(t_game *game, t_list *lst)
{
	int		lst_size;

	lst_size = ft_lstsize(lst);
	while (game->y < lst_size)
	{
		(game->map)[game->y] = ft_strdup(lst->content);
		if ((game->map)[game->y] == NULL)
		{
			(game->y)--;
			while (game->y >= 0)
			{
				free((game->map)[game->y]);
				(game->y)--;
			}
			return (-1);
		}
		lst = lst->next;
		(game->y)++;
	}
	return (0);
}

int	parse_map(int fd, t_game *game)
{
	char	*line;
	int		val;
	t_list	*lst;

	val = 0;
	game->map = NULL;
	lst = NULL;
	game->y = 0;
	while (ft_get_line(fd, &val, &lst, &line) > 0)
		;
	if (val == 0)
	{
		game->map = (char **)ft_calloc(ft_lstsize(lst), sizeof(char *));
		if (game->map == NULL)
			val = ft_put_error("Error\nMemory allocation is failed\n");
		if (val == 0 && ft_copy_lines(game, lst) < 0)
		{
			val = ft_put_error("Error\nMemory allocation is failed\n");
			free(game->map);
		}
	}
	ft_lstclear(&lst, free);
	return (val + ft_check_rules(game) + ft_close(fd));
}
