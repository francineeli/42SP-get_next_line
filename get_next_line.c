/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/04 17:10:28 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_read_line(int fd, char *str);
char	*ft_check_first_line(const char *str);
char	*ft_check_next_line(char *str);
char	*get_next_line(int fd);

char	*ft_read_line(int fd, char *str)
{
	char 	*buf;
	int		ret; 
	
	buf = malloc(BUFFER_SIZE + 1);
	ret = 0;
	while (!ft_strchr(str, '\n'))
	{
		ret = read (fd, buf, BUFFER_SIZE);
		if (ret <= 0)
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

char	*ft_check_first_line(const char *str)
{
	char	*result;
	size_t	i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = ft_calloc(i, sizeof(result));
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
	return (result);
}

char	*ft_check_next_line(char *str)
{
	char	*new_result;
	size_t	i;
	size_t	j;

	i = 0; 
	j = 0; 
	while (str && str[j])
		j++;
	while (str[i] != '\0' && str[i] != '\n')
		i++;	
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	new_result = ft_calloc((j - i) + 1, sizeof(new_result));
	if (!new_result)
		return (NULL);
	while (str[i + j])
	{
		new_result[j] = str[i + j];
		j++;
	}			
	free (str);
	return (new_result);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*result;
	
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
		result = ft_check_first_line(str);
		str = ft_check_next_line(str);
	}
	return (result);
}

