/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:17:19 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 07:32:03 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_old(t_game *g, t_character *ch)
{
	int	x;
	int	y;

	x = ch->prev_x / TILE;
	if (ch->prev_x > ch->new_x)
		x++;
	y = ch->prev_y / TILE;
	if (ch->prev_y > ch->new_y)
		y++;
	ft_put_tile(g, x, y);
	if (ch == &g->enemy[0] || ch == &g->enemy[1] || ch == &g->enemy[2])
	{
		ft_put_tile(g, x + 1, y);
		ft_put_tile(g, x, y + 1);
		ft_put_tile(g, x + 1, y + 1);
	}
}
