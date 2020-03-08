/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_intersec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:16:37 by ozakkare          #+#    #+#             */
/*   Updated: 2020/03/03 16:54:42 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_help(t_ii *i, t_equation *eq, t_hv *inter, float o)
{
	if (o >= 270 * M_PI / 180 || o < 90 * M_PI / 180)
		right(i, inter, o);
	else
	{
		eq->helper++;
		left(i, inter, o);
	}
}

float	vertical(t_ii *i, float o)
{
	t_hv		inter;
	t_equation	eq;

	i->hlp_v = 0;
	eq.helper = 0;
	vertical_help(i, &eq, &inter, o);
	inter.y = i->c->b + (inter.x - i->c->a) * tan(o);
	while (1)
	{
		if (!((int)((inter.y) / i->tilesize) < i->tab->rows && (int)
		((inter.x - eq.helper) / i->tilesize) < i->tab->columns
		&& ((int)((inter.y) / i->tilesize) >= 0) && ((int)
		((inter.x - eq.helper) / i->tilesize) >= 0)))
			break ;
		if (ft_strchr("14", i->tab->tab[(int)(inter.y / i->tilesize)]
		[(int)((inter.x - eq.helper) / i->tilesize)]))
		{
			i->vx = inter.x;
			i->vy = inter.y;
			break ;
		}
		inter.x += inter.xa;
		inter.y += inter.ya;
	}
	return (sqrt(pow(i->c->a - inter.x, 2) + pow(i->c->b - inter.y, 2)));
}

void	horizontal_help(t_ii *i, t_equation *eq, t_hv *inter, float o)
{
	if (o >= M_PI)
	{
		up(i, inter, o);
		eq->helper++;
	}
	else
		down(i, inter, o);
}

float	horizontal(t_ii *i, float o)
{
	t_hv		inter;
	t_equation	eq;

	i->hlp_h = 0;
	eq.helper = 0;
	horizontal_help(i, &eq, &inter, o);
	inter.x = i->c->a + ((inter.y - i->c->b) / tan(o));
	while (1)
	{
		if (!((int)((inter.y - eq.helper) / i->tilesize) < i->tab->rows && (int)
		((inter.x) / i->tilesize) < i->tab->columns
		&& ((int)((inter.y - eq.helper) / i->tilesize) >= 0) && ((int)
		((inter.x) / i->tilesize) >= 0)))
			break ;
		if (ft_strchr("14", i->tab->tab[(int)((inter.y - eq.helper)
		/ i->tilesize)][(int)(inter.x / i->tilesize)]))
		{
			i->hx = inter.x;
			i->hy = inter.y;
			break ;
		}
		inter.x += inter.xa;
		inter.y += inter.ya;
	}
	return (sqrt(pow(i->c->a - inter.x, 2) + pow(i->c->b - inter.y, 2)));
}

int		expose(void *param)
{
	t_ii *i;

	i = (t_ii *)param;
	exit(1);
}
