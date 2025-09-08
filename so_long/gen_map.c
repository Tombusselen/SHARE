/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:36:20 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 13:33:24 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	def_window(t_game *game)
{
	game->width = (game->exit.img_width * game->width_m);
	game->height = (game->exit.img_height * game->height_m);
	game->win = mlx_new_window(game->mlx, game->width, game->height,
			"A ring to rule them all !");
}

void	map_to_game(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = j * game->exit.img_width;
	y = i * game->exit.img_width;
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, x, y);
	else if (game->map[i][j] == '0' | game->map[i][j] == 'P' |
		game->map[i][j] == 'C' | game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor.img, x, y);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.img, x, y);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, x, y);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, x, y);
}

void	create_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height_m)
	{
		j = 0;
		while (j < game->width_m)
		{
			map_to_game(game, i, j);
			j++;
		}
		i++;
	}
}

void	display_map(t_game *game)
{
	def_window(game);
	create_map(game);
}
