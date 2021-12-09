/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:29:14 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/09 04:30:28 by jakira-p         ###   ########.fr       */
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

static int	is_wall_enclosed(t_map *map)
{
	int	walls;

	walls = measure_enclosing(map->width, map->height);
	if (map->enclosing_walls != walls)
		return (1);
	return (0);
}

// 1 -> invalid map
// 0 -> valid map
int	is_valid_map(t_map *map)
{
	if (map->exit == 0
		|| map->collectibles == 0
		|| map->start == 0
		|| map->width <= map->height
		|| is_wall_enclosed(map) != 0)
		return (1);
	return (0);
}
