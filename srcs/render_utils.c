/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 06:17:17 by eshana            #+#    #+#             */
/*   Updated: 2021/10/08 22:47:50 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_tile(t_game *game, int x, int y)
{
	if (x >= game->x || y >= game->y || x < 0 || y < 0)
		return ;
	if ((int)(game->map)[y][x] >= 0 && (int)(game->map)[y][x] < 8)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->empty[(int)game->map[y][x]].ptr, ft_fix_x(x, game),
			ft_fix_y(y, game));
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->empty[0].ptr, ft_fix_x(x, game), ft_fix_y
			(y, game));
		if ((game->map)[y][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				game->wall[ft_rnd(&game->seed, 8)].ptr, ft_fix_x(x, game),
				ft_fix_y(y, game));
		else if ((game->map)[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				game->exit_img.ptr, ft_fix_x(x, game), ft_fix_y(y, game));
		else if ((game->map)[y][x] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				game->collect.img.ptr, ft_fix_x(x, game), ft_fix_y(y, game));
	}
}

void	ft_draw_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			ft_put_tile(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window,
		game->player.img.ptr, ft_fix_x(game->player.x, game),
		ft_fix_y(game->player.y, game));
}

static void	ft_put_steps(int cnt)
{
	ft_putchar_fd('\r', 1);
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(cnt, 1);
}

int	ft_render_next_frame(t_game *game)
{
	static int	player_x;
	static int	player_y;

	if (game->move)
	{
		ft_put_tile(game, player_x, player_y);
		if ((int)game->map[game->player.y][game->player.x] != 'E')
			ft_put_tile(game, game->player.x, game->player.y);
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->player.img.ptr,
			ft_fix_x(game->player.x, game), ft_fix_y(game->player.y, game));
		game->player.steps++;
		game->move = 0;
	}
	else
	{
		player_x = game->player.x;
		player_y = game->player.y;
	}
	ft_put_steps(game->player.steps);
	return (0);
}
