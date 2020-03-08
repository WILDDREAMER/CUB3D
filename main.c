/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:28:47 by ozakkare          #+#    #+#             */
/*   Updated: 2020/03/03 16:51:07 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	getdata(t_ii *i, t_calcul *calcul)
{
	i->texture->xo = 0;
	i->texture->k = 0;
	if (calcul->sprite)
		i->texture->datad = i->texture->datadsp;
	else if ((i->tex == 1) && (normalise(i->c->or + i->texture->o) > M_PI))
		i->texture->datad = i->texture->datadno;
	else if ((i->tex == 1) && (normalise(i->c->or + i->texture->o) < M_PI))
		i->texture->datad = i->texture->datadso;
	else if (i->tex == -1 && normalise(i->c->or + i->texture->o)
	< (270 * M_PI / 180) && normalise(i->c->or + i->texture->o) > (M_PI / 2))
		i->texture->datad = i->texture->datadwe;
	else
		i->texture->datad = i->texture->datadea;
}

void	inititialcalcul(t_calcul *calcul, t_ii *i)
{
	calcul->x = i->xxx;
	calcul->y = i->yyy;
	calcul->xx = 0;
	calcul->bot = 0;
	calcul->top = 0;
	calcul->tilesize = i->tilesize;
	calcul->sprite = 0;
	calcul->wallheight = 0;
	calcul->distance = 0;
}

void	free_struc(t_ii *i, int n)
{
	free(i->file->s);
	free(i->file->so);
	free(i->file->no);
	free(i->file->ea);
	free(i->file->we);
	if (n != 1)
	{
		while (--i->tab->rows >= 0)
			free(i->tab->tab[i->tab->rows]);
		free(i->tab->tab);
	}
}

int		func(void *param)
{
	t_ii	*i;

	i = (t_ii*)param;
	mlx_destroy_image(i->mlx_ptr, i->img_ptr);
	mlx_clear_window(i->mlx_ptr, i->win_ptr);
	update(i);
	while (--i->tab->rows >= 0)
		free(i->tab->tab[i->tab->rows]);
	free(i->tab->tab);
	readfile(i);
	drawfromfile(i);
	draw_wall(i);
	draw_sprite(i);
	free_struc(i, 1);
	if (i->save)
	{
		if (!strcmp(i->save, "--save"))
			create_bmp(i);
		else if (strcmp(i->save, "--save"))
			error(i, "ERROR : second argument not correct !");
	}
	mlx_put_image_to_window(i->mlx_ptr, i->win_ptr, i->img_ptr, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_ii i;

	argc = 0;
	i.file_name = argv[1];
	if (argv[2])
		i.save = argv[2];
	else
		i.save = NULL;
	i.tab = malloc(sizeof(t_line));
	i.c = malloc(sizeof(t_character));
	i.file = malloc(sizeof(t_file));
	i.texture = malloc(sizeof(t_textures));
	readfile(&i);
	initials(&i);
	mlx_hook(i.win_ptr, 2, 0, deal_key, &i);
	mlx_hook(i.win_ptr, 3, 0, release, &i);
	mlx_hook(i.win_ptr, 17, 0, expose, &i);
	mlx_loop_hook(i.mlx_ptr, func, &i);
	free_struc(&i, 0);
	mlx_loop(i.mlx_ptr);
	return (0);
}
