/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:11:23 by zaleksan          #+#    #+#             */
/*   Updated: 2025/04/23 20:17:36 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// size_t	ft_strlen(const char *src);
char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif