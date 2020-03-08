/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_horizontal_intersec.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:44:05 by ozakkare          #+#    #+#             */
/*   Updated: 2020/03/03 16:52:36 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_sprite_info *sprite_info)
{
	sprite_info->x = 0;
	sprite_info->y = 0;
	sprite_info->center_distance = 0;
	sprite_info->intersec_distance = 0;
	sprite_info->x_off = 0;
}

void	hor_help(t_ii *i, t_equation *eq, t_hv *inter, t_sprite_info *sp)
{
	t_sprite_info	*help;

	help = malloc(sizeof(t_sprite_info));
	help->x = (((int)inter->x / 256) * 256) + 128;
	help->y = ((((int)inter->y - eq->helper) / 256) * 256) + 128;
	if ((i->c->a - inter->x))
		eq->a = (float)(i->c->b - inter->y) / (float)(i->c->a - inter->x);
	eq->b = inter->y - (eq->a * inter->x);
	eq->b1 = help->y + ((1 / eq->a) * help->x);
	i->hxsprite = (eq->b1 - eq->b) / (eq->a + (1 / eq->a));
	i->hysprite = ((-1 / eq->a) * i->hxsprite) + eq->b1;
	help->x_off = 128 - sqrt(pow(help->x - i->hxsprite, 2)
	+ pow(help->y - i->hysprite, 2));
	help->intersec_distance = sqrt(pow(i->c->a - inter->x, 2)
	+ pow(i->c->b - inter->y, 2));
	help->center_distance = sqrt(pow(i->c->a - help->x, 2)
	+ pow(i->c->b - help->y, 2));
	sp[i->ind] = *help;
	free(help);
	i->ind++;
}

void	ray_direction(t_ii *i, t_equation *equation, float o, t_hv *inter)
{
	equation->a = 0.1;
	equation->helper = 0;
	if (o >= M_PI)
	{
		up(i, inter, o);
		equation->helper++;
	}
	else
		down(i, inter, o);
}

float	horizontal_sprite(t_ii *i, float o, t_sprite_info *sprite_info, int x)
{
	t_hv			inter;
	t_equation		equation;

	x = 0;
	ray_direction(i, &equation, o, &inter);
	inter.x = i->c->a + ((inter.y - i->c->b) / tan(o));
	while (1)
	{
		if ((!((int)((inter.y - equation.helper) / i->tilesize)
		< i->tab->rows && (int)((inter.x) / i->tilesize) < i->tab->columns
		&& ((int)((inter.y - equation.helper) / i->tilesize) >= 0)
		&& ((int)((inter.x) / i->tilesize) >= 0))))
			break ;
		if (i->tab->tab[(int)((inter.y - equation.helper)
		/ i->tilesize)][(int)(inter.x / i->tilesize)] == '2')
			hor_help(i, &equation, &inter, sprite_info);
		if (i->tab->tab[(int)((inter.y - equation.helper)
		/ i->tilesize)][(int)(inter.x / i->tilesize)] == '1')
			return (1);
		inter.x += inter.xa;
		inter.y += inter.ya;
	}
	return (sqrt(pow(i->c->a - inter.x, 2) + pow(i->c->b - inter.y, 2)));
}
