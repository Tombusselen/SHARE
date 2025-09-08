/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:51:02 by tbussele          #+#    #+#             */
/*   Updated: 2025/07/15 10:22:37 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	nbr_mots(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			nbr++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (nbr);
}

static char	*arr_mot(const char *s, size_t size_m)
{
	char			*mot;
	unsigned int	i;

	i = 0;
	mot = malloc(sizeof(char) * (size_m + 1));
	if (mot == NULL)
		return (NULL);
	while (i < size_m)
	{
		mot[i] = s[i];
		i++;
	}
	mot[i] = '\0';
	return (mot);
}

static void	free_all(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
}

static char	**add_mot(char **arr, const char *s, char c, int j)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > start)
		{
			arr[j] = arr_mot(&s[start], (i - start));
			if (arr[j] == NULL)
			{
				free_all(arr, j);
				return (NULL);
			}
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	j;
	char			**arr;

	if (s == NULL)
		return (NULL);
	j = 0;
	arr = malloc(sizeof(char *) * (nbr_mots(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	arr = add_mot(arr, s, c, j);
	return (arr);
}
