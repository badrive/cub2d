/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:18:59 by bfaras            #+#    #+#             */
/*   Updated: 2024/11/20 23:40:13 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		one;
	long	result;
	int		nb;
	int		j;

	one = 1;
	result = 0;
	nb = 0;
	j = 0;
	while ((str[j] >= 9 && str[j] <= 13) || (str[j] == 32))
		j++;
	if (str[j] == '-')
		one *= -1;
	if (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j] >= '0' && str[j] <= '9')
	{
		nb = (str[j] - 48);
		result = result * 10 + nb;
		j++;
	}
	return (result * one);
}
