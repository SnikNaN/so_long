/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:34:17 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 08:20:27 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define TILE 128
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
/* FRAMERATE CORRECTION */
# define TICK 300
/* SPEED MUST BE A FEWER THAN TILE !!! */
# define PL_SPEED 8
# define ENM_SPEED 2

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line_bonus.h"

enum e_dir
{
	DWN,
	LFT,
	UP,
	RGT
};

enum e_rot
{
	DL,
	LU,
	UR,
	RD,
	DU,
	LR
};

enum e_rot_dir
{
	CCW = -1,
	CW = 1
};

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_egg
{
	void	*img;
	void	*mlx;
	void	*win;
	int		egg;
	int		i;
	int		cnt_dir;
	int		x;
	int		y;
}	t_egg;

typedef struct s_character
{
	t_img	img[4][10];
	t_img	ro[6][9];
	void	*im;
	int		x;
	int		y;
	int		move;
	int		rotate;
	int		rot;
	int		new_rot;
	int		rot_dir;
	int		rot_arr;
	int		rot_cntr;
	int		prev_x;
	int		prev_y;
	int		new_x;
	int		new_y;
	int		anim_cntr;
	int		speed;
}	t_character;

typedef struct s_game
{
	char		**map;
	t_character	player;
	t_character	enemy[3];
	int			collectibles;
	int			steps;
	t_img		egg_img[4][10];
	t_list		*eggs;
	t_img		wall[8];
	t_img		empty[8];
	t_img		exit_img;
	int			you_win;
	int			x_size;
	int			y_size;
	void		*mlx_ptr;
	void		*window;
	int			seed;
	int			tick;
}	t_game;

int		parse_map(int fd, t_game *game);
int		ft_check_rules(t_game *game);
int		ft_load_resources(t_game *g);
int		ft_create_eggs_list(t_game *g);
int		ft_open(char *filename);
int		ft_close(int fd);
int		ft_fix_x(int x, t_game *game);
int		ft_fix_y(int y, t_game *game);
int		ft_rnd(int *seed, int lim);
void	ft_put_tile(t_game *game, int x, int y);
void	ft_put_old(t_game *g, t_character *ch);
void	ft_draw_map(t_game *game);
int		ft_render_next_frame(t_game *g);
void	ft_anim_rot(t_character *ch);
void	ft_anim_mov(t_character *ch);
void	ft_change_pos(t_game *g, t_character *ch);
void	ft_anim_egg(t_game *g);
void	ft_check_collected(t_list **begin_list, t_character pl);
void	ft_initialize_game(t_game *g);
int		ft_load_eggs(t_game *g);
int		ft_png_to_arr(t_game *g, t_img img[4][10], char **s, int rot);
int		ft_abs(int num);
void	ft_enemy_moving(t_game *g);
void	ft_process_rot(int rot, t_character *ch);
int		ft_exit_success(t_game *game);
void	ft_free_map(t_game *game);

#endif