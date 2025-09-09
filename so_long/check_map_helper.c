/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:16:51 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/09 12:55:42 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_epc_count(t_game *game)
{
	int	i;
	int	j;
	int	e_count;
	int	p_count;

	i = 0;
	e_count = 0;
	p_count = 0;
	game->collec_nbr = 0;
	while (i < game->height_m)
	{
		j = 0;
		while (j < game->width_m)
		{
			if (game->map[i][j] == 'C')
				game->collec_nbr++;
			else if (game->map[i][j] == 'E')
				e_count++;
			else if (game->map[i][j] == 'P')
				p_count++;
			j++;
		}
		i++;
	}
	ft_epc_check(game, e_count, p_count);
}

void	ft_epc_check(t_game *game, int e_count, int p_count)
{
	if (e_count != 1 || p_count != 1)
	{
		ft_printf("ERROR : Invalid number of Exit or Player\n");
		clean_exit (game);
	}
	if (game->collec_nbr < 1)
	{
		ft_printf("ERROR : Missing Collectible\n");
		clean_exit (game);
	}
}

void	ft_exit_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height_m)
	{
		j = 0;
		while (j < game->width_m)
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
