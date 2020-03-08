/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:59:44 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/24 15:20:18 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	help_check_hor(t_ii *i, t_equation *eq, t_hv *inter, float o)
{
	if (o >= M_PI)
	{
		up(i, inter, o);
		eq->helper++;
	}
	else
		down(i, inter, o);
}

float	check_hor(t_ii *i, float o)
{
	t_hv		inter;
	t_equation	eq;

	i->hlp_h = 0;
	eq.helper = 0;
	help_check_hor(i, &eq, &inter, o);
	inter.x = i->c->a + ((inter.y - i->c->b) / tan(o));
	while (1)
	{
		if ((!((int)((inter.y - eq.helper) / i->tilesize)
		< i->tab->rows && (int)((inter.x) / i->tilesize) < i->tab->columns
		&& ((int)((inter.y - eq.helper) / i->tilesize) >= 0)
		&& ((int)((inter.x) / i->tilesize) >= 0))))
			return (i->hlp_h);
		if (i->tab->tab[(int)((inter.y - eq.helper) / i->tilesize)]
		[(int)(inter.x / i->tilesize)] == '2')
			i->hlp_h++;
		if (i->tab->tab[(int)((inter.y - eq.helper) / i->tilesize)]
		[(int)(inter.x / i->tilesize)] == '1')
			break ;
		inter.x += inter.xa;
		inter.y += inter.ya;
	}
	return (i->hlp_h);
}

void	help_check_ver(t_ii *i, t_hv *inter, t_equation *eq, float o)
{
	if (o >= 270 * M_PI / 180 || o < 90 * M_PI / 180)
		right(i, inter, o);
	else
	{
		eq->helper++;
		left(i, inter, o);
	}
}

float	check_ver(t_ii *i, float o)
{
	t_hv		inter;
	t_equation	eq;

	eq.helper = 0;
	i->hlp_v = 0;
	help_check_ver(i, &inter, &eq, o);
	inter.y = i->c->b + (inter.x - i->c->a) * tan(o);
	while (1)
	{
		if ((!((int)((inter.y) / i->tilesize) < i->tab->rows &&
		(int)((inter.x - eq.helper) / i->tilesize) < i->tab->columns
		&& ((int)((inter.y) / i->tilesize) >= 0) &&
		((int)((inter.x - eq.helper) / i->tilesize) >= 0))))
			return (i->hlp_v);
		if (i->tab->tab[(int)(inter.y / i->tilesize)]
		[(int)((inter.x - eq.helper) / i->tilesize)] == '2')
			i->hlp_v++;
		if (i->tab->tab[(int)(inter.y / i->tilesize)]
		[(int)((inter.x - eq.helper) / i->tilesize)] == '1')
			break ;
		inter.x += inter.xa;
		inter.y += inter.ya;
	}
	return (i->hlp_v);
}

void	lastline(t_dr *d, t_ii *i)
{
	d->j = 0;
	d->x = 0;
	d->c = 0;
	i->tab->tab[d->r] = (char *)malloc(i->tab->columns * sizeof(char));
	loopp(d, i);
	i->tab->tab[d->r][d->c] = '\0';
	d->r++;
}
