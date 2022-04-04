/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:33:14 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 08:33:00 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_process_moving(t_game *g, int x, int y)
{
	char	c;

	c = g->map[y][x];
	if (c == 'E' && ft_lstsize(g->eggs) == 0)
	{
		g->you_win = 1;
		mlx_string_put(g->mlx_ptr, g->window,
			g->x_size / 2 * TILE - TILE / 2,
			g->y_size * TILE + 20, 0x00FF44, "You win! Press ESC for exit...");
	}
	if ((c >= 0 && c < 10) || c == 'C' || (c == 'E' && g->you_win == 1))
	{
		g->player.prev_x = g->player.x * TILE;
		g->player.prev_y = g->player.y * TILE;
		g->player.new_x = x * TILE;
		g->player.new_y = y * TILE;
		g->player.x = x;
		g->player.y = y;
		g->player.move = 1;
		g->steps++;
	}
}

void	ft_set_rot(int i, int arr, int dir, t_character *ch)
{
	ch->rot_cntr = i;
	ch->rot_arr = arr;
	ch->rot_dir = dir;
	ch->rotate = 1;
}

void	ft_process_rot(int rot, t_character *ch)
{
	ch->new_rot = rot;
	if (ch->rot == DWN && rot == LFT)
		ft_set_rot(0, DL, CW, ch);
	else if (ch->rot == UP && rot == LFT)
		ft_set_rot(8, LU, CCW, ch);
	else if (ch->rot == RGT && rot == LFT)
		ft_set_rot(8, LR, CCW, ch);
	else if (ch->rot == LFT && rot == DWN)
		ft_set_rot(8, DL, CCW, ch);
	else if (ch->rot == RGT && rot == DWN)
		ft_set_rot(0, RD, CW, ch);
	else if (ch->rot == UP && rot == DWN)
		ft_set_rot(8, DU, CCW, ch);
	else if (ch->rot == DWN && rot == RGT)
		ft_set_rot(8, RD, CCW, ch);
	else if (ch->rot == UP && rot == RGT)
		ft_set_rot(0, UR, CW, ch);
	else if (ch->rot == LFT && rot == RGT)
		ft_set_rot(0, LR, CW, ch);
	else if (ch->rot == RGT && rot == UP)
		ft_set_rot(8, UR, CCW, ch);
	else if (ch->rot == LFT && rot == UP)
		ft_set_rot(0, LU, CW, ch);
	else if (ch->rot == DWN && rot == UP)
		ft_set_rot(0, DU, CW, ch);
}

static int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_exit_success(game);
	if (game->player.rotate || game->player.move || game->you_win)
		return (0);
	if (keycode == KEY_D)
	{
		ft_process_rot(RGT, &game->player);
		ft_process_moving(game, game->player.x + 1, game->player.y);
	}
	if (keycode == KEY_S)
	{
		ft_process_rot(DWN, &game->player);
		ft_process_moving(game, game->player.x, game->player.y + 1);
	}
	if (keycode == KEY_A)
	{
		ft_process_rot(LFT, &game->player);
		ft_process_moving(game, game->player.x - 1, game->player.y);
	}
	if (keycode == KEY_W)
	{
		ft_process_rot(UP, &game->player);
		ft_process_moving(game, game->player.x, game->player.y - 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.mlx_ptr = mlx_init();
		if (parse_map(ft_open(argv[1]), &game) + ft_load_resources(&game) < 0)
		{
			ft_free_map(&game);
			exit(EXIT_FAILURE);
		}
		game.window = mlx_new_window(game.mlx_ptr, game.x_size * TILE,
				game.y_size * TILE + 30, "so_long");
		ft_create_eggs_list(&game);
		ft_draw_map(&game);
		mlx_loop_hook(game.mlx_ptr, ft_render_next_frame, &game);
		mlx_hook(game.window, 2, 1L << 0, ft_key_hook, &game);
		mlx_hook(game.window, 17, 1L << 17, ft_exit_success, &game);
		mlx_do_sync(game.mlx_ptr);
		mlx_loop(game.mlx_ptr);
	}
	ft_putstr_fd("Error\nInvalid arguments. Usage: ./so_long <map file>\n", 2);
	exit(EXIT_FAILURE);
}
