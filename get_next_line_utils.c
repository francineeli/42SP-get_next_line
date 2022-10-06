/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:41 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/06 19:06:40 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == (char) c)
				return ((char *) str + i);
			i++;
		}
		if (c == '\0')
			return ((char *) str + i);
		return (0);
	}
	return (0);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[i] != '\0' && i < (dstsize - dst_len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	
	if (dstsize)
	{
		i = 0;
		while (src[i] != '\0' && i < dstsize -1)
		{
			dst[i] = src[i];
			i++;
		}
		//dst[i] = " ";
	}	
	return (ft_strlen(src));	
}

char	*ft_strdup(char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src) + 1;
	dst = malloc(len);
	if (dst)
		ft_strlcpy(dst, src, len);
	return (dst);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*finalstr;
	size_t 	size;
	
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	finalstr = malloc(size);
	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	if (!finalstr)
		return (NULL);	
	ft_strlcpy(finalstr, str1, size);
	ft_strlcat (finalstr, str2, size);
	return (finalstr);
}
