/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_sprites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:16:44 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/01 04:29:08 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_sprite	**load_sprites(t_game *game)
{
	t_sprite	**sprites;

	sprites = ft_calloc(6, sizeof(t_sprite *));
	sprites[0] = load_player(game);
	sprites[1] = load_collectible(game);
	sprites[2] = load_wall(game);
	sprites[3] = load_exit(game);
	sprites[4] = load_floor(game);
	sprites[5] = NULL;
	game->sprites = sprites;
	return (sprites);
}

void	*select_sprite(t_sprite **sprites, char element)
{
	if (element == 'P')
		return (sprites[0]->sprite->addr);
	if (element == 'C')
		return (sprites[1]->sprite->addr);
	if (element == '1')
		return (sprites[2]->sprite->addr);
	if (element == 'E')
		return (sprites[3]->sprite->addr);
	else
		return (sprites[4]->sprite->addr);
}

void	load_map_sprites(t_game *game, t_map *map)
{
	int			idx;
	int			l_idx;

	idx = 0;
	l_idx = 0;
	load_sprites(game);
	while (l_idx < map->height)
	{
		while (idx < map->width)
		{
			mlx_put_image_to_window(
				game->mlx,
				game->window,
				select_sprite(game->sprites, map->map_lines[l_idx][idx]),
				64 * idx + 1,
				64 * l_idx + 1
				);
				idx++;
		}
		idx = 0;
		l_idx++;
	}
}
