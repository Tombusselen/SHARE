/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:05:47 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/27 11:25:03 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	opt;

	if (str == NULL)
		return (0);
	i = 0;
	count = 0;
	va_start(opt, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count = count + ft_type(str[i + 1], opt);
			i = i + 2;
		}
		else
		{
			write (1, &str[i], 1);
			count++;
			i++;
		}
	}
	va_end(opt);
	return (count);
}
