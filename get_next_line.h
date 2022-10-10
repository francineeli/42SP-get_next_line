/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:07:01 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/10 15:32:55 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/*---------------GNL---------------*/
char	*ft_alloc_first_line(char *str);
char	*ft_alloc_next_line(char *str);
char	*ft_read_line(int fd, char *str);
char	*get_next_line(int fd);

/*---------------UTILS---------------*/
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
#endif