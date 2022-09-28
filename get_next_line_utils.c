/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:41 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/28 16:54:31 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	ovflow;
	size_t	i;
	
	
	i = 0;
	ovflow = nmemb * size;
	result = (void *) malloc (nmemb * size);
	if (ovflow / nmemb != size || ovflow / size != nmemb || (!result))
		return (NULL);
	while (i < size)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

