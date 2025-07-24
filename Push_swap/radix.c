/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:50:57 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/24 15:44:37 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	max_ind;
	int	max_bits;
	int	i;
	int	j;

	max_ind = index_max(stack_a);
	max_bits = nbr_bits(max_ind);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_ind)
		{
			if (((*stack_a)->index >> i) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b != NULL)
			push_a(stack_b, stack_a);
		i++;
	}
}

void	sorting_tree(t_node **stack_a, t_node **stack_b)
{
	if (nbr_node(stack_a) < 4)
		sort_three_a(stack_a);
	if (nbr_node(stack_a) > 3 && nbr_node(stack_a) < 11)
		sort_ten(stack_a, stack_b);
	if (nbr_node(stack_a) >= 11)
		radix_sort(stack_a, stack_b);
}
