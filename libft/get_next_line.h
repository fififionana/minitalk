/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:58:31 by frushiti          #+#    #+#             */
/*   Updated: 2023/03/06 18:07:12 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);

int		ft_strlen(char *str);

char	*ft_strdup(char *src);

char	*ft_strcat(char *dest, char *src);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *src, int c);

#endif
