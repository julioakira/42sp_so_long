/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:25:34 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/09 01:18:00 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_map	*new_map(char *map_chunk)
{
	t_map	*new_map;

	new_map = ft_calloc(1, sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->map_chunk = map_chunk;
	new_map->is_valid = 0;
	new_map->height = 0;
	new_map->width = 0;
	new_map->walls = 0;
	new_map->enclosing_walls = 0;
	new_map->collectibles = 0;
	new_map->start = 0;
	new_map->exit = 0;
	new_map->free_spaces = 0;
	return (new_map);
}