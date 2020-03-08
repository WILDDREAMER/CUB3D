/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:07:45 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/24 21:42:56 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_to_rgb(int color, int *r, int *g, int *b)
{
	*b = color % 256;
	*r = (color - *b) / (256 * 256);
	*g = (color - ((*r * 256 * 256) + *b)) / 256;
}

int		shadow(int color, t_calcul *calcul)
{
	int b;
	int g;
	int r;

	b = color % 256;
	r = (color - b) / (256 * 256);
	g = (color - ((r * 256 * 256) + b)) / 256;
	if ((calcul->distance / 680) > 1)
	{
		b /= (calcul->distance / 680);
		r /= (calcul->distance / 680);
		g /= (calcul->distance / 680);
	}
	return (transform_color(r, g, b));
}

void	drawwall(t_ii *i, t_calcul *calcul)
{
	int px;

	px = ((int)(i->texture->yo * i->texture->fac) *
	calcul->tilesize + i->texture->xo);
	if (px < 0)
		px = 0;
	i->texture->color = shadow(i->texture->datad[px], calcul);
	if (calcul->top >= 0 && calcul->top < i->file->height)
	{
		if (i->texture->color)
			i->data[((int)calcul->top) * i->file->width +
			calcul->xx] = i->texture->color;
	}
	calcul->top++;
	i->texture->yo++;
}

void	drawwfloor(t_ii *i, t_calcul *calcul)
{
	i->data[((int)calcul->bot) * i->file->width +
	calcul->xx] = i->file->color_f;
	calcul->bot++;
}

void	drawcc(t_ii *i, t_calcul *calcul)
{
	i->data[((int)i->texture->k) * i->file->width +
	calcul->xx] = i->file->color_c;
	i->texture->k++;
}
