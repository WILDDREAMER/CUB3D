/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:23:35 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/24 17:56:58 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			comma(t_ii *i, char **line, char c)
{
	if (**line == c)
		line[0]++;
	else
		error(i, "ERROR : color value not valid !");
	return (ft_atoi(*line));
}

void		everything(t_ii *i)
{
	if (!i->file->height || !i->file->width || !i->file->no || !i->file->so
	|| !i->file->we || !i->file->ea || !i->file->s || !i->file->xposition ||
	!i->file->yposition || !i->file->direction)
		error(i, "ERROR : missing information !");
}

int			readfile(t_ii *i)
{
	char	*line;
	int		fd;
	char	*ptr;

	fd = open(i->file_name, O_RDONLY);
	i->tab->rows = 0;
	i->file->direction = '\0';
	initialfile(i);
	while (get_next_line(fd, &line) == 1)
	{
		ptr = line;
		distrub(i, &line);
		free(ptr);
	}
	ptr = line;
	distrub(i, &line);
	free(ptr);
	everything(i);
	close(fd);
	return (1);
}

void		initialdr(t_dr *d, int l)
{
	d->j = 0;
	d->x = 0;
	d->c = 0;
	if (l)
	{
		d->r = 0;
		d->y = 0;
		d->first = 0;
	}
}

int			drawfromfile(t_ii *i)
{
	t_dr d;

	initialdr(&d, 1);
	d.fd = open(i->file_name, O_RDONLY);
	i->tab->tab = (char**)malloc((i->tab->rows) * sizeof(char*));
	while ((d.gnl = get_next_line(d.fd, &d.line)) == 1)
	{
		if (*d.line == '1' || *d.line == '4')
		{
			initialdr(&d, 0);
			i->tab->tab[d.r] = malloc(i->tab->columns * sizeof(char));
			loopp(&d, i);
			i->tab->tab[d.r][d.c] = '\0';
			d.r++;
		}
		free(d.line);
	}
	if (*d.line == '1')
		lastline(&d, i);
	else
		error(i, "ERROR : map not set at the end of file !");
	free(d.line);
	close(d.fd);
	return (1);
}
