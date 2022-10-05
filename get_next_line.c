/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/05 20:14:19 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_read_line(int fd, char *str);
char	*ft_check_first_line(char *str);
char	*ft_check_next_line(char *str);
char	*get_next_line(int fd);

char	*ft_strchr(char *str, int c)
{
	int	i;
	char	*find;
	
	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == (char) c)
			{
				find = &str[i];
				return ((char *) find);
			}
			i++;
		}
		if (c == 0)
			find = (str + ft_strlen(str));
		return ((char *) find);
	}
	return (NULL);
}

char	*ft_check_first_line(char *str)
{
	char	*strcheck;
	size_t	i;
	
	i = 0;
	if(str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	strcheck = malloc(sizeof(char) * (i + str[i] == '\n' + 1));
	if (strcheck == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		strcheck[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		strcheck[i++] = '\n';
	strcheck[i] = '\0';
	return (strcheck);
}

char	*ft_check_next_line(char *str)
{
	char	*cknewstr;
	size_t	i;
	size_t	j;

	i = 0; 
	while (str[i] != '\0' && str[i] != '\n')
		i++;	
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	cknewstr = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (cknewstr == NULL)
		return (NULL);
	i++;
	j = 0;
	while (str[i + j] != '\0')
	{
		cknewstr[j] = str[i + j];
		j++;
	}			
	cknewstr[j] = '\0';			
	free (str);
	return (cknewstr);
}

char	*ft_read_line(int fd, char *str)
{
	char 	*buf;
	ssize_t	t; 
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	t = 1;
	while (!ft_strchr(str, '\n'))
	{
		t = read (fd, buf, BUFFER_SIZE);
		if (t <= 0)
		{
			free (buf);
			return (str);
		}
		buf[t] = '\0';
		str = ft_strjoin(str, buf);
		if (str == NULL)
		{
			free (buf);
			return (NULL);
		}		
	}
	free (buf);
	if (t == -1)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;
	static char	*result;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line(fd, str);
	result = ft_check_first_line(str);
	if (result == NULL)
		return (NULL);
	str = ft_check_next_line(str);
	return (result);
}

