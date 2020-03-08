/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:20:12 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/28 18:03:48 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_xpm(char *path, t_ii *i)
{
	int		fd;
	char	buf[1];

	fd = open(path, O_RDONLY);
	if (read(fd, buf, 1) == -1)
		error(i, "ERROR : xpm path not exist !");
	close(fd);
}

void	ntexture(t_ii *i, char **line)
{
	if (i->file->no)
		error(i, "ERROR : NO path exist twice !");
	while (**line != '.' && **line)
		line[0]++;
	i->file->no = ft_strdup(*line);
	check_xpm(i->file->no, i);
}

void	stexture(t_ii *i, char **line)
{
	if (line[0][1] == 'O')
	{
		if (i->file->so)
			error(i, "ERROR : SO path exist twice !");
		++line[0];
		++line[0];
		while (**line != '.' && **line == ' ')
			line[0]++;
		i->file->so = ft_strdup(*line);
		check_xpm(i->file->so, i);
	}
	else if (line[0][1] == ' ')
	{
		++line[0];
		++line[0];
		if (i->file->s)
			error(i, "ERROR : SO or S path exist twice !");
		while (**line != '.' && **line == ' ')
			line[0]++;
		i->file->s = ft_strdup(*line);
		check_xpm(i->file->s, i);
	}
}

void	weewtexture(t_ii *i, char **line)
{
	if (**line == 'W' && *++*line == 'E')
	{
		++line[0];
		if (i->file->we)
			error(i, "ERROR : WE path exist twice !");
		while (**line != '.' && **line == ' ')
			line[0]++;
		i->file->we = ft_strdup(*line);
		check_xpm(i->file->we, i);
	}
	else if (**line == 'E' && *++*line == 'A')
	{
		++line[0];
		if (i->file->ea)
			error(i, "ERROR : EA path exist twice !");
		while (**line != '.' && **line == ' ')
		{
			printf("%c", **line);
			if (**line != ' ')
				error(i, "ERROR : missing information !");
			line[0]++;
		}
		i->file->ea = ft_strdup(*line);
		check_xpm(i->file->ea, i);
	}
}

void	loopp(t_dr *d, t_ii *i)
{
	while (d->line[d->j] != '\0' && d->r <= i->tab->rows)
	{
		while (d->line[d->j] == ' ')
			d->j++;
		if (ft_strchr("421", d->line[d->j]))
		{
			i->tab->tab[d->r][d->c] = d->line[d->j];
			d->c++;
			d->j++;
		}
		if (((!d->gnl || !d->first) &&
		!ft_strchr("1 ", d->line[d->j]) && d->line[d->j])
		|| d->line[i->tab->last - 1] != '1' || d->line[0] != '1')
			error(i, "ERROR : map not valid !");
		if (ft_strchr("NSWE0", d->line[d->j]))
		{
			i->tab->tab[d->r][d->c] = d->line[d->j];
			d->c++;
			d->j++;
		}
	}
	d->first = 1;
}
