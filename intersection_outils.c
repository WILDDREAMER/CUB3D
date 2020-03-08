/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_outils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:27:17 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/23 17:05:43 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left(t_ii *i, t_hv *v, float o)
{
	v->ya = i->tilesize * tan(o) * -1;
	v->xa = -i->tilesize;
	v->x = floor(i->c->a / i->tilesize) * (i->tilesize);
}

void	right(t_ii *i, t_hv *v, float o)
{
	v->ya = i->tilesize * tan(o);
	v->xa = i->tilesize;
	v->x = floor(i->c->a / i->tilesize) * (i->tilesize) + i->tilesize;
}

void	up(t_ii *i, t_hv *v, float o)
{
	v->xa = i->tilesize / tan(o) * -1;
	v->ya = -i->tilesize;
	v->y = floor(i->c->b / i->tilesize) * (i->tilesize);
}

int		down(t_ii *i, t_hv *v, float o)
{
	v->xa = i->tilesize / tan(o);
	v->ya = i->tilesize;
	v->y = floor(i->c->b / i->tilesize) * (i->tilesize) + i->tilesize;
	return (0);
}
