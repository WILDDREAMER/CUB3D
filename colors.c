/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:21:08 by ozakkare          #+#    #+#             */
/*   Updated: 2020/03/03 16:45:58 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_color(t_ii *i, t_color color, char **line)
{
	if ((color.r > 255 || color.r < 0) || (color.g > 255 || color.g < 0)
	|| (color.b > 255 || color.b < 0) || **line != 0)
		error(i, "ERROR : color value not valid !");
}

void	fcolor(t_ii *i, char **line)
{
	t_color color;
	int		k;

	k = -1;
	if (i->file->color_f)
		error(i, "ERROR : color exists twice !");
	line[0]++;
	while (**line == ' ')
		line[0]++;
	color.r = ft_atoi(*line);
	k = -1;
	while (++k < s_itoa(color.r))
		line[0]++;
	color.g = comma(i, line, ',');
	k = -1;
	while (++k < s_itoa(color.g))
		line[0]++;
	color.b = comma(i, line, ',');
	k = -1;
	while (++k < s_itoa(color.b))
		line[0]++;
	while (**line == ' ')
		line[0]++;
	check_color(i, color, line);
	i->file->color_f = transform_color(color.r, color.g, color.b);
}

void	ccolor(t_ii *i, char **line)
{
	t_color color;
	int		k;

	if (i->file->color_c)
		error(i, "ERROR : color c exists twice !");
	k = -1;
	line[0]++;
	while (**line == ' ')
		line[0]++;
	color.r = ft_atoi(*line);
	k = -1;
	while (++k < s_itoa(color.r))
		line[0]++;
	color.g = comma(i, line, ',');
	k = -1;
	while (++k < s_itoa(color.g))
		line[0]++;
	color.b = comma(i, line, ',');
	k = -1;
	while (++k < s_itoa(color.b))
		line[0]++;
	while (**line == ' ')
		line[0]++;
	check_color(i, color, line);
	i->file->color_c = transform_color(color.r, color.g, color.b);
}

void	free_struct(t_ii *i)
{
	free(i->texture);
	free(i->c);
	free(i->file);
	free(i->tab);
}

void	error(t_ii *i, char *msg)
{
	t_ii *x;

	x = i;
	write(1, msg, ft_strlen(msg));
	exit(1);
}
