/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:37:57 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 10:17:04 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_load_empty_imgs(t_game *game, const char *str)
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
		game->empty[i].ptr = mlx_png_file_to_image(game->mlx_ptr, s,
				&game->empty[i].w, &game->empty[i].h);
		if (!game->empty[i].ptr)
		{
			free(s);
			return (-1);
		}
		i++;
	}
	free(s);
	return (0);
}

static int	ft_load_wall_imgs(t_game *game, const char *str)
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
		game->wall[i].ptr = mlx_png_file_to_image(game->mlx_ptr, s,
				&game->wall[i].w, &game->wall[i].h);
		if (!game->wall[i].ptr)
		{
			free(s);
			return (-1);
		}
		i++;
	}
	free(s);
	return (0);
}

int	ft_load_resources(t_game *game)
{
	int	res;

	res = 0;
	res += ft_load_empty_imgs(game, "res/empty/0.png");
	res += ft_load_wall_imgs(game, "res/wall/0.png");
	game->player.img.ptr = mlx_png_file_to_image(game->mlx_ptr,
			"res/player.png", &(game->player.img.w), &(game->player.img.h));
	game->collect.img.ptr = mlx_png_file_to_image(game->mlx_ptr,
			"res/egg.png", &(game->collect.img.w),
			&(game->collect.img.h));
	game->exit_img.ptr = mlx_png_file_to_image(game->mlx_ptr,
			"res/exit.png", &(game->exit_img.w),
			&(game->exit_img.h));
	if (!game->player.img.ptr || !game->collect.img.ptr || !game->exit_img.ptr)
		res--;
	game->player.steps = 0;
	game->move = 0;
	game->you_win = 0;
	if (res < 0)
		ft_putstr_fd("Error\nCan't load resources\n", 2);
	return (res);
}
