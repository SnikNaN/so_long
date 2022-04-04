/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_minilibx_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:23:51 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 02:21:11 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_fix_x(int x, t_game *game)
{
	int	res;

	res = x * TILE;
	if (x > game->x_size / 2)
		res--;
	return (res);
}

int	ft_fix_y(int y, t_game *game)
{
	int	res;

	res = y * TILE;
	if (y > game->y_size / 2)
		res--;
	return (res);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}
