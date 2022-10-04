/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:41 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/04 18:58:33 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	total = nmemb * size;
	result = (void *) malloc (total);
	if (total / nmemb != size || total / size != nmemb || (!result))
		return (NULL);
	ft_bzero (result, total);
	return (result);
}
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) s)[i] = '\0';
		i++;
	}
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
	char	*result;
	size_t	i;
	
	if (!result)
	{
		result = malloc(1 * sizeof(char));
		result[0] = '\0';
	}	
	if (!str1 || !str2)
		return (NULL);
	i = 0;
	result = ft_calloc(sizeof(char), ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!result)
		return (NULL);
	while (i < ft_strlen(str1))
	{
		result[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(str2))
	{
		result[ft_strlen(str1) + i] = str2[i];
		i++;
	}	
	*(result + ft_strlen(str1) + ft_strlen(str2)) = '\0';
	return (result);
}

