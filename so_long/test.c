/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:40:05 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 17:31:10 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("maps/test.ber", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s\n", line);
		free(line);
	}
	free(line);
}
