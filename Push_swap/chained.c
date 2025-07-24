/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:58:43 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/21 14:50:27 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	add_node(t_node **head, t_node *new_node)
{
	t_node	*current;

	if (!head || !new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

t_node	*ft_list(char **argv)
{
	t_node	*stack;
	t_node	*new;
	int		i;

	stack = NULL;
	i = 0;
	while (argv[i])
	{
		new = create_node(ft_atoi(argv[i]));
		if (!new)
		{
			free_list(stack);
			return (NULL);
		}
		add_node(&stack, new);
		i++;
	}
	return (stack);
}
