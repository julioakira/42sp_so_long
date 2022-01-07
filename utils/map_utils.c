/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:29:14 by jakira-p          #+#    #+#             */
/*   Updated: 2022/01/07 06:41:50 by jakira-p         ###   ########.fr       */
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

// smallest possible size (5x3)
static void	check_map_size(t_map *map)
{
	if (map->width < 5)
	{
		if (map->height <= 3)
		{
			free_map(map);
			exit_and_print(EINVAL,
				"Error: Map is smaller than the minimum size (5x3).\n");
		}
	}
	if (map->height < 3)
	{
		if (map->width <= 5)
		{
			free_map(map);
			exit_and_print(EINVAL,
				"Error: Map is smaller than the minimum size (5x3).\n");
		}
	}
}

static void	check_map_elements(t_map *map)
{
	if (map->exit != 1)
	{
		free_map(map);
		exit_and_print(EINVAL,
			"Error: Map must have exactly one exit.\n");
	}
	if (map->collectibles == 0)
	{
		free_map(map);
		exit_and_print(EINVAL,
			"Error: Map must have at least one collectible.\n");
	}
	if (map->start != 1)
	{
		free_map(map);
		exit_and_print(EINVAL,
			"Error: Map must have exactly player spawn.\n");
	}
}

static void	check_map_enclosing(t_map *map)
{
	if (measure_enclosing(map->width, map->height) != map->enclosing_walls)
	{
		free_map(map);
		exit_and_print(EINVAL,
			"Error: Map must be wall enclosed.\n");
	}
}

// Check again later if all validations are being applied
void	is_valid_map(t_map *map)
{
	parse_map_elements(map);
	check_map_size(map);
	check_map_elements(map);
	check_map_enclosing(map);
}
