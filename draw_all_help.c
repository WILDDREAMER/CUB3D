/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 09:34:37 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/24 22:10:32 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	len(t_ii *i, float o)
{
	float v;
	float h;

	v = vertical(i, o);
	h = horizontal(i, o);
	if (v > h)
	{
		i->tex = 1;
		i->xxx = i->hx;
		i->yyy = i->hy;
		return (h);
	}
	i->xxx = i->vx;
	i->yyy = i->vy;
	i->tex = -1;
	return (v);
}

void	crouch_look(t_ii *i, t_calcul *calcul)
{
	if (i->crouch)
	{
		calcul->bot -= i->crouch;
		calcul->top -= i->crouch;
	}
	if (i->look && calcul->top > 100 && calcul->bot < i->file->height - 100)
	{
		calcul->bot += 10 * i->look;
		calcul->top += 10 * i->look;
	}
	if (i->look_press == 0)
		i->look = 0;
}

void	d_w_help(t_ii *i, t_calcul *calcul)
{
	calcul->tilesize = i->tilesize;
	calcul->distance = len(i, normalise(i->c->or + i->texture->o))
	* cos(normalise(i->c->or + i->texture->o) - normalise(i->c->op));
	calcul->x = i->xxx;
	calcul->y = i->yyy;
	calcul->wallheight = ((i->tilesize / calcul->distance) *
	(((i->file->width) * tan(30 * M_PI / 180))));
	calcul->bot = (i->file->height / 2) + (calcul->wallheight / 2);
	calcul->top = (i->file->height / 2) - (calcul->wallheight / 2);
	crouch_look(i, calcul);
	i->texture->fac = calcul->tilesize / calcul->wallheight;
	getdata(i, calcul);
}

void	draw_wall(t_ii *i)
{
	t_calcul calcul;

	inititialcalcul(&calcul, i);
	i->texture->o = 0;
	calcul.xx = 0;
	while (calcul.xx < i->file->width)
	{
		d_w_help(i, &calcul);
		i->texture->k = 0;
		while (i->texture->k < calcul.top)
			drawcc(i, &calcul);
		i->texture->xo = (i->tex == 1) ? (int)calcul.x % i->tilesize :
		(int)calcul.y % i->tilesize;
		i->texture->yo = 0;
		while (calcul.top < calcul.bot)
			drawwall(i, &calcul);
		while (calcul.bot < i->file->height)
			drawwfloor(i, &calcul);
		i->texture->o += ((60 * (M_PI / 180)) / i->file->width);
		calcul.xx++;
	}
}

void	d_s_help(t_ii *i, t_calcul *calcul, t_sprite_info sprite_info)
{
	calcul->distance = sprite_info.center_distance;
	calcul->x = sprite_info.x;
	calcul->y = sprite_info.y;
	calcul->wallheight = ((i->tilesize / calcul->distance) *
	(((i->file->width) * tan(30 * M_PI / 180))));
	calcul->bot = (i->file->height / 2) + (calcul->wallheight / 2);
	calcul->top = (i->file->height / 2) - (calcul->wallheight / 2);
	crouch_look(i, calcul);
	i->texture->fac = calcul->tilesize / calcul->wallheight;
	getdata(i, calcul);
	calcul->sprite = 1;
}
