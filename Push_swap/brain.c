/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:45:39 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/24 15:44:50 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	//if (argc < 2)
	//	exit (0);
	if (arg_check(argc, argv) != 0)
		exit (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	stack_a = ft_list(argv);
	stack_b = NULL;
	if (argc == 2)
		free_arr(argv);
	sort_index(&stack_a, nbr_arg(argv));
	if (check_sort(&stack_a) == 0)
	{
		free_list(stack_a);
		free_list(stack_b);
		exit (0);
	}
	/*if (nbr_node(&stack_a) < 4)
		sort_three_a(&stack_a);
	if (nbr_node(&stack_a) > 3 && nbr_node(&stack_a) < 11)
		sort_ten(&stack_a, &stack_b);
	if (nbr_node(&stack_a) >= 11)
		radix_sort(&stack_a, &stack_b);*/
	/*print_index("stack_a", stack_a);
	if (check_sort(&stack_a) == 0)
		ft_printf("value sorted\n");
	if (check_sort_index(&stack_a) == 0)
		ft_printf("index sorted\n");*/
	free_list(stack_a);
	free_list(stack_b);
}
