/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 06:17:17 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 08:34:35 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_tile(t_game *game, int x, int y)
{
	if (x >= game->x_size || y >= game->y_size || x < 0 || y < 0)
		return ;
	if ((int)(game->map)[y][x] >= 0 && (int)(game->map)[y][x] < 10)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->empty[(int)game->map[y][x]].ptr, ft_fix_x(x, game),
			ft_fix_y(y, game));
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->empty[0].ptr, ft_fix_x(x, game), ft_fix_y(y, game));
		if ((game->map)[y][x] >= '1' && (game->map)[y][x] <= '8')
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				game->wall[game->map[y][x] - '1'].ptr, ft_fix_x(x, game),
				ft_fix_y(y, game));
		else if ((game->map)[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				game->exit_img.ptr, ft_fix_x(x, game), ft_fix_y(y, game));
	}
}

static void	ft_put_steps(t_game *g)
{
	char	*steps;
	int		y;

	y = g->y_size * TILE + 20;
	steps = ft_itoa(g->steps);
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "00000000000");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "11111111111");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "22222222222");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "33333333333");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "44444444444");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "55555555555");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "66666666666");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "77777777777");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "88888888888");
	mlx_string_put(g->mlx_ptr, g->window, 80, y, 0, "99999999999");
	if (steps)
	{
		mlx_string_put(g->mlx_ptr, g->window, 80, y, 0xb0c4ff, steps);
		free(steps);
	}
}

static void	ft_put_below_tiles(t_game *g)
{
	int	i;

	i = 0;
	ft_put_tile(g, g->player.x, g->player.y);
	while (i < 3)
	{
		ft_put_tile(g, g->enemy[i].x, g->enemy[i].y);
		ft_put_tile(g, g->enemy[i].x, g->enemy[i].y + 1);
		ft_put_tile(g, g->enemy[i].x + 1, g->enemy[i].y);
		ft_put_tile(g, g->enemy[i].x + 1, g->enemy[i].y + 1);
		if (g->enemy[i].move)
			ft_put_old(g, &g->enemy[i]);
		i++;
	}
	if (g->player.move)
		ft_put_old(g, &g->player);
}

static void	ft_animate_player_and_enemies(t_game *g)
{
	int	i;

	i = 0;
	ft_anim_mov(&g->player);
	ft_anim_rot(&g->player);
	ft_change_pos(g, &g->player);
	while (i < 3)
	{
		ft_anim_mov(&g->enemy[i]);
		ft_anim_rot(&g->enemy[i]);
		ft_change_pos(g, &g->enemy[i]);
		i++;
	}
}

int	ft_render_next_frame(t_game *g)
{
	if (g->tick % (TICK) == 0)
	{
		ft_put_below_tiles(g);
		ft_anim_egg(g);
		ft_animate_player_and_enemies(g);
		ft_put_steps(g);
		ft_check_collected(&g->eggs, g->player);
		ft_enemy_moving(g);
		if (g->you_win && !g->player.rotate)
		{
			if (g->player.rot == 3)
				ft_process_rot(0, &g->player);
			else
				ft_process_rot(g->player.rot + 1, &g->player);
		}
	}
	g->tick++;
	if (g->tick > TICK)
		g->tick = 1;
	return (0);
}
