/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:43:20 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/09 13:23:56 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_dimensions(t_game *game, char *map_txt)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map_txt, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR : fichier .ber introuvable");
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i == 0)
			game->width_m = ft_strlen(line) - 1;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->height_m = i;
	close(fd);
}

char	**extract_map(int height, char *map_txt)
{
	int		i;
	int		fd;
	char	**map;

	fd = open(map_txt, O_RDONLY);
	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		return (NULL);
	while (i < height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[height] = NULL;
	close(fd);
	return (map);
}

void	init_map(t_game *game, char *map_txt)
{
	map_dimensions(game, map_txt);
	game->map = extract_map(game->height_m, map_txt);
}
