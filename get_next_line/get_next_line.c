/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:10:14 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/26 11:33:15 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_static(char *hold)
{
	if (hold != NULL)
		free(hold);
	return (NULL);
}

static char	*get_hold(char *stock, char *tmp, char *hold, int fd)
{
	int	byte_rd;

	while (ft_strchr(stock, '\n') == 0)
	{
		byte_rd = read(fd, stock, BUFFER_SIZE);
		if (byte_rd < 0)
		{
			if (hold != NULL)
				free(hold);
			return (NULL);
		}
		if (byte_rd == 0)
			break ;
		stock[byte_rd] = '\0';
		if (hold == NULL)
			hold = ft_strdup(stock);
		else
		{
			tmp = ft_strjoin(hold, stock);
			free(hold);
			hold = tmp;
		}
	}
	return (hold);
}

static char	*get_line(char *hold)
{
	char			*n_pos;
	char			*line;
	unsigned int	len;

	if (hold == NULL || hold[0] == '\0')
		return (NULL);
	n_pos = ft_strchr(hold, '\n');
	if (n_pos != NULL)
		len = n_pos - &hold[0] + 1;
	else
		len = ft_strlen(hold);
	line = ft_substr(hold, 0, len);
	return (line);
}

static char	*new_hold(char *hold)
{
	char	*new_hold;
	char	*n_pos;

	n_pos = ft_strchr(hold, '\n');
	if (n_pos == NULL)
		return (NULL);
	new_hold = ft_strdup(n_pos + 1);
	return (new_hold);
}

char	*get_next_line(int fd)
{
	char			*stock;
	char			*tmp;
	char			*line;
	static char		*hold;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = malloc(BUFFER_SIZE + 1);
	if (stock == NULL)
		return (NULL);
	stock[0] = '\0';
	tmp = NULL;
	hold = get_hold(stock, tmp, hold, fd);
	free(stock);
	if (hold == NULL)
		return (NULL);
	line = get_line(hold);
	if (line == NULL)
		return (hold = free_static(hold));
	tmp = new_hold(hold);
	free(hold);
	hold = tmp;
	return (line);
}
