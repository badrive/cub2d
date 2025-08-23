/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:13:06 by bfaras            #+#    #+#             */
/*   Updated: 2024/11/12 09:17:40 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	i = ft_strlen(s);
	uc = (unsigned char)c;
	if (uc == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if ((unsigned char)s[i - 1] == uc)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (NULL);
}
