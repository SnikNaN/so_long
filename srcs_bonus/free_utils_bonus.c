/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 08:17:12 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 08:18:17 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->y_size)
		{
			if (game->map[i])
				free((game->map)[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

int	ft_exit_success(t_game *game)
{
	ft_free_map(game);
	ft_lstclear(&game->eggs, free);
	exit(EXIT_SUCCESS);
}
