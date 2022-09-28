/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/28 16:45:20 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

static char	ft_get_first_line(const char *s)
{
	char	*result;
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	while (s[i] != '\0' && s[i] == '\n')
		i++;
	result = ft_calloc (i + 1, sizeof * result);
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
	return (result);
}

