/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:06:51 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/23 16:21:57 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*first;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	first = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	*head = first->next;
	first->next = NULL;
	tmp->next = first;
}

void	rotate_a(t_node **head)
{
	ft_rotate(head);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **head)
{
	ft_rotate(head);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_node **head_a, t_node **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	write(1, "rr\n", 3);
}
