/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:29:07 by frushiti          #+#    #+#             */
/*   Updated: 2023/03/21 13:42:39 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_crossroad(va_list args, char identifier)
{
	int	nc_printed;

	nc_printed = 0;
	if (identifier == 'c')
		nc_printed = ft_putchar_ftp(va_arg(args, int));
	else if (identifier == 's')
		nc_printed = ft_putstr_ftp(va_arg(args, char *));
	else if (identifier == 'p')
		nc_printed = ft_putptr(va_arg(args, void *));
	else if (identifier == 'd' || identifier == 'i')
		nc_printed = ft_putnbr(va_arg(args, int));
	else if (identifier == 'u')
		nc_printed = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (identifier == 'x' || identifier == 'X')
		nc_printed = ft_putnbr_hex(va_arg(args, unsigned int), identifier);
	else if (identifier == '%')
		nc_printed = ft_putchar_ftp('%');
	return (nc_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nc_printed;
	int		i;

	i = 0;
	nc_printed = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			nc_printed = nc_printed + ft_crossroad(args, str[i + 1]);
			i++;
		}
		else
			nc_printed = nc_printed + ft_putchar_ftp(str[i]);
		i++;
	}
	va_end(args);
	return (nc_printed);
}
