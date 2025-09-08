/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:40:49 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 16:16:08 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rectangular(t_game *game)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(game->map[0]);
	ft_printf("len = %d \n", len);
	ft_printf("height_m = %d \n", game->height_m); 
	while (i < game->height_m)
	{
		if (len != ft_strlen(game->map[i]))
		{
			ft_printf("ERROR : Non rectangular map \n");
			ft_printf("len[i] = %d et i = %d \n", ft_strlen(game->map[i]), i); 
			exit (0);
		}
		i++;
	}
}

void	ft_surrounded(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->width_m)
	{
		if (game->map[0][i] != '1' || game->map[game->height_m - 1][i] != '1')
		{
			ft_printf("ERROR : Map is not surrounded \n");
			clean_exit (game);
		}
		i++;
	}
	while (j < game->height_m)
	{
		if (game->map[j][0] != '1' || game->map[j][game->width_m - 1] != '1')
		{
			ft_printf("ERROR : Map is not surrounded \n");
			clean_exit (game);
		}
		j++;
	}
}

void	ft_correct_fill(t_game *game)
{
	int		i;
	int		j;
	char	type;

	i = 0;
	while (i < game->height_m)
	{
		j = 0;
		while (j < game->width_m)
		{
			type = game->map[i][j];
			if (type != 'P' && type != 'C' && type != 'E' && type != '1'
				&& type != '0')
			{
				ft_printf("ERROR : Uncorrect map fill at map[%d][%d] \n", i, j);
				clean_exit (game);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	ft_rectangular(game);
	ft_surrounded(game);
	ft_correct_fill(game);
	ft_epc_count(game);
}
