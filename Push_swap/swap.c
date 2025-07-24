/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:45:58 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/23 15:18:43 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **head)
{
	t_node	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	swap_a(t_node **head)
{
	ft_swap(head);
	write(1, "sa\n", 3);
}

void	swap_b(t_node **head)
{
	ft_swap(head);
	write(1, "sb\n", 3);
}

void	swap_ab(t_node **head_a, t_node **head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
	write(1, "ss\n", 3);
}
