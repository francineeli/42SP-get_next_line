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
		while (str[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		{
			if (str[i] == (char) c)
				return ((char *) str + i);
			i++;
		}
	return (NULL);
}

// size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
// {
// 	size_t	src_len;
// 	size_t	dst_len;
// 	size_t	i;

// 	src_len = ft_strlen(src);
// 	dst_len = ft_strlen(dst);
// 	i = 0;
// 	if (dstsize <= dst_len)
// 		return (src_len + dstsize);
// 	while (src[i] != '\0' && i < (dstsize - dst_len - 1))
// 	{
// 		dst[dst_len + i] = src[i];
// 		i++;
// 	}
// 	dst[dst_len + i] = '\0';
// 	return (dst_len + src_len);
// }

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	
	i = 0;
	if (dstsize <= 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0' && i < dstsize -1)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));	
}

// char	*ft_strdup(char *src)
// {
// 	char	*dst;
// 	size_t	len;

// 	len = ft_strlen(src) + 1;
// 	dst = malloc(len);
// 	if (dst)
// 		ft_strlcpy(dst, src, len);
// 	return (dst);
// }

// char	*ft_strjoin(char *str1, char *str2)
// {
// 	char	*finalstr;
// 	size_t 	size;
	
// 	size = ft_strlen(str1) + ft_strlen(str2) + 1;
// 	finalstr = malloc(size);
// 	if (!str1 && !str2)
// 		return (NULL);
// 	if (!str1)
// 		return (ft_strdup(str2));
// 	if (!str2)
// 		return (ft_strdup(str1));
// 	if (!finalstr)
// 		return (NULL);	
// 	ft_strlcpy(finalstr, str1, size);
// 	ft_strlcat (finalstr, str2, size);
// 	return (finalstr);
// }
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
