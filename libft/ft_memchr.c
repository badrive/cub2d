/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:16:43 by bfaras            #+#    #+#             */
/*   Updated: 2024/11/11 10:52:17 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	target;
	size_t			i;

	str = (unsigned char *)s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == target)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
