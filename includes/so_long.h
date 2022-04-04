/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:34:17 by eshana            #+#    #+#             */
/*   Updated: 2021/10/08 22:33:52 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 128
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_player
{
	t_img	img;
	int		x;
	int		y;
	int		steps;
}	t_player;

typedef struct s_collect
{
	t_img	img;
	int		cnt;
}	t_collect;

typedef struct s_game
{
	char		**map;
	t_player	player;
	t_collect	collect;
	t_img		wall[8];
	t_img		empty[8];
	t_img		exit_img;
	int			move;
	int			you_win;
	int			x;
	int			y;
	void		*mlx_ptr;
	void		*window;
	int			seed;
}	t_game;

int		parse_map(int fd, t_game *game);
int		ft_check_rules(t_game *game);
int		ft_load_resources(t_game *game);
int		ft_open(char *filename);
int		ft_close(int fd);
int		ft_fix_x(int x, t_game *game);
int		ft_fix_y(int y, t_game *game);
int		ft_rnd(int *seed, int lim);
void	ft_put_tile(t_game *game, int x, int y);
void	ft_draw_map(t_game *game);
int		ft_render_next_frame(t_game *game);

#endif