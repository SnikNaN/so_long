/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:47:36 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 02:16:46 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_anim_rot(t_character *ch)
{
	if (ch->rotate)
	{
		ch->anim_cntr = 0;
		ch->rot_cntr += ch->rot_dir;
		ch->im = ch->ro[ch->rot_arr][ch->rot_cntr].ptr;
		if (ch->rot_cntr == 0 || ch->rot_cntr == 8)
		{
			ch->rotate = 0;
			ch->anim_cntr = 0;
			ch->rot = ch->new_rot;
		}
	}
}

void	ft_anim_mov(t_character *ch)
{
	if (!ch->rotate)
	{
		ch->anim_cntr++;
		if (ch->anim_cntr == 10)
			ch->anim_cntr = 0;
		ch->im = ch->img[ch->rot][ch->anim_cntr].ptr;
	}
}

static void	ft_count_pos(t_character *ch)
{
	if (ch->prev_x != ch->new_x)
	{
		if (ch->prev_x < ch->new_x)
			ch->prev_x += ch->speed;
		else
			ch->prev_x -= ch->speed;
	}
	if (ch->prev_y != ch->new_y)
	{
		if (ch->prev_y < ch->new_y)
			ch->prev_y += ch->speed;
		else
			ch->prev_y -= ch->speed;
	}
}

void	ft_change_pos(t_game *g, t_character *ch)
{
	if (ch->move)
	{
		ft_count_pos(ch);
		if (ft_abs(ch->prev_x - ch->new_x) < ch->speed
			&& ft_abs(ch->prev_y - ch->new_y) < ch->speed)
			ch->move = 0;
		mlx_put_image_to_window(g->mlx_ptr, g->window, ch->im,
			ch->prev_x, ch->prev_y);
	}
	else
	{
		ch->prev_x = ch->x * TILE;
		ch->prev_y = ch->y * TILE;
		mlx_put_image_to_window(g->mlx_ptr, g->window, ch->im,
			ft_fix_x(ch->x, g), ft_fix_y(ch->y, g));
	}
}

void	ft_anim_egg(t_game *g)
{
	t_list	*lst;
	t_egg	*egg;

	lst = g->eggs;
	while (lst)
	{
		egg = lst->content;
		ft_put_tile(g, egg->x, egg->y);
		mlx_put_image_to_window(egg->mlx, egg->win, egg->img, egg->x * TILE,
			egg->y * TILE);
		egg->i += egg->cnt_dir;
		if (egg->i == -1)
		{
			egg->i = 1;
			egg->cnt_dir = 1;
		}
		else if (egg->i == 10)
		{
			egg->i = 8;
			egg->cnt_dir = -1;
		}
		egg->img = g->egg_img[egg->egg][egg->i].ptr;
		lst = lst->next;
	}
}
