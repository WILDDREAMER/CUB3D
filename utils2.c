/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 09:18:13 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/23 09:33:18 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalise(float o)
{
	if (o < 0)
		o += 2 * M_PI;
	o = fmod(o, 360 * M_PI / 180);
	return (o);
}

float	direction(t_ii *i)
{
	if (i->file->direction == 'N')
		return (270 * M_PI / 180);
	if (i->file->direction == 'S')
		return (90 * M_PI / 180);
	if (i->file->direction == 'W')
		return (M_PI);
	return (2 * M_PI);
}

void	initials3(t_ii *i)
{
	i->texture->mxpmsp = mlx_xpm_file_to_image(i->mlx_ptr, i->file->s,
	&i->texture->x, &i->texture->yy);
	i->texture->datadsp = (int *)mlx_get_data_addr(i->texture->mxpmsp,
	&i->texture->aa, &i->texture->ss, &i->texture->bb);
	i->texture->datadno = (int *)mlx_get_data_addr(i->texture->mxpmno,
	&i->texture->aa, &i->texture->ss, &i->texture->bb);
	i->texture->datadso = (int *)mlx_get_data_addr(i->texture->mxpmso,
	&i->texture->aa, &i->texture->ss, &i->texture->bb);
	i->texture->datadwe = (int *)mlx_get_data_addr(i->texture->mxpmwe,
	&i->texture->aa, &i->texture->ss, &i->texture->bb);
	i->texture->datadea = (int *)mlx_get_data_addr(i->texture->mxpmea,
	&i->texture->aa, &i->texture->ss, &i->texture->bb);
}

void	initials2(t_ii *i)
{
	i->tab->rows = 0;
	i->tab->tab = NULL;
	i->mlx_ptr = mlx_init();
	i->win_ptr = mlx_new_window(i->mlx_ptr, i->file->width,
	i->file->height, "CUB3D");
	i->img_ptr = mlx_new_image(i->mlx_ptr, i->file->width,
	i->file->height);
	i->data = (int *)mlx_get_data_addr(i->img_ptr, &i->bpp, &i->size_l,
	&i->endian);
	i->texture->mxpmno = mlx_xpm_file_to_image(i->mlx_ptr, i->file->no,
	&i->texture->x, &i->texture->yy);
	i->texture->mxpmso = mlx_xpm_file_to_image(i->mlx_ptr, i->file->so,
	&i->texture->x, &i->texture->yy);
	i->texture->mxpmwe = mlx_xpm_file_to_image(i->mlx_ptr, i->file->we,
	&i->texture->x, &i->texture->yy);
	i->texture->mxpmea = mlx_xpm_file_to_image(i->mlx_ptr, i->file->ea,
	&i->texture->x, &i->texture->yy);
	initials3(i);
	i->tilesize = 256;
	i->sprite = 0;
}

int		transform_color(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}
