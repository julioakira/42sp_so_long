/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:27:04 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/11 19:52:59 by jakira-p         ###   ########.fr       */
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
		exit_and_print(EINVAL, "Error: Invalid map path\n");
	if (map_path[path_len - 1] == 'r'
		&& map_path[path_len - 2] == 'e'
		&& map_path[path_len - 3] == 'b'
		&& map_path[path_len - 4] == '.')
		return (1);
	else
		exit_and_print(EINVAL, "Error: Invalid map extension.\n");
	return (0);
}

t_map	*parse_map(char *map_chunk)
{
	t_map	*map;

	map = new_map(map_chunk);
	return (map);
}
