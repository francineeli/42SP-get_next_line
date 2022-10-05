char	*ft_strjoin(char *str1, char *str2)
{
	char	*added;
	size_t 	size;
	
	// if (!result)
	// 	{
	// 	result = malloc(1 * sizeof(char));
	// 	result[0] = '\0';
	// 	}	
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	added = malloc(sizeof(char) * size); 
	//ft_calloc(sizeof(char), ft_strlen(str1) + ft_strlen(str2) + 1);
	if (result == NULL)
	{
		free(str1)
		return (NULL);
	}
	//ft_strcat(result, str1);		
	//ft_strcat(result, str2);	
	// while (i < ft_strlen(str1))
	// {
	// 	result[i] = str1[i];
	// 	i++;
	// }
	// i = 0;
	// while (i < ft_strlen(str2))
	// {
	// 	result[ft_strlen(str1) + i] = str2[i];
	// 	i++;
	// }	
	*(result + ft_strlen(str1) + ft_strlen(str2) + 1) = '\0';
	free (result);
	return (result);
}

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	total;
	size_t	i;

	i = 0;
	total = nmemb * size;
	result = (void *) malloc (total);
	if (total / nmemb != size || total / size != nmemb || (!result))
		return (NULL);
	while (i < total)
	{
		((char *) result)[i] = '\0';
		i++;
	}
	return (result);
}

char	*ft_strchr(char *str, int c)
{
	int	i;
	const char *result;

	i = 0;
	result = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == (char) c)
			{
				result = &str[i];
				return ((char *) str + i);
			}
			i++;
		}
		if (c == 0)
			result = (str + ft_strlen(str));
		return ((char *) result);
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*added;
	size_t 	size;
	
	
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	added = malloc(sizeof(char) * size); 
	if (result == NULL)
	{
		free(str1)
		return (NULL);
	}
	
	*(result + ft_strlen(str1) + ft_strlen(str2) + 1) = '\0';
	free (result);
	return (result);
}
void ft_strcat(char *dst, char *src)
{
	size_t inc;
	size_t size;

	inc = 0;
	size = ft_strlen(dst);
	if (src)
	{
		while(src[inc] != '\0')	
		{
			dst[size + inc + 1] = src[inc];
			inc++;
		}
	}	
}

#include "get_next_line.h" 

char	*ft_read_line(int fd, char *str);
char	*ft_check_first_line(char *str);
char	*ft_check_next_line(char *str);
char	*get_next_line(int fd);

char	*ft_check_first_line(char *str)
{
	char	*result;
	size_t	i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = ft_calloc(i, sizeof * result);
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
	new_result = ft_calloc((j - i) + 1, sizeof * new_result);
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


char	*get_next_line(int fd)
{
	char	*str;
	static char	*result;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line(fd, str);
	if (!ft_strlen(str))
	{
		free (result);
		return (NULL);
	}
	else
	{
		result = ft_check_first_line(str);
		str = ft_check_next_line(str);
	}
	return (result);
}

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
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void 	ft_strcat(char *dst, char *src);
void	*ft_calloc(size_t nmemb, size_t size);