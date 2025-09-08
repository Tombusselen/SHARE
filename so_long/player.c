/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:47:13 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 13:37:18 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->height_m)
	{
		i = 0;
		while (i < game->width_m)
		{
			if (game->map[j][i] == 'P')
			{
				game->player_data.x = i;
				game->player_data.y = j;
			}
			i++;
		}
		j++;
	}
}

int	key_action(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		printf("you pressed ESC, the window closed\n");
		clean_exit(game);
	}
	else if (keycode == 119)
		player_move(game, 0, -1);
	else if (keycode == 115)
		player_move(game, 0, 1);
	else if (keycode == 97)
		player_move(game, -1, 0);
	else if (keycode == 100)
		player_move(game, 1, 0);
	return (0);
}

void	move_update(t_game *game, char next, int new_x, int new_y)
{
	if (next == '1')
	{
		ft_printf("You cannot go there !\n");
		return ;
	}
	if (next == 'C')
	{
		game->player_data.collected++;
		game->map[new_y][new_x] = '0';
	}
	if (next == 'E')
	{
		if (game->player_data.collected == game->collec_nbr)
		{
			ft_printf("🏆🏆 YOU WIN !!! 🏆🏆\n");
			clean_exit(game);
		}
		else
		{
			ft_printf("You forgot a PRECIOUS\n");
			return ;
		}
	}
}

void	player_move(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = game->player_data.x + dx;
	new_y = game->player_data.y + dy;
	next = game->map[new_y][new_x];
	move_update(game, next, new_x, new_y);
	if (next == '1' || next == 'E')
		return ;
	game->map[game->player_data.y][game->player_data.x] = '0';
	game->player_data.x = new_x;
	game->player_data.y = new_y;
	game->map[game->player_data.y][game->player_data.x] = 'P';
	game->move_count++;
	ft_printf("move count : %d \n", game->move_count);
	create_map(game);
}
