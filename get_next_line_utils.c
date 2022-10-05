/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:41 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/05 19:43:19 by feli-bar         ###   ########.fr       */
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
size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize == 0)
		return (src_len);
	if (dst_len < dstsize)
	{
		i = 0;	
		while (src[i] != '\0' && i < dstsize - dst_len - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + dstsize);
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
		dst[i] = '\0';
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
	char	*added;
	size_t 	size;
	
	if (!str1)
	{
		str1 = malloc(1 * sizeof(char));
		str1[0] = '\0';
	}	
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	added = malloc(sizeof(size)); 
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 == NULL)
		return (ft_strdup(str2));
	if (str2 == NULL)
		return (ft_strdup(str1));
	if (added == NULL)
		return (NULL);
	ft_strlcpy(added, str1, ft_strlen(str1));
	ft_strlcat (added, str2, size + 1);
	return (added);
}
