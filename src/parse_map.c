/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:27:04 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/18 03:55:03 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// Possible characters
//	0 -> empty space
//	1 -> wall
//	C -> collectible
//	E -> exit
//	P -> player starting position

int	is_valid_extension(char *map_path)
{
	size_t	path_len;

	path_len = ft_strlen(map_path);
	if (path_len == 0 || path_len < 4)
		exit_and_print(EINVAL, "Error: Invalid map path.\n");
	if (map_path[path_len - 1] == 'r'
		&& map_path[path_len - 2] == 'e'
		&& map_path[path_len - 3] == 'b'
		&& map_path[path_len - 4] == '.')
		return (1);
	else
		exit_and_print(EINVAL, "Error: Invalid map extension.\n");
	return (0);
}

// I can read all at once and then
// split with ft_split
static char	**read_map(char *filename)
{
	char	*map_read;
	char	*tmp;
	int		fd;
	char	*holder;
	char	**split_map;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_and_print(EINVAL, "Error: Failed to open map file.\n");
	map_read = ft_calloc(1, 1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		holder = map_read;
		map_read = ft_strjoin(holder, tmp);
		free_and_nullify(tmp);
		free_and_nullify(holder);
	}
	split_map = ft_split(map_read, '\n');
	free_and_nullify(map_read);
	close(fd);
	return (split_map);
}

t_map	*retrieve_map(char *filename)
{
	t_map	*map;
	char	**split_map;

	split_map = read_map(filename);
	map = new_map(split_map);
	return (map);
}
