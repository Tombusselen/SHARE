/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:45:32 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/27 11:34:18 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

int	ft_printf(const char *str, ...);
int	ft_type(char c, va_list opt);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunsign(int n);
int	ft_puthexup(unsigned int nbr);
int	ft_puthexlow(unsigned int nbr);
int	ft_putptr(void *ptr);
int	ft_puthexptr(unsigned long nbr);

#endif
