/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:16:15 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/24 15:22:28 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_node **head)
{
	int	i_max;

	i_max = index_max(head);
	if ((*head)->index == i_max)
		rotate_a(head);
	else if ((*head)->next->index == i_max)
		r_rotate_a(head);
	if ((*head)->index > (*head)->next->index)
		swap_a(head);
}

void	sort_three_b(t_node **head)
{
	int	i_max;

	i_max = index_max(head);
	if ((*head)->index == i_max)
		rotate_b(head);
	else if ((*head)->next->index == i_max)
		r_rotate_b(head);
	if ((*head)->index > (*head)->next->index)
		swap_b(head);
}

void	sort_ten(t_node **stack_a, t_node **stack_b)
{
	int	i_max;
	int	size;

	size = nbr_node(stack_a);
	i_max = size - 1;
	while (nbr_node(stack_a) != (size + 1) / 2)
	{
		if ((*stack_a)->index > i_max / 2)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_a(stack_a, stack_b, size);
	sort_b(stack_a, stack_b, i_max);
	while (*stack_b != NULL)
		push_a(stack_b, stack_a);
	while ((*stack_a)->index != 0)
		rotate_a(stack_a);
}

void	sort_a(t_node **stack_a, t_node **stack_b, int size)
{
	while (nbr_node(stack_a) > 3)
	{
		if ((*stack_a)->index > 2)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_three_a(stack_a);
	while (nbr_node(stack_b) != size / 2)
		push_a(stack_b, stack_a);
	while ((*stack_a)->index != 0)
		rotate_a(stack_a);
}

void	sort_b(t_node **stack_a, t_node **stack_b, int i_max)
{
	while (nbr_node(stack_b) > 3)
	{
		if ((*stack_b)->index >= i_max)
		{
			push_a(stack_b, stack_a);
			i_max--;
		}
		else
			rotate_b(stack_b);
	}
	sort_three_b(stack_b);
	if (nbr_node(stack_b) == 3)
		rotate_b(stack_b);
	swap_b(stack_b);
}
