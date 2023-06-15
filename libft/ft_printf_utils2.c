/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:11:51 by frushiti          #+#    #+#             */
/*   Updated: 2023/05/26 18:12:20 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
HEXADECIMAL
*/

int	ft_putnbr_hex(unsigned int nb, char x)
{
	char			*hex;
	int				len;

	len = 0;
	hex = "0123456789abcdef";
	if (x == 'X')
		hex = "0123456789ABCDEF";
	if (nb >= 16)
		len += ft_putnbr_hex(nb / 16, x);
	write(1, &hex[nb % 16], 1);
	len++;
	return (len);
}

/*
UNSIGNED
*/

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_putnbr_unsigned(nb / 10);
		len += ft_putnbr_unsigned(nb % 10);
	}
	else
		len += ft_putchar_ftp(nb + 48);
	return (len);
}
