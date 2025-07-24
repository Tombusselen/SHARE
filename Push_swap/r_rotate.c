/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:06:51 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/23 16:27:56 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	prev = NULL;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *head;
	prev->next = NULL;
	*head = tmp;
}

void	r_rotate_a(t_node **head)
{
	ft_r_rotate(head);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_node **head)
{
	ft_r_rotate(head);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_node **head_a, t_node **head_b)
{
	ft_r_rotate(head_a);
	ft_r_rotate(head_b);
	write(1, "rrr\n", 4);
}
