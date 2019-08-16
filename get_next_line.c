/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 09:29:07 by mnkebeny          #+#    #+#             */
/*   Updated: 2019/08/16 17:55:53 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_length(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	return (i);
}

int		get_chr(char **str, char **line, int r)
{
	int			i;
	char		*hold;

	if (*str == NULL)
		return (0);
	i = ft_length(str);
	if ((*str)[i] != '\0')
	{
		(*line) = ft_strsub(*str, 0, i);
		hold = ft_strdup(*str + i + 1);
		free(*str);
		*str = ft_strdup(hold);
		free(hold);
		return (1);
	}
	if ((*str)[i] == '\0' && r == 0)
	{
		(*line) = ft_strdup(*str);
		hold = ft_strsub(*str, i, ft_strlen(*str));
		free(*str);
		*str = ft_strdup(hold);
		free(hold);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	static char		*temp = NULL;
	char			*temp2;
	char			buffer[BUFF_SIZE + 1];

	i = 1;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((get_chr(&temp, &(*line), i) == 0))
	{
		if ((i = read(fd, buffer, BUFF_SIZE)) < 0)
			return (-1);
		buffer[i] = '\0';
		if (temp == NULL)
			temp = ft_strdup(buffer);
		else
		{
			temp2 = temp;
			temp = ft_strjoin(temp2, buffer);
			free(temp2);
		}
	}
	if (ft_strlen(*line) > 0 || i > 0)
		return (1);
	return (0);
}

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

	int		fd;
	char	*line;

	if (argc == 1)
	{
		fd = 0;
		ft_putendl("nothing was rea...");
		return(0);
	}
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
