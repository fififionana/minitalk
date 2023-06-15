/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:21:22 by frushiti          #+#    #+#             */
/*   Updated: 2023/04/05 14:22:12 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h> 
# include <stdlib.h> 
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_crossroad(va_list args, char data_type);

/* Parameter functions */
int		ft_putchar_ftp(char c);
int		ft_putstr_ftp(const char *s);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putptr(void *ptr);
int		ft_putnbr_hex(unsigned int nb, char x);

/* Utility functions */
//size_t	ft_strlen(const char *s);
int		ft_putnbr_phex(unsigned long long nb);

#endif
