/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:59:03 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/27 11:41:09 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_type(char c, va_list opt)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(opt, int)));
	if (c == 's')
		return (ft_putstr(va_arg(opt, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(opt, int)));
	if (c == 'u')
		return (ft_putunsign(va_arg(opt, int)));
	if (c == 'x')
		return (ft_puthexlow(va_arg(opt, unsigned int)));
	if (c == 'X')
		return (ft_puthexup(va_arg(opt, unsigned int)));
	if (c == 'p')
		return (ft_putptr(va_arg(opt, void *)));
	return (0);
}
