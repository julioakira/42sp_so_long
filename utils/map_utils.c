/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:29:14 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/19 05:28:58 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// surr walls = (2 * width) + ((height - 2) * 2)
static int	measure_enclosing(int width, int height)
{
	int	walls;

	walls = (2 * width) + ((height - 2) * 2);
	return (walls);
}

// 19/12 -> Now we need to actually validate the map
// Check again if it is rectangular?
// Check for smallest possible size?
void	is_valid_map(t_map *map)
{
	parse_map_elements(map);
	if (map->exit != 1)
	{
		free_map(map);
		exit_and_print(EINVAL, "Error: Map must have at least one exit point.\n");
	}
	if (map->collectibles == 0)
	{
		free_map(map);
		exit_and_print(EINVAL, "Error: Map must have at least one collectible.\n");
	}
	if (map->start != 1)
	{
		free_map(map);
		exit_and_print(EINVAL, "Error: Map must have at least one starting point.\n");
	}
	if (measure_enclosing(map->width, map->height) != map->enclosing_walls)
	{
		free_map(map);
		exit_and_print(EINVAL, "Error: Map must be wall enclosed.\n");
	}
}
