/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 09:17:54 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/28 18:33:21 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initials(t_ii *i)
{
	i->c->len = 100;
	i->c->a = i->file->xposition + 70;
	i->c->b = i->file->yposition + 20;
	i->c->r = 5;
	i->c->rx = i->c->a + 500;
	i->c->ry = i->c->b + 500;
	i->c->op = direction(i);
	i->c->or = normalise(i->c->op - (30 * M_PI / 180));
	i->vup = 0;
	i->vdown = 0;
	i->tab->columns = 0;
	i->down = 0;
	i->up = 0;
	i->left = 0;
	i->right = 0;
	i->walk_right = 0;
	i->walk_left = 0;
	i->look = 0;
	i->crouch = 0;
	initials2(i);
}

void	update_help(t_ii *i)
{
	if (i->look_press == -1 && i->look > -(i->file->height / 100 * 4))
		i->look--;
	if (i->left)
	{
		i->c->op = normalise(i->c->op - (2 * M_PI / 180));
		i->c->or = normalise(i->c->or - (2 * M_PI / 180));
	}
	if (i->walk_right)
		if (ft_strchr("NSWE04", i->tab->tab[(int)(i->c->b + 70 *
		sin(i->c->op + (90 * M_PI / 180))) / i->tilesize][(int)(i->c->a + 70 *
		cos(i->c->op + (90 * M_PI / 180))) / i->tilesize]))
		{
			i->c->a += 30 * cos(i->c->op + (90 * M_PI / 180));
			i->c->b += 30 * sin(i->c->op + (90 * M_PI / 180));
		}
	if (i->walk_left)
		if (ft_strchr("NSWE04", i->tab->tab[(int)(i->c->b - (70 *
		sin(i->c->op + (90 * M_PI / 180)))) / i->tilesize][(int)(i->c->a - (70 *
		cos(i->c->op + (90 * M_PI / 180)))) / i->tilesize]))
		{
			i->c->a -= 30 * cos(i->c->op + (90 * M_PI / 180));
			i->c->b -= 30 * sin(i->c->op + (90 * M_PI / 180));
		}
	if (i->look_press == 1 && i->look < i->file->height / 100 * 4)
		i->look++;
}

void	update(t_ii *i)
{
	i->img_ptr = mlx_new_image(i->mlx_ptr, i->file->width, i->file->height);
	i->data = (int *)mlx_get_data_addr(i->img_ptr,
	&i->bpp, &i->size_l, &i->endian);
	if (i->down)
		if (ft_strchr("NSWE04", i->tab->tab[(int)((i->c->b) - (200 *
		sin(i->c->op))) / i->tilesize][(int)((i->c->a) - (200
		* cos(i->c->op))) / i->tilesize]))
		{
			i->c->a -= (35 * cos(i->c->op));
			i->c->b -= (35 * sin(i->c->op));
		}
	if (i->up)
		if (ft_strchr("NSWE04", i->tab->tab[(int)((i->c->b) + (200 *
		sin(i->c->op))) / i->tilesize][(int)((i->c->a) + (200 *
		cos(i->c->op))) / i->tilesize]))
		{
			i->c->a += 35 * cos(i->c->op);
			i->c->b += 35 * sin(i->c->op);
		}
	if (i->right)
	{
		i->c->op = normalise(i->c->op + (2 * M_PI / 180));
		i->c->or = normalise(i->c->or + (2 * M_PI / 180));
	}
	update_help(i);
}

int		deal_key(int key, void *param)
{
	t_ii *i;

	i = (t_ii *)param;
	if (key == 1)
		i->down = 1;
	if (key == 13)
		i->up = 1;
	if (key == 2)
		i->right = 1;
	if (key == 0)
		i->left = 1;
	if (key == 124)
		i->walk_right = 1;
	if (key == 123)
		i->walk_left = 1;
	if (key == 12)
		i->look_press = 1;
	if (key == 6)
		i->look_press = -1;
	if (key == 49)
		i->crouch = 100;
	if (key == 53)
		exit(1);
	return (1);
}

int		release(int key, void *param)
{
	t_ii *i;

	i = (t_ii *)param;
	if (key == 1)
		i->down = 0;
	if (key == 13)
		i->up = 0;
	if (key == 2)
		i->right = 0;
	if (key == 0)
		i->left = 0;
	if (key == 124)
		i->walk_right = 0;
	if (key == 123)
		i->walk_left = 0;
	if (key == 12)
		i->look_press = 0;
	if (key == 6)
		i->look_press = 0;
	if (key == 49)
		i->crouch = 0;
	release_help(key, i);
	return (1);
}
