/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:07:43 by frushiti          #+#    #+#             */
/*   Updated: 2023/03/06 18:38:58 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	if (!dest && size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	x = 0;
	if (i >= size)
		return (ft_strlen(src) + size);
	while (i + x < size -1 && src[x] != '\0')
	{
		dest[i + x] = src[x];
		x++;
	}
	dest[i + x] = '\0';
	return (i + ft_strlen(src));
}
