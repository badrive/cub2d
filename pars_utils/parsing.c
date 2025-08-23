/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/23 14:16:42 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		return (write(2, "ERROR\n", 6), 0);
	return (1);
}
