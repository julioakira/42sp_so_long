/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 04:19:25 by jakira-p          #+#    #+#             */
/*   Updated: 2022/01/20 03:26:05 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_sprite	*load_player(t_game *game)
{
	t_sprite	*player;

	player = sprite_from_img(game, PLAYER_SPRITE, 'P');
	return (player);
}

t_sprite	*load_collectible(t_game *game)
{
	t_sprite	*collectible;

	collectible = sprite_from_img(game, COLLECTIBLE_SPRITE, 'C');
	return (collectible);
}

t_sprite	*load_wall(t_game *game)
{
	t_sprite	*wall;

	wall = sprite_from_img(game, WALL_SPRITE, '1');
	return (wall);
}

t_sprite	*load_exit(t_game *game)
{
	t_sprite	*exit;

	exit = sprite_from_img(game, EXIT_SPRITE, 'E');
	return (exit);
}

t_sprite	*load_floor(t_game *game)
{
	t_sprite	*exit;

	exit = sprite_from_img(game, FLOOR_SPRITE, '0');
	return (exit);
}
