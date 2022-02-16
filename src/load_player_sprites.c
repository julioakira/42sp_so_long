/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:42:28 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/16 04:15:30 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_sprite	*load_player_east(t_game *game)
{
	t_sprite	*player;

	player = sprite_from_img(game, PLAYER_SPRITE_EAST, 'P');
	return (player);
}

t_sprite	*load_player_south(t_game *game)
{
	t_sprite	*player;

	player = sprite_from_img(game, PLAYER_SPRITE_SOUTH, 'P');
	return (player);
}

t_sprite	*load_player_west(t_game *game)
{
	t_sprite	*player;

	player = sprite_from_img(game, PLAYER_SPRITE_WEST, 'P');
	return (player);
}

t_sprite	*load_player_north(t_game *game)
{
	t_sprite	*player;

	player = sprite_from_img(game, PLAYER_SPRITE_NORTH, 'P');
	return (player);
}
