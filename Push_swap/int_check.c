/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:10:07 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/18 11:58:03 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_isdigit(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	arg_double(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = nbr_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_check(int argc, char **argv)
{
	int		i;
	long	tmp_argv;
	char	**tmp_arr;

	i = 0;
	if (argc == 2)
		tmp_arr = ft_split(argv[1], ' ');
	else
		tmp_arr = argv + 1;
	while (tmp_arr[i] != NULL)
	{
		tmp_argv = ft_atoi(tmp_arr[i]);
		if (arg_isdigit(tmp_arr[i]) == 0 || tmp_argv > 2147483647
			|| tmp_argv < -2147483648 || arg_double(tmp_arr) == 0)
		{
			write(2, "Error\n", 6);
			if (argc == 2)
				free_arr(tmp_arr);
			return (1);
		}
		i++;
	}
	if (argc == 2)
		free_arr(tmp_arr);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	arg_check(argc, argv);
	return (0);
}*/
