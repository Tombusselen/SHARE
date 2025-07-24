/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:30:08 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/24 11:51:35 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

// outils test
void	print_index(char *stack_name, t_node *stack);
void	print_stack_ab(t_node *stack_a, t_node *stack_b);
// outils node
int		nbr_arg(char **arr);
int		nbr_node(t_node **head);
void	free_arr(char **arr);
void	free_list(t_node *head);
void	print_list(t_node *head);
// outils sort
int		index_max(t_node **head);
int		nbr_bits(int nbr);
int		check_sort(t_node **head);
int		check_sort_index(t_node **head);
// verification input
int		arg_isdigit(char *argv);
int		arg_double(char **argv);
int		arg_check(int argc, char **argv);
// creation de liste chainee
t_node	*create_node(int value);
void	add_node(t_node **head, t_node *new_node);
t_node	*ft_list(char **argv);
// operation
void	swap_a(t_node **head);
void	swap_b(t_node **head);
void	swap_ab(t_node **head_a, t_node **head_b);
void	rotate_a(t_node **head);
void	rotate_b(t_node **head);
void	rotate_ab(t_node **head_a, t_node **head_b);
void	r_rotate_a(t_node **head);
void	r_rotate_b(t_node **head);
void	r_rotate_ab(t_node **head_a, t_node **head_b);
void	push_a(t_node **head_a, t_node **head_b);
void	push_b(t_node **head_b, t_node **head_a);
// index
void	sort_index(t_node **head, int stack_size);
// small tri
void	sort_three(t_node **head);
void	sort_ten(t_node **stack_a, t_node **stack_b);
void	sort_a(t_node **stack_a, t_node **stack_b, int size);
void	sort_b(t_node **stack_a, t_node **stack_b, int i_max);
// radix
void	radix_sort(t_node **stack_a, t_node **stack_b);
#endif
