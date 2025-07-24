/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:43:25 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/24 11:49:56 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_index(char *stack_name, t_node *stack)
{
	ft_printf("%s:\n", stack_name);
	while (stack != NULL)
	{
		ft_printf("value = %d | index = %d\n", stack->value, stack->index);
		stack = stack->next;
	}
}

void	print_stack_ab(t_node *stack_a, t_node *stack_b)
{
	ft_printf("A\n");
	print_list(stack_a);
	ft_printf("B\n");
	print_list(stack_b);
}
