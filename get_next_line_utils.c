/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:43:41 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/24 22:26:00 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = s;
	i = 0;
	while (i < n)
		a[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*c;

	if (!(c = malloc(count * size)))
		return (0);
	ft_bzero(c, count * size);
	return (c);
}

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int		release_help(int key, t_ii *i)
{
	if (key == 12 || key == 6)
		i->look_press = 0;
	if (key == 53)
		exit(1);
	return (1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*a;
	unsigned const char *b;

	a = dst;
	b = src;
	if (a == 0 && b == 0)
		return (0);
	while (n--)
		*a++ = *b++;
	return (dst);
}
