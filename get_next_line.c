/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:14 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/03 19:16:58 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	ft_read_line(int fd, char *str);
char	*ft_get_first_line(const char *str);
char	*ft_get_next_lines(const char *str);
char	*get_next_line(int fd);

// Function to read from the file descriptor
// normally here we use three parameters, but here we have the fd that will be read and the destination char buf of our strings.
// the third parameter refers to the number of bytes that we need to read, but in my file.h I already defined the BUFFER_SIZE as 1.
char	ft_read_line(int fd, char *str)
{
	char 	*buf;
	// int to stock the returned numbers of bytes that have been read or -1 in case of error
	int		ret; 
	
	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	//allocation failure handling
	if (!buf)
		return ;
	ret = 1;
	//here the ft_strchr function was used to find the first '\n' of the file to stop the loop
	while (!ft_strchr(str, '\n'))
	{
		buf = read(fd, buf, BUFFER_SIZE);
		//error handling, stop the reading and return the string
		if (ret == -1)
		{
			free (buf);
			return (*str);
		}	
		//end of the string
		buf[ret] = '\0';
		//parameter receives str + buf read from fd
		str = ft_strjoin(str, buf);
		if (!str)
		{
			free (buf);
			return (NULL);
		}		
	}
	free (buf);
	return (*str);
}
//Function to get the first line to return
char	*ft_get_first_line(const char *str)
{
	char	*result;
	size_t	i;
	
	//to loop through the string
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = malloc (sizeof(char)) * (i + 1);
	//allocation failure handling
	if (!result)
		return (NULL);
	//assigning values ​​to the result variable	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		result[i++] = str[i];
	}
	if (str[i] == '\n')
	{
		result[i++] = str[i]
	}
	result[i] = '\0';
	return (result);
}
//Function to get the next lines to return
char	*ft_get_next_lines(const char *str)
{
	char	*new_result;
	int		len_previous_str;
	size_t	i;
	size_t	j;

	//counter of the string that has already been read 
	i = 0; 
	//counter of the string that will be read
	j = 0; 
	//string lenght assignment passes as parameter both in ft_read_first_line as ft_reade_next_lines
	len_previous_str = ft_strlen(str);
	//to loop through the string, remembering that there is already a result referring to the reading of the first line
	while (str && str[j])
		j++;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	//condition to keep going up the string 	
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	new_result = malloc(len_previous_str - i + 1);
	//allocation failure handling
	if (!new_result)
		return (NULL);
	//assigning values ​​to the new_result variable, noting that the i and j counters will be summed		
	while (str[i + j])
	{
		new_result[j++] = str[i + j];
		//here we already have the counter i, only the assignment of counter j is necessary
	}			
	new_result = '\0';
	free (str);
	return (new_result);
}
//The get_next_line function
char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;
	
	//condition that handles the hypothesis of invalidity of the fd or the BUFFER_SIZE
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//static char receives the result of the ft_read_line function (str + buf read)
	str = ft_read_line(fd, str);
	//condition that handles the possibility of the line that we wnat to return is null or empty
	//in this case, free any allocated memory and return NULL
	if (!ft_strlen(str))
	{
		free (str);
		return (NULL);
	}
	//otherwise, return the line
	else
	{
		result = ft_get_first_line(str);
		str = ft_get_next_lines(str);
	}
	return (result);
}

