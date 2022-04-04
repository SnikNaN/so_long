/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:33:14 by eshana            #+#    #+#             */
/*   Updated: 2021/10/08 22:40:37 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->y)
		{
			if (game->map[i])
				free((game->map)[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

static int	ft_exit_success(t_game *game)
{
	ft_free_map(game);
	exit(EXIT_SUCCESS);
}

void	ft_process_moving(t_game *game, int x, int y)
{
	if ((int)game->map[y][x] >= 0 && (int)game->map[y][x] < 10)
	{
		game->player.x = x;
		game->player.y = y;
		game->move = 1;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = (char)0;
		game->collect.cnt--;
		game->player.x = x;
		game->player.y = y;
		game->move = 1;
	}
	if (game->map[y][x] == 'E' && game->collect.cnt == 0)
	{
		game->player.x = x;
		game->player.y = y;
		game->move = 1;
		game->you_win = 1;
		mlx_string_put(game->mlx_ptr, game->window,
			game->x / 2 * TILE - TILE / 2,
			game->y / 2 * TILE, 0x00ffffff, "You win! Press ESC for exit");
	}
}

static int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_exit_success(game);
	if (game->move || game->you_win)
		return (0);
	if (keycode == KEY_D)
		ft_process_moving(game, game->player.x + 1, game->player.y);
	if (keycode == KEY_S)
		ft_process_moving(game, game->player.x, game->player.y + 1);
	if (keycode == KEY_A)
		ft_process_moving(game, game->player.x - 1, game->player.y);
	if (keycode == KEY_W)
		ft_process_moving(game, game->player.x, game->player.y - 1);
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
		game.window = mlx_new_window(game.mlx_ptr, game.x * TILE,
				game.y * TILE, "so_long");
		ft_draw_map(&game);
		mlx_loop_hook(game.mlx_ptr, ft_render_next_frame, &game);
		mlx_hook(game.window, 2, 1L << 0, ft_key_hook, &game);
		mlx_hook(game.window, 17, 1L << 17, ft_exit_success, &game);
		mlx_do_sync(game.mlx_ptr);
		mlx_do_key_autorepeaton(game.mlx_ptr);
		mlx_loop(game.mlx_ptr);
	}
	ft_putstr_fd("Error\nInvalid arguments. Usage: ./so_long <map file>\n", 2);
	exit(EXIT_FAILURE);
}
