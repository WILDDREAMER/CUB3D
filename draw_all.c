/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 09:36:15 by ozakkare          #+#    #+#             */
/*   Updated: 2020/03/03 16:50:48 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_elemnts(t_sprite_info *sprite_info, int n_sprites, int k, int j)
{
	t_sprite_info holder;

	n_sprites = 0;
	holder = sprite_info[j];
	sprite_info[j] = sprite_info[k];
	sprite_info[k] = holder;
}

void	sort(t_sprite_info *sprite_info, int n_sprites)
{
	int j;
	int k;

	j = -1;
	while (++j < n_sprites)
	{
		k = j;
		while (++k < n_sprites)
			if (sprite_info[j].center_distance >
			sprite_info[k].center_distance)
				swap_elemnts(sprite_info, n_sprites, k, j);
	}
}

void	render_sprite(t_ii *i, t_calcul calcul,
t_sprite_info *sprite_info, int n_sprites)
{
	if (len(i, normalise(i->c->or + i->texture->o))
	> sprite_info[n_sprites].center_distance)
	{
		calcul.sprite = 1;
		d_s_help(i, &calcul, sprite_info[n_sprites]);
		while (i->texture->k < calcul.top)
			drawcc(i, &calcul);
		i->texture->xo = sprite_info[n_sprites].x_off;
		i->texture->yo = 0;
		while (calcul.top < calcul.bot)
			drawwall(i, &calcul);
		while (calcul.bot < i->file->height)
			drawwfloor(i, &calcul);
	}
}

int		nu_sprites(t_ii *i, t_calcul *calcul)
{
	int n;

	i->ind = 0;
	calcul->sprite = 0;
	n = check_ver(i, normalise(i->c->or + i->texture->o))
	+ check_hor(i, normalise(i->c->or + i->texture->o));
	return (n);
}

void	draw_sprite(t_ii *i)
{
	t_calcul		calcul;
	int				n_sprites;
	t_sprite_info	*sprite_info;

	inititialcalcul(&calcul, i);
	i->texture->o = 0;
	calcul.xx = 0;
	while (calcul.xx < i->file->width)
	{
		n_sprites = nu_sprites(i, &calcul);
		sprite_info = malloc(n_sprites * sizeof(t_sprite_info));
		horizontal_sprite(i, normalise(i->c->or + i->texture->o),
		sprite_info, calcul.xx);
		vertical_sprite(i, normalise(i->c->or + i->texture->o),
		sprite_info, calcul.xx);
		i->texture->k = 0;
		sort(sprite_info, n_sprites);
		while (--n_sprites >= 0)
			render_sprite(i, calcul, sprite_info, n_sprites);
		i->texture->o += ((60 * (M_PI / 180)) / i->file->width);
		calcul.xx++;
		free(sprite_info);
	}
}
