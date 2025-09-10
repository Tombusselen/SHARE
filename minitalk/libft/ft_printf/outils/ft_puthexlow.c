/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:54:42 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/27 11:40:30 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexlow(unsigned int nbr)
{
	int		mod;
	int		i;
	int		count;
	char	ch[50];

	mod = 0;
	i = 0;
	ch[0] = '0';
	if (nbr == 0)
		return (write(1, "0", 1));
	while (nbr > 0)
	{
		mod = nbr % 16;
		nbr = nbr / 16;
		if (mod > 9)
			ch[i] = (mod - 10) + 'a';
		else
			ch[i] = mod + '0';
		i++;
	}
	count = i;
	while (i > 0)
		write (1, &ch[--i], 1);
	return (count);
}
