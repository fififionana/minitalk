/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:01:58 by frushiti          #+#    #+#             */
/*   Updated: 2023/03/05 17:13:06 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*next_line(char *a)
{
	int		i;
	char	*buf;

	if (!a || !a[0])
		return (NULL);
	i = 0;
	while (a[i] && a[i] != '\n')
		i++;
	if (a[i] == '\n')
		i++;
	buf = (char *)malloc((sizeof(char) * i) + 1);
	if (!buf)
		return (NULL);
	i = 0;
	while (a[i] && a[i] != '\n')
	{
		buf[i] = a[i];
		i++;
	}
	if (a[i] == '\n')
		buf[i++] = '\n';
	buf[i] = '\0';
	return (buf);
}

char	*offset(char *a)
{
	char	*buf;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!a)
		return (NULL);
	while (a[i] && a[i] != '\n')
		i++;
	if (a[i] == '\0')
	{
		free(a);
		return (NULL);
	}
	if (a[i] == '\n')
		i++;
	buf = (char *)malloc(ft_strlen(a) - i + 1);
	while (a[i])
		buf[x++] = a[i++];
	buf[x] = '\0';
	free(a);
	return (buf);
}

char	*read_file(int fd, char *str, char *buf)
{
	int		i;
	char	*tmp;

	i = 1;
	while (!(ft_strchr(str, '\n')) && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	free (buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buf)
		return (NULL);
	str = read_file(fd, str, buf);
	if (!str)
		return (NULL);
	buf = next_line(str);
	str = offset(str);
	return (buf);
}
