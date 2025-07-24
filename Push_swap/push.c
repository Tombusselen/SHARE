/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:14:45 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/23 16:31:03 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **head_from, t_node **head_to)
{
	t_node	*tmp;

	if (*head_from == NULL)
		return ;
	tmp = (*head_from)->next;
	(*head_from)->next = *head_to;
	*head_to = *head_from;
	*head_from = tmp;
}

void	push_a(t_node **head_b, t_node **head_a)
{
	ft_push(head_b, head_a);
	write(1, "pa\n", 3);
}

void	push_b(t_node **head_a, t_node **head_b)
{
	ft_push(head_a, head_b);
	write(1, "pb\n", 3);
}
