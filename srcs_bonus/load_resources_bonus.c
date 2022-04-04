/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_resources_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:37:57 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 01:56:49 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_load_map_imgs(t_game *g, t_img img[8], const char *str)
{
	char	*s;
	int		i;

	s = ft_strdup(str);
	if (!s)
		return (-1);
	i = 0;
	while (i < 8)
	{
		s[ft_strlen(s) - 5] = '0' + i;
		img[i].ptr = mlx_png_file_to_image(g->mlx_ptr, s, &img[i].w, &img[i].h);
		if (!img[i].ptr)
		{
			free(s);
			return (-1);
		}
		i++;
	}
	free(s);
	return (0);
}

int	ft_png_to_arr(t_game *g, t_img img[4][10], char **s, int rot)
{
	int		i;

	if (!(*s))
		return (-1);
	i = 0;
	while (i < 10)
	{
		(*s)[ft_strlen(*s) - 5] = '0' + i;
		img[rot][i].ptr = mlx_png_file_to_image(g->mlx_ptr, *s,
				&img[rot][i].w, &img[rot][i].h);
		if (!img[rot][i].ptr)
		{
			free(*s);
			return (-1);
		}
		i++;
	}
	free(*s);
	return (0);
}

static int	ft_load_rot_imgs(t_game *g, t_img img[6][9], char **s, int rot)
{
	int		i;

	if (!(*s))
		return (-1);
	i = 0;
	while (i < 9)
	{
		(*s)[ft_strlen(*s) - 5] = '0' + i;
		img[rot][i].ptr = mlx_png_file_to_image(g->mlx_ptr, *s,
				&img[rot][i].w, &img[rot][i].h);
		if (!img[rot][i].ptr)
		{
			free(*s);
			return (-1);
		}
		i++;
	}
	free(*s);
	return (0);
}

static int	ft_load_character(t_game *g, t_character *ch, char *str)
{
	int		res;
	char	*path;

	res = 0;
	path = ft_strjoin(str, "/d/0.png");
	res += ft_png_to_arr(g, ch->img, &path, DWN);
	path = ft_strjoin(str, "/r/0.png");
	res += ft_png_to_arr(g, ch->img, &path, RGT);
	path = ft_strjoin(str, "/u/0.png");
	res += ft_png_to_arr(g, ch->img, &path, UP);
	path = ft_strjoin(str, "/l/0.png");
	res += ft_png_to_arr(g, ch->img, &path, LFT);
	path = ft_strjoin(str, "/dl/0.png");
	res += ft_load_rot_imgs(g, ch->ro, &path, DL);
	path = ft_strjoin(str, "/lu/0.png");
	res += ft_load_rot_imgs(g, ch->ro, &path, LU);
	path = ft_strjoin(str, "/ur/0.png");
	res += ft_load_rot_imgs(g, ch->ro, &path, UR);
	path = ft_strjoin(str, "/rd/0.png");
	res += ft_load_rot_imgs(g, ch->ro, &path, RD);
	path = ft_strjoin(str, "/du/0.png");
	res += ft_load_rot_imgs(g, ch->ro, &path, DU);
	path = ft_strjoin(str, "/lr/0.png");
	res += ft_load_rot_imgs(g, ch->ro, &path, LR);
	return (res);
}

int	ft_load_resources(t_game *g)
{
	static int	res;

	res += ft_load_map_imgs(g, g->empty, "res/empty/0.png");
	res += ft_load_map_imgs(g, g->wall, "res/wall/0.png");
	res += ft_load_character(g, &g->player, "res/hero");
	res += ft_load_character(g, &g->enemy[0], "res/enemy/0");
	res += ft_load_character(g, &g->enemy[1], "res/enemy/1");
	res += ft_load_character(g, &g->enemy[2], "res/enemy/2");
	res += ft_load_eggs(g);
	g->exit_img.ptr = mlx_png_file_to_image(g->mlx_ptr,
			"res/exit.png", &(g->exit_img.w), &(g->exit_img.h));
	if (!g->exit_img.ptr)
		res--;
	if (res < 0)
		ft_putstr_fd("Error\nCan't load resources\n", 2);
	ft_initialize_game(g);
	return (res);
}
