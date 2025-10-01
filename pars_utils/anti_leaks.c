/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:41:56 by bfaras            #+#    #+#             */
/*   Updated: 2025/09/04 17:59:32 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

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
	void	*add;
	t_save	*new_node;
	t_save	**head;

	if (size == 0)
	{
		head = save_add();
		ie_free(head);
		return (NULL);
	}
	add = malloc(size);
	if (!add)
		return (NULL);
	new_node = malloc(sizeof(t_save));
	if (!new_node)
	{
		free(add);
		return (NULL);
	}
	new_node->add = add;
	new_node->next = *save_add();
	*save_add() = new_node;
	return (add);
}
