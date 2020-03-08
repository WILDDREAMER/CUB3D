/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:18:20 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/28 17:32:02 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialfile(t_ii *i)
{
	i->file->width = 0;
	i->file->height = 0;
	i->file->no = NULL;
	i->file->so = NULL;
	i->file->we = NULL;
	i->file->ea = NULL;
	i->file->s = NULL;
	i->file->xposition = 0;
	i->file->yposition = 0;
	i->file->color_f = 0;
	i->file->color_c = 0;
	i->tab->helper = 0;
}

void	read_map_help(t_ii *i, char **line)
{
	if (i->file->direction)
		error(i, "ERROR : player direction exists twice !");
	i->file->direction = **line;
	i->file->xposition = (float)(i->tab->columns) * 256 + 128;
	i->file->yposition = (float)(i->tab->rows) * 256 + 128;
	i->tab->columns++;
}

void	readmap(t_ii *i, char **line)
{
	i->tab->columns = 0;
	i->tab->last = 0;
	while (**line)
	{
		if (ft_strchr("1024", **line))
			i->tab->columns++;
		else if (ft_strchr("NSWE", **line))
			read_map_help(i, line);
		else if (**line != ' ')
			error(i, "ERROR : unknown character in map !");
		else
			i->tab->last++;
		line[0]++;
	}
	if (!i->tab->helper)
		i->tab->helper = i->tab->columns;
	if (i->tab->helper != i->tab->columns)
		error(i, "ERROR : map columns are not equal");
	else
		i->tab->last += i->tab->columns;
	i->tab->rows++;
}

void	distrub(t_ii *i, char **line)
{
	if (**line == 'R')
		res(i, line);
	else if (**line == 'F')
		fcolor(i, line);
	else if (**line == 'C')
		ccolor(i, line);
	else if (line[0][0] == 'N' && line[0][1] == 'O')
		ntexture(i, line);
	else if (**line == 'S')
		stexture(i, line);
	else if ((line[0][0] == 'W' && line[0][1] == 'E') || **line == 'E')
		weewtexture(i, line);
	else if (**line == '1')
	{
		if (!i->file->height || !i->file->width || !i->file->no || !i->file->so
		|| !i->file->we || !i->file->ea || !i->file->s)
			error(i, "ERROR : missing information !");
		readmap(i, line);
	}
	else if (**line != '\n' && **line)
		error(i, "ERROR : textures informations followed by characters !");
}

void	res(t_ii *i, char **line)
{
	int k;
	int help;

	k = -1;
	if (i->file->width)
		error(i, "ERROR : resolution exists twice !");
	line[0]++;
	while (**line == ' ')
		line[0]++;
	if (!ft_isdigit(**line))
		error(i, "ERROR resolution not valid !");
	help = ft_atoi(*line);
	i->file->width = (help > 1600) ? 1600 : help;
	while (++k < s_itoa(help))
		line[0]++;
	help = ft_atoi(*line);
	i->file->height = (help > 900) ? 900 : help;
	k = -2;
	while (++k < s_itoa(help))
		line[0]++;
	while (**line == ' ')
		line[0]++;
	if (i->file->height < 0 || i->file->width < 0 || **line)
		error(i, "ERROR  : resolution not valid !");
}
