/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:38:50 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/23 16:05:19 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pars_utils/parsing.h"

int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	free_split(char **ptr, size_t index)
{
	while (index > 0)
		free(ptr[--index]);
	free(ptr);
}

char	**ft_callocc(char **ptr, const char *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	len_word;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		len_word = ft_len(&s[i], c);
		ptr[j] = ft_substr(s, i, len_word);
		if (!ptr[j])
		{
			free_split(ptr, j);
			return (NULL);
		}
		i += len_word;
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	ptr = (char **)ft_malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	if (count == 0)
	{
		ptr[0] = NULL;
		return (ptr);
	}
	if (!ft_callocc(ptr, s, c))
		return (NULL);
	return (ptr);
}
