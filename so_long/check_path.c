/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:48:51 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 15:59:13 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_reach(t_game *game, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x > game->width_m || y > game->height_m)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	ft_reach(game, map, x + 1, y);
	ft_reach(game, map, x - 1, y);
	ft_reach(game, map, x, y + 1);
	ft_reach(game, map, x, y - 1);
}

char	**map_cpy(t_game *game)
{
	char	**tmp_map;
	int		i;

	i = 0;
	tmp_map = malloc(sizeof(char *) * (game->height_m));
	if (tmp_map == NULL)
		return (0);
	while (i < game->height_m)
	{
		tmp_map[i] = ft_strdup(game->map[i]);
		if (tmp_map[i] == NULL)
		{
			free_arr(tmp_map, i);
			return (0);
		}
		i++;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

int	ft_check_path(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		j;

	i = 0;
	tmp_map = map_cpy(game);
	ft_reach(game, tmp_map, game->player_data.x, game->player_data.y);
	while (i < game->height_m)
	{
		j = 0;
		while (j < game->width_m)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') &&
				tmp_map[i][j] != 'V')
			{
				free_arr(tmp_map, i);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_arr(tmp_map, i);
	return (1);
}
