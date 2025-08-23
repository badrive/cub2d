/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:34:34 by bfaras            #+#    #+#             */
/*   Updated: 2024/11/12 13:52:45 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	uc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
