/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:25:18 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/24 22:23:09 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_color(t_ii *i, int column, int row)
{
	int	x;
	int	size_line;
	int	color;
	int *img;

	img = (int*)mlx_get_data_addr(i->img_ptr, &x, &size_line, &x);
	color = img[row * (size_line / 4) + column];
	return (color);
}

void		set_bmp_header(unsigned char *buff, t_bitmap *bmp, t_ii *i)
{
	bmp->pd_offset = 54;
	bmp->header_size = 40;
	bmp->image_width = i->file->width;
	bmp->image_height = i->file->height;
	bmp->bpp = 24;
	bmp->width_in_bytes = ((bmp->image_width * bmp->bpp + 31) / 32) * 4;
	bmp->planes = 1;
	bmp->image_size = bmp->width_in_bytes * bmp->image_height;
	bmp->file_size = 54 + bmp->image_size;
	ft_memcpy(buff, "BM", 2);
	ft_memcpy(buff + 2, &(bmp->file_size), 4);
	ft_memcpy(buff + 10, &(bmp->pd_offset), 4);
	ft_memcpy(buff + 14, &(bmp->header_size), 4);
	ft_memcpy(buff + 18, &(bmp->image_width), 4);
	ft_memcpy(buff + 22, &(bmp->image_height), 4);
	ft_memcpy(buff + 26, &(bmp->planes), 2);
	ft_memcpy(buff + 28, &(bmp->bpp), 2);
	ft_memcpy(buff + 34, &(bmp->image_size), 4);
}

void		put_color_buff(unsigned char *buffer, t_bitmap *bmp, t_ii *i)
{
	int		row;
	int		col;
	int		y2;
	int		tab_color[3];
	int		color;

	row = i->file->height;
	y2 = 0;
	while (--row >= 0)
	{
		col = i->file->width;
		while (--col >= 0)
		{
			color = get_color(i, col, row);
			color_to_rgb(color, tab_color, tab_color + 1, tab_color + 2);
			buffer[y2 * bmp->width_in_bytes + col * 3] = tab_color[2];
			buffer[y2 * bmp->width_in_bytes + col * 3 + 1] = tab_color[1];
			buffer[y2 * bmp->width_in_bytes + col * 3 + 2] = tab_color[0];
		}
		y2++;
	}
}

void		init_header(unsigned char *header)
{
	int		i;

	i = 55;
	while (--i >= 0)
		header[i] = 0;
}

int			create_bmp(t_ii *i)
{
	t_bitmap		bmp;
	int				fd;
	unsigned char	header[54];
	unsigned char	*buffer;

	init_header(header);
	buffer = ft_calloc(bmp.image_size, sizeof(unsigned char));
	fd = open("img.bmp", O_RDWR | O_CREAT, 777);
	set_bmp_header(header, &bmp, i);
	write(fd, header, 54);
	put_color_buff(buffer, &bmp, i);
	write(fd, buffer, bmp.image_size);
	close(fd);
	free(buffer);
	exit(1);
	return (1);
}
