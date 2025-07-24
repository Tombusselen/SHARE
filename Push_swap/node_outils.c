/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:07:35 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/23 16:22:50 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_arg(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int	nbr_node(t_node **head)
{
	int		i;
	t_node	*tmp;

	if (head == NULL || *head == NULL)
		return (0);
	else if ((*head)->next == NULL)
		return (1);
	i = 2;
	tmp = (*head)->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	print_list(t_node *head)
{
	while (head != NULL)
	{
		ft_printf("%d\n", head->value);
		head = head->next;
	}
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_arr(char **arr)
{
	int	i;
	int	len;

	i = 0;
	len = nbr_arg(arr);
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
