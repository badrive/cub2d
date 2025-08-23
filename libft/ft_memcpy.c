/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:16:36 by bfaras            #+#    #+#             */
/*   Updated: 2024/11/20 17:49:05 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (dst == src)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
