/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:26:24 by ozakkare          #+#    #+#             */
/*   Updated: 2020/02/28 18:42:47 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				whitespace(char c)
{
	if (ft_strchr("\n\v\f\t\r ", c))
		return (1);
	return (0);
}

long long		ft_atoiu(char *str)
{
	int				i;
	int				negativity;
	long long		result;

	result = 0;
	negativity = 1;
	i = 0;
	if (str == NULL)
		return (0);
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-')
		negativity = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > 4294967295 && negativity == 1)
		return (-1);
	if (result > 4294967295 && negativity == -1)
		return (0);
	return (result * negativity);
}

int				ft_atoi(char *str)
{
	int				i;
	int				negativity;
	unsigned long	result;

	result = 0;
	negativity = 1;
	i = 0;
	if (str == NULL)
		return (0);
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-')
		negativity = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > 2147483647 && negativity == 1)
		return (-1);
	if (result > 2147483648 && negativity == -1)
		return (0);
	return (result * negativity);
}
