/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:10:33 by bfaras            #+#    #+#             */
/*   Updated: 2024/11/20 11:17:27 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
