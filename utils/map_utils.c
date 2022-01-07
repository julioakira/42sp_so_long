/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:29:14 by jakira-p          #+#    #+#             */
/*   Updated: 2022/01/07 04:30:02 by jakira-p         ###   ########.fr       */
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

static int	check_min_size(t_map *map)
{
	if (map->width < 5 && map->height < 3)
		return (1);
	return (0);
}

// 19/12 -> Now we need to actually validate the map
// Check again if it is rectangular?
// Check for smallest possible size?
void	is_valid_map(t_map *map)
{
	parse_map_elements(map);
	if (check_min_size(map) == 0)
	{
		free_map(map);
		exit_and_print(EINVAL, "Error: Map is smaller than the minimum size (5x3).\n");
	}
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
