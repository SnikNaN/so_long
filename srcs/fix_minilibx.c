/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:23:51 by eshana            #+#    #+#             */
/*   Updated: 2021/10/03 20:14:09 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fix_x(int x, t_game *game)
{
	int	res;

	res = x * TILE;
	if (x > game->x / 2)
		res--;
	return (res);
}

int	ft_fix_y(int y, t_game *game)
{
	int	res;

	res = y * TILE;
	if (y > game->y / 2)
		res--;
	return (res);
}
