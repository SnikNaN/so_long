/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_logics_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 08:02:40 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 08:29:45 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_check_collisions(t_game *g, int i)
{
	if (g->you_win == 0 && (ft_abs(g->enemy[i].prev_x + TILE
				- (g->player.prev_x + TILE / 2)) < TILE / 3 * 2)
		&& (ft_abs(g->enemy[i].prev_y + TILE
				- (g->player.prev_y + TILE / 2)) < TILE / 3 * 2))
	{
		g->you_win = -1;
		mlx_string_put(g->mlx_ptr, g->window,
			g->x_size / 2 * TILE - TILE / 2,
			g->y_size * TILE + 20, 0xff4444, "You lose... Press ESC for exit");
	}
}

static int	ft_count_next_action(t_game *g, int i)
{
	if (g->enemy[i].rot == UP)
	{
		if (g->enemy[i].y > ft_rnd(&g->seed, 4))
			return (g->enemy[i].y--);
	}
	else if (g->enemy[i].rot == DWN)
	{
		if (g->enemy[i].y < 0
			|| g->enemy[i].y < g->y_size - (2 + ft_rnd(&g->seed, 4)))
			return (g->enemy[i].y++);
	}
	else if (g->enemy[i].rot == LFT)
	{
		if (g->enemy[i].x > g->x_size || g->enemy[i].x > ft_rnd(&g->seed, 4))
			return (g->enemy[i].x--);
	}
	else if (g->enemy[i].rot == RGT)
	{
		if (g->enemy[i].x < 0
			|| g->enemy[i].x < g->x_size - (2 + ft_rnd(&g->seed, 4)))
			return (g->enemy[i].x++);
	}
	return (-TILE);
}

void	ft_enemy_moving(t_game *g)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!g->enemy[i].move && !g->enemy[i].rotate && g->you_win == 0)
		{
			g->enemy[i].prev_x = g->enemy[i].x * TILE;
			g->enemy[i].prev_y = g->enemy[i].y * TILE;
			if (ft_count_next_action(g, i) == -TILE)
				ft_process_rot(ft_rnd(&g->seed, 4), &g->enemy[i]);
			g->enemy[i].new_x = g->enemy[i].x * TILE;
			g->enemy[i].new_y = g->enemy[i].y * TILE;
			g->enemy[i].move = 1;
		}
		ft_check_collisions(g, i);
		i++;
	}
}
