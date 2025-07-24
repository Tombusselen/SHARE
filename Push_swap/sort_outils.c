/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:55:07 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/24 11:46:45 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max(t_node **head)
{
	int		biggest;
	t_node	*tmp;

	biggest = (*head)->index;
	tmp = (*head)->next;
	while (tmp != NULL)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	return (biggest);
}

int	nbr_bits(int nbr)
{
	int	bits;
	
	bits = 0;
	while (nbr > 0)
	{
		nbr = nbr >> 1;
		bits++;
	}
	return (bits);
}

int	check_sort(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_index(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
