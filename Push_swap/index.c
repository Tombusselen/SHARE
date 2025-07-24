/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:01:15 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/23 16:30:11 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_node **head, int stack_size)
{
	t_node	*tmp;
	t_node	*biggest;

	tmp = *head;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	while (stack_size > 0)
	{
		biggest = NULL;
		tmp = *head;
		while (tmp != NULL)
		{
			if (tmp->index == -1
				&& (biggest == NULL || tmp->value > biggest->value))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest != NULL)
			biggest->index = stack_size - 1;
		stack_size--;
	}
}
