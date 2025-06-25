/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:10:14 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/19 12:10:18 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_hold(char *stock, char *tmp)
{
	while (newline(stock) == 0)
	{
		byte_rd = read(fd, stock, BUFFER_SIZE);
		if (byte_rd < 0)
		{
			free(stock);
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

char	*get_line(char *hold, char *tmp)
{
	char			*n_pos;
	char			*line;
	unsigned int	len;

	line = NULL;
	n_pos = ft_strchr(hold, '\n');
	if (n_pos != NULL)
	{
		len = n_pos - &hold[0] + 1;
		line = ft_substr(hold, 0, len);
		tmp = ft_strdup(&hold[len]);
		free(hold);
		hold = tmp;
		printf("HOLD : %s", hold);
	}
	else
	{
		line = ft_strdup(hold);
		free(hold);
		hold = NULL;
	}
	return (line);
}


char	*get_next_line(int fd)
{
	int				byte_rd;
	char			*stock;
	char			*tmp;
	static char		*hold;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = malloc(BUFFER_SIZE + 1);
	if (stock == NULL)
		return (NULL);
	/*while (newline(stock) == 0)
	{
		byte_rd = read(fd, stock, BUFFER_SIZE);
		if (byte_rd < 0)
		{
			free(stock);
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
	}*/
	hold = get_hold(stock, tmp);
	printf("ICI : %s", stock);
	free(stock);
	if (hold == NULL || hold[0] == '\0')
	{
		free(hold);
		hold = NULL;
		return (NULL);
	}
	return (get_line(hold, tmp));
}
