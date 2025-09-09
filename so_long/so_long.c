/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:55:09 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/09 11:13:01 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_cross(t_game *game)
{
	printf("you clicked on the cross, window closed\n");
	clean_exit(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.player_data.collected = 0;
	game.move_count = 0;
	if (argc == 2)
	{
		game.mlx = mlx_init();
		init_map(&game, argv[1]);
		load_images(&game);
		check_map(&game);
		player_pos(&game);
		if (ft_check_path(&game) == 0)
		{
			ft_printf("ERROR : No possible escape! \n");
			clean_exit(&game);
		}
		display_map(&game);
		mlx_hook(game.win, 2, 1L << 0, key_action, &game);
		mlx_hook(game.win, 17, 0, close_cross, &game);
		mlx_loop(game.mlx);
		clean_exit(&game);
	}
	return (0);
}
