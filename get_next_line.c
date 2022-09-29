/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/29 22:20:21 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_get_first_line(const char *str)
{
	char	*result;
	size_t		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	result = (char *)malloc (sizeof(char)) * (i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		result[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		result[i] = s[i]
			i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_get_next_line(const char *str)
{
	char	*new_str;
	int		len_old_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_old_str = ft_strlen(str);
	while (str && str[j])
		j++;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	new_str = malloc(len_old_str - i + 1);
	if (!new_str)
		return (NULL);
	while (str[i + j])
	{
		new_str[j] = str[i + j];
		j++;
	}		
	new_str = '\0';
	free (str);
	return (new_str);
}

char	ft_read_line(int fd, char *str)
{
	char 	*buf;
	int		k;
	
	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	while (!ft_strchr(str, '\n'));
	{
		k = read(fd, buf, BUFFER_SIZE);
		if (k == -1) - pesquisar numeros reservados read
		(
			free (buf);
			return (str);
		)
		buf[k] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
		{
			free(buf);
			return (str);
		}
		if (!str)
		{
			free (buf);
			return (NULL);
		}		
	}
	free (buf);
	return (str);
}


