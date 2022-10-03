/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:39 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/03 23:55:40 by feli-bar         ###   ########.fr       */
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
char	*ft_get_first_line(const char *str);
char	*ft_get_next_line(char *str);
char	*get_next_line(int fd);

/*----------UTILS----------*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);