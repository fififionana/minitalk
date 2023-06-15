/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:48:52 by frushiti          #+#    #+#             */
/*   Updated: 2023/03/15 14:35:38 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_len(long n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_put_nbr(long n, char *result, int *i)
{
	if (n > 9)
	{
		ft_put_nbr(n / 10, result, i);
		ft_put_nbr(n % 10, result, i);
	}
	else
		result[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	nbr;

	nbr = n;
	result = (char *)malloc((ft_str_len(nbr) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		result[i] = '-';
		nbr *= -1;
		i++;
	}
	ft_put_nbr(nbr, result, &i);
	result[i] = '\0';
	return (result);
}
