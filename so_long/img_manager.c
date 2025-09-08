/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:41:53 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 11:21:25 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "images/basalt.xpm",
			&game->floor.img_width, &game->floor.img_height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "images/lava.xpm",
			&game->wall.img_width, &game->wall.img_height);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "images/frodo.xpm",
			&game->player.img_width, &game->player.img_height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx, "images/ring.xpm",
			&game->collectible.img_width, &game->collectible.img_height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "images/eagle.xpm",
			&game->exit.img_width, &game->exit.img_height);
	if (!game->wall.img || !game->floor.img || !game->player.img
		|| !game->collectible.img || !game->exit.img)
	{
		printf("Erreur : impossible de charger les images\n");
		exit(1);
	}
}
