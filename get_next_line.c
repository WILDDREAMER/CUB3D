/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:49:48 by ozakkare          #+#    #+#             */
/*   Updated: 2020/03/03 16:47:39 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"
#define BUFFER_SIZE 1000

char		*filll(char *holder, char **line)
{
	char *str;

	str = NULL;
	if (holder)
	{
		if ((str = ft_strchr(holder, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(holder);
			ft_strcpy(holder, ++str);
		}
		else
		{
			*line = ft_strdup(holder);
			holder = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (str);
}

void		swap(char *buff, char **line)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, buff);
	free(tmp);
}

int			ifempty(char **holder, char *buff, int fd, char **line)
{
	int			size_read;
	char		*str;

	str = filll(*holder, line);
	while (!str)
	{
		if ((size_read = read(fd, buff, BUFFER_SIZE)) == 0)
		{
			free(buff);
			free(*holder);
			return (((*holder = 0) == 0) ? 0 : 0);
		}
		*(buff + size_read) = '\0';
		if ((str = ft_strchr(buff, '\n')))
		{
			*str++ = '\0';
			free(*holder);
			*holder = ft_strdup(str);
		}
		swap(buff, line);
	}
	free(buff);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char *holder;
	char		*buff;
	t_ii		*i;

	i = NULL;
	if ((read(fd, NULL, 0) != 0) || fd < 0)
		error(i, "ERROR : file.cub not valid !");
	if (BUFFER_SIZE >= 2147483647)
		return (-1);
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	return (ifempty(&holder, buff, fd, line));
}
