/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:35:47 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/23 16:04:23 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pars_utils/parsing.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = ft_malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
