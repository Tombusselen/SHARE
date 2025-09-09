/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:07:42 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/09 13:39:02 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	destroy_images(t_game *game)
{
	if (game->wall.img)
	mlx_destroy_image(game->mlx, game->wall.img);
	if (game->floor.img)
	mlx_destroy_image(game->mlx, game->floor.img);
	if (game->player.img)
	mlx_destroy_image(game->mlx, game->player.img);
	if (game->exit.img)
	mlx_destroy_image(game->mlx, game->exit.img);
	if (game->collectible.img)
	mlx_destroy_image(game->mlx, game->collectible.img);
}

void	clean_exit(t_game *game)
{
	free_arr(game->map);
	if (game->mlx != NULL)
	{
		destroy_images(game);
		if (game->win != NULL)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
