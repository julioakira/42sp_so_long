/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 05:04:39 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/16 04:15:48 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_sprite	**load_sprites(t_game *game)
{
	t_sprite	**sprites;

	sprites = ft_calloc(9, sizeof(t_sprite *));
	sprites[0] = load_player_east(game);
	sprites[1] = load_player_south(game);
	sprites[2] = load_player_west(game);
	sprites[3] = load_player_north(game);
	sprites[4] = load_collectible(game);
	sprites[5] = load_wall(game);
	sprites[6] = load_exit(game);
	sprites[7] = load_floor(game);
	sprites[8] = NULL;
	game->sprites = sprites;
	return (sprites);
}

void	*select_sprite(t_sprite **sprites, char element, char last_move)
{
	if (element == 'P' && last_move == 'E')
		return (sprites[0]->sprite->addr);
	if (element == 'P' && last_move == 'S')
		return (sprites[1]->sprite->addr);
	if (element == 'P' && last_move == 'W')
		return (sprites[2]->sprite->addr);
	if (element == 'P' && last_move == 'N')
		return (sprites[3]->sprite->addr);
	if (element == 'C')
		return (sprites[4]->sprite->addr);
	if (element == '1')
		return (sprites[5]->sprite->addr);
	if (element == 'E')
		return (sprites[6]->sprite->addr);
	else
		return (sprites[7]->sprite->addr);
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
				select_sprite(game->sprites, map->map_lines[l_idx][idx],
					game->player->last_movement),
				64 * idx + 1,
				64 * l_idx + 1
				);
				idx++;
		}
		idx = 0;
		l_idx++;
	}
}
