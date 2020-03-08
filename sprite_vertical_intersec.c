/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_vertical_intersec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:40:28 by ozakkare          #+#    #+#             */
/*   Updated: 2020/03/03 16:55:19 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ver_help(t_hv *inter, t_ii *i, t_equation *eq,
t_sprite_info *sprite_info)
{
	t_sprite_info *help;

	help = malloc(sizeof(t_sprite_info));
	help->y = (((int)inter->y / 256) * 256) + 128;
	help->x = ((((int)inter->x - eq->helper) / 256) * 256) + 128;
	if (i->c->b - inter->y)
		eq->a = (float)(i->c->b - inter->y) / (float)(i->c->a - inter->x);
	eq->b = inter->y - (eq->a * inter->x);
	eq->b1 = help->y + ((1 / eq->a) * help->x);
	i->vxsprite = (eq->b1 - eq->b)
	/ (eq->a + (1 / eq->a));
	i->vysprite = ((-1 / eq->a) * i->vxsprite) + eq->b1;
	help->x_off = 128 - sqrt(pow(help->x - i->vxsprite, 2)
	+ pow(help->y - i->vysprite, 2));
	help->intersec_distance = sqrt(pow(i->c->a - inter->x, 2)
	+ pow(i->c->b - inter->y, 2));
	help->center_distance = sqrt(pow(i->c->a - help->x, 2)
	+ pow(i->c->b - help->y, 2));
	sprite_info[i->ind] = *help;
	free(help);
	i->ind++;
}

void	ver_direction(t_ii *i, t_hv *inter, t_equation *equation, float o)
{
	if (o >= 270 * M_PI / 180 || o < 90 * M_PI / 180)
		right(i, inter, o);
	else
	{
		equation->helper++;
		left(i, inter, o);
	}
}

float	vertical_sprite(t_ii *i, float o, t_sprite_info *sprite_info, int x)
{
	t_hv		inter;
	t_equation	equation;

	x = 0;
	equation.helper = 0;
	equation.a = 0.1;
	ver_direction(i, &inter, &equation, o);
	inter.y = i->c->b + (inter.x - i->c->a) * tan(o);
	while (1)
	{
		if ((!((int)((inter.y) / i->tilesize) < i->tab->rows && (int)
		((inter.x - equation.helper) / i->tilesize) < i->tab->columns
		&& ((int)((inter.y) / i->tilesize) >= 0) && ((int)
		((inter.x - equation.helper) / i->tilesize) >= 0))))
			return (0);
		if (i->tab->tab[(int)(inter.y / i->tilesize)][(int)
		((inter.x - equation.helper) / i->tilesize)] == '2')
			ver_help(&inter, i, &equation, sprite_info);
		if (i->tab->tab[(int)(inter.y / i->tilesize)][(int)
		((inter.x - equation.helper) / i->tilesize)] == '1')
			return (1);
		inter.x += inter.xa;
		inter.y += inter.ya;
	}
	return (1);
}
