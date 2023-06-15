/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:13:31 by frushiti          #+#    #+#             */
/*   Updated: 2023/03/09 15:38:21 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	char	*tmp;
	int		i;

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
	static char		*str[8192] = {NULL};
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buf)
		return (NULL);
	str[fd] = read_file(fd, str[fd], buf);
	if (!str[fd])
		return (NULL);
	buf = next_line(str[fd]);
	str[fd] = offset(str[fd]);
	return (buf);
}
