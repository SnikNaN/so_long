/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_resources_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:06:31 by eshana            #+#    #+#             */
/*   Updated: 2021/10/12 08:45:50 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_initialize_enemy(t_game *g, t_character *ch)
{
	if (ch == &g->enemy[0])
	{
		ch->x = -10;
		ch->y = ft_rnd(&g->seed, g->y_size - 2);
		ch->rot = RGT;
	}
	if (ch == &g->enemy[1])
	{
		ch->x = ft_rnd(&g->seed, g->x_size - 2);
		ch->y = -30;
		ch->rot = DWN;
	}
	if (ch == &g->enemy[2])
	{
		ch->x = g->x_size + 100;
		ch->y = ft_rnd(&g->seed, g->y_size - 2);
		ch->rot = LFT;
	}
	ch->anim_cntr = ft_rnd(&g->seed, 10);
	ch->im = ch->img[ch->rot][ch->anim_cntr].ptr;
	ch->move = 0;
	ch->rotate = 0;
}

void	ft_initialize_game(t_game *g)
{
	int	i;

	i = 0;
	g->steps = 0;
	g->player.rot = DWN;
	g->player.im = g->player.img[DWN][0].ptr;
	g->player.move = 0;
	g->you_win = 0;
	g->tick = 0;
	g->player.anim_cntr = 0;
	g->player.rotate = 0;
	g->player.speed = PL_SPEED;
	while (i < 3)
	{
		ft_initialize_enemy(g, &g->enemy[i]);
		g->enemy[i].speed = (i + 2) * ENM_SPEED + g->y_size / 4;
		i++;
	}
}

int	ft_load_eggs(t_game *g)
{
	int		res;
	char	*str;

	res = 0;
	str = ft_strdup("res/egg/0/0.png");
	res += ft_png_to_arr(g, g->egg_img, &str, 0);
	str = ft_strdup("res/egg/1/0.png");
	res += ft_png_to_arr(g, g->egg_img, &str, 1);
	str = ft_strdup("res/egg/2/0.png");
	res += ft_png_to_arr(g, g->egg_img, &str, 2);
	str = ft_strdup("res/egg/3/0.png");
	res += ft_png_to_arr(g, g->egg_img, &str, 3);
	return (res);
}
