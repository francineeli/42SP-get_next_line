/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:39 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/05 11:08:57 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

/*----------GNL----------*/
char	*ft_read_line(int fd, char *str);
char	*ft_get_first_line(char *str);
char	*ft_get_next_line(char *str);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);

/*----------UTILS----------*/
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *str1, char *str2);