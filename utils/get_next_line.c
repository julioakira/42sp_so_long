/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:10:39 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/18 02:40:06 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static char	*retrieve_line(char **buffer);
static char	*buffer_to_line(char **buffer, char *line);
static char	*handle_line(
				int fd,
				char **buffer,
				char **preserved_line,
				char **line
				);
static int	str_has_newline(char *str);

static int	str_has_newline(char *str)
{
	size_t	idx;

	if (!str || !str[0])
		return (0);
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (1);
		idx++;
	}
	return (0);
}

static char	*buffer_to_line(char **buffer, char *line)
{
	size_t	idx;

	idx = 0;
	while ((*buffer)[idx])
	{
		line[idx] = (*buffer)[idx];
		if ((*buffer)[idx] == '\n')
		{
			line[idx] = (*buffer)[idx];
			idx++;
			break ;
		}
		idx++;
	}
	return (line);
}

static char	*retrieve_line(char **buffer)
{
	size_t	idx;
	char	*line;
	char	*ptr;

	idx = 0;
	if (!*buffer || *buffer[0] == '\0')
		return (NULL);
	while ((*buffer)[idx])
	{
		if ((*buffer)[idx] == '\n')
		{
			idx++;
			break ;
		}
		idx++;
	}
	line = ft_calloc((idx + 1), sizeof(char));
	if (!line)
		return (NULL);
	line = buffer_to_line(buffer, line);
	ptr = *buffer;
	*buffer = ft_strdup(&(*buffer)[idx]);
	free(ptr);
	return (line);
}

static char	*handle_line(
						int fd,
						char **buffer,
						char **preserved_line,
						char **line
						)
{
	char	*holder;
	int		read_checker;

	read_checker = 1;
	while (!str_has_newline(*preserved_line) && read_checker)
	{
		read_checker = read(fd, *buffer, BUFFER_SIZE);
		if (read_checker < 0)
			return (NULL);
		holder = *preserved_line;
		*preserved_line = ft_strjoin(holder, *buffer);
		ft_bzero(*buffer, BUFFER_SIZE);
		free_and_nullify(holder);
		if (read_checker == 0)
			break ;
	}
	if (read_checker == 0 && !(*preserved_line)[0])
	{
		free_and_nullify(*preserved_line);
		return (NULL);
	}
	*line = retrieve_line(preserved_line);
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*preserved_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (!preserved_line)
		preserved_line = NULL;
	line = handle_line(fd, &buffer, &preserved_line, &line);
	free_and_nullify(buffer);
	if (!line)
		preserved_line = NULL;
	return (line);
}
