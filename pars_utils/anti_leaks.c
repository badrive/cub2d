/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:41:56 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/23 14:44:12 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_save	**save_add(void)
{
	static t_save	*save;

	if (save == NULL)
	{
		save = malloc(sizeof(t_save));
		if (!save)
			return (NULL);
		save->add = NULL;
		save->next = NULL;
	}
	return (&save);
}

void	ie_free(t_save **head)
{
	t_save	*temp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		if (temp->add)
		{
			free(temp->add);
			temp->add = NULL;
		}
		free(temp);
		temp = NULL;
	}
}

void	*ft_malloc(size_t size)
{
	void			*add;
	static t_save	*head;

	if (size == 0)
	{
		ie_free(&head);
		return (NULL);
	}
	add = malloc(size);
	if (!add)
		return (0);
	head = malloc(sizeof(t_save));
	if (!head)
		return (0);
	head->add = add;
	head->next = *save_add();
	*save_add() = head;
	return (add);
}
