/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:41 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/04 14:06:45 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	ovflow;

	ovflow = nmemb * size;
	result = (void *)malloc (nmemb * size);
	if (ovflow / nmemb != size || ovflow / size != nmemb || (!result))
		return (NULL);
	ft_bzero (result, ovflow);
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
char	*ft_strchr(char *s, int c)
{
	int	i;
	const char *result;

	i = 0;
	result = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == (char) c)
			{
				result = &s[i];
				return ((char *) s + i);
			}
			i++;
		}
			if (c == 0)
				result = (s + ft_strlen(s));
			return ((char *) result);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}	
	*(str + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (str);
}

