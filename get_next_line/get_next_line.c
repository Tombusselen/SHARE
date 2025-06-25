/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:10:14 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/25 14:46:03 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_static(char *hold)
{
	if (hold != NULL)
		free(hold);
	//hold = NULL;
	return (NULL);
}

static char	*get_hold(char *stock, char *tmp, char *hold, int fd)
{
	int	byte_rd;

	while (ft_strchr(stock, '\n') == 0)
	{
		byte_rd = read(fd, stock, BUFFER_SIZE);
		if (byte_rd < 0)
			return (NULL);
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
		if (hold == NULL)
			return (NULL);
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
		return (free_static(hold));
	tmp = new_hold(hold);
	free(hold);
	hold = tmp;
	return (line);
}
/*#include "get_next_line.h"

static char *free_static(char *ptr)
{
    if (ptr)
        free(ptr);
    return (NULL);
}

static char *get_hold(char *stock, char *hold, int fd)
{
    int bytes_read;
    char *tmp;

    while (!ft_strchr(hold, '\n'))
    {
        bytes_read = read(fd, stock, BUFFER_SIZE);
        if (bytes_read < 0)
            return (free_static(hold));
        if (bytes_read == 0)
            break;
        stock[bytes_read] = '\0';
        if (!hold)
            hold = ft_strdup(stock);
        else
        {
            tmp = ft_strjoin(hold, stock);
            free(hold);
            hold = tmp;
        }
        if (!hold)
            return (NULL);
    }
    return (hold);
}

static char *get_line(char *hold)
{
    char *line;
    size_t len;
    char *newline_pos;

    if (!hold || hold[0] == '\0')
        return (NULL);
    newline_pos = ft_strchr(hold, '\n');
    if (newline_pos)
        len = newline_pos - hold + 1;
    else
        len = ft_strlen(hold);
    line = ft_substr(hold, 0, len);
    return (line);
}

static char *new_hold(char *hold)
{
    char *newline_pos;
    char *new_hold;

    newline_pos = ft_strchr(hold, '\n');
    if (!newline_pos)
        return (NULL);
    new_hold = ft_strdup(newline_pos + 1);
    return (new_hold);
}

char *get_next_line(int fd)
{
    static char *hold;
    char *stock;
    char *line;
    char *tmp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stock = malloc(BUFFER_SIZE + 1);
    if (!stock)
        return (NULL);
    stock[0] = '\0';
    hold = get_hold(stock, hold, fd);
    free(stock);
    if (!hold)
        return (NULL);
    line = get_line(hold);
    if (!line)
    {
	free(hold);
	hold = NULL;
	return (NULL);
    }
    tmp = new_hold(hold);
    free(hold);
    hold = tmp;
    return (line);
}*/

