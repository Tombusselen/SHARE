/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:43:20 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 17:37:36 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width_map(char *map_txt)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(map_txt, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line) - 1;
	free(line);
	close(fd);
	return (len);
}

int	height_map(char *map_txt)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map_txt, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		i++;
		free(line);
	}
	close(fd);
	ft_printf("count = %d \n", i);
	return (i);
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

void	free_arr(char **arr, int height)
{
	while (height >= 0)
	{
		free(arr[height]);
		height--;
	}
	free(arr);
}

void	init_map(t_game *game, char *map_txt)
{
	int	fd;

	fd = open(map_txt, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fichier .ber introuvable");
		exit (0);
	}
	close(fd);
	game->width_m = width_map(map_txt);
	game->height_m = height_map(map_txt);
	game->map = extract_map(game->height_m, map_txt);
}
