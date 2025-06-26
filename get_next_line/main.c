/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:17:11 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/25 15:20:29 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     main(void)
{
        char *line;
	char *line2;
	char *line3;
	int fd = open("text_gnl", O_RDONLY);
	int fd2 = open("textvide", O_RDONLY);
	int fd3 = open("giant_line_nl.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	if (line == NULL)
		printf("%s", line);
	printf("||||||||||||||||||||||||||||||||||||||");
	while ((line2 = get_next_line(fd2)) != NULL)
        {
                printf("%s", line2);
                free(line2);
        }
        if (line2 == NULL)
                printf("%s", line2);
	printf("||||||||||||||||||||||||||||||||||||||");
	while ((line3 = get_next_line(fd3)) != NULL)
        {
                printf("%s", line3);
                free(line3);
        }
        if (line3 == NULL)
                printf("%s", line3);
	
	return (0);
}

