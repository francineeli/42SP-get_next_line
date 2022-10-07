/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:41 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/06 21:48:21 by feli-bar         ###   ########.fr       */
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

char	*ft_strchr(char *str, int c)
{
	const char	*find;
	int			i;

	i = 0;
	find = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == (char) c)
				find = (str + i);
			return ((char *) str + i);
			i++;
		}
		if (c == 0)
			find = (str + ft_strlen(str));
		return ((char *) find);
	}	
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	newstr = (char *) malloc((ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!newstr)
		return (NULL);
	if (str1)
	{
		while (str1[len1])
		{
			newstr[len1] = str1[len1];
			len1++;
		}
	}
	while (str2[len2])
	{
		newstr[len1 + len2] = str2[len2];
		len2++;
	}	
	newstr[len1 + len2] = '\0';
	free (str1);
	return (newstr);
}
