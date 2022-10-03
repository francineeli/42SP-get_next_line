/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/04 00:03:39 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_read_line(int fd, char *str);
char	*ft_get_first_line(const char *str);
char	*ft_get_next_line(char *str);
char	*get_next_line(int fd);

char	*ft_read_line(int fd, char *str)
{
	char 	*buf;
	int		ret; 
	
	buf = malloc(BUFFER_SIZE + 1);
	ret = 1;
	while (!ft_strchr(str, '\n'))
	{
		ret = read (fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free (buf);
			return (str);
		}	
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
		{
			free (buf);
			return (NULL);
		}		
	}
	free (buf);
	return (str);
}

char	*ft_get_first_line(const char *str)
{
	char	*result;
	size_t	i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = malloc (sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_get_next_line(char *str)
{
	 char	*new_result;
	int		len_previous_str;
	size_t	i;
	size_t	j;

	i = 0; 
	j = 0; 
	len_previous_str = ft_strlen(str);
	while (str && str[j])
		j++;
	while (str[i] != '\0' && str[i] != '\n')
		i++;	
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	new_result = malloc(len_previous_str - i + 1);
	if (!new_result)
		return (NULL);
	while (str[i + j])
	{
		new_result[j] = str[i + j];
		j++;
	}			
	new_result[j] = '\0';
	free (str);
	return (new_result);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line(fd, str);
	if (!ft_strlen(str))
	{
		free (str);
		return (NULL);
	}
	else
	{
		str = ft_get_first_line(str);
		result = ft_get_next_line(str);
	}
	return (result);
}

