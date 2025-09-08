/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:38:38 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 15:52:20 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_img
{
	void	*img;
	void	*addr;
	char	*path;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
	int	collected;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	int			width_m;
	int			height_m;
	int			move_count;
	int			collec_nbr;
	t_img		floor;
	t_img		wall;
	t_img		player;
	t_img		collectible;
	t_img		exit;
	t_player	player_data;
}	t_game;

//maps
char	**extract_map(int height, char *map_txt);
void	free_arr(char **arr, int height);
void	init_map(t_game *game, char *map_txt);
int		width_map(char *map_txt);
int		height_map(char *map_txt);
//generate map
void	def_window(t_game *game);
void	create_map(t_game *game);
void	display_map(t_game *game);
//check map
void	ft_rectangular(t_game *game);
void	ft_surrounded(t_game *game);
void	ft_correct_fill(t_game *game);
void	check_map(t_game *game);
//check map helper
void	ft_epc_count(t_game *game);
void	ft_epc_check(t_game *game, int e_count, int p_count);
//check path
void	ft_reach(t_game *game, char **map, int x, int y);
char	**map_cpy(t_game *game);
int		ft_check_path(t_game *game);
//images
void	load_images(t_game *game);
//player
void	player_pos(t_game *game);
void	player_move(t_game *game, int dx, int dy);
int		key_action(int keycode, t_game *game);
//so_long
void	clean_exit(t_game *game);

#endif
