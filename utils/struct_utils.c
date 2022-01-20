/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:25:34 by jakira-p          #+#    #+#             */
/*   Updated: 2022/01/20 04:02:34 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_mlx_img	*new_img(void)
{
	t_mlx_img	*img;

	img = ft_calloc(1, sizeof(t_mlx_img));
	img->addr = NULL;
	img->data = NULL;
	img->size_line = 3200;
	img->endian = 1;
	img->width = 64;
	img->height = 64;
	img->bpp = 32;
	return (img);
}

t_map	*new_map(char **map_lines)
{
	t_map	*new_map;

	new_map = ft_calloc(1, sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->map_lines = map_lines;
	new_map->is_valid = 0;
	new_map->height = 0;
	new_map->width = 0;
	new_map->walls = 0;
	new_map->enclosing_walls = 0;
	new_map->empty_spaces = 0;
	new_map->collectibles = 0;
	new_map->start = 0;
	new_map->exit = 0;
	return (new_map);
}
