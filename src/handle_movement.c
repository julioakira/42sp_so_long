/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:46:26 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/03 05:26:40 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// map[y_pos][x_pos]
// x_pos -> height/vertical movement
// y_pos -> width/horizontal movement
int	move_player_west(t_game *game)
{
	if (game->map->map_lines[game->player->y_pos][game->player->x_pos - 1] == 'C')
		game->player->collectible_count++;
	game->map->map_lines[game->player->y_pos][game->player->x_pos] = '0';
	game->player->x_pos--;
	game->map->map_lines[game->player->y_pos][game->player->x_pos] = 'P';
	game->player->steps_count++;
	overlay_game_sprites(game);
	return (0);
}

int	move_player_east(t_game *game)
{
	if (game->map->map_lines[game->player->y_pos][game->player->x_pos + 1] == 'C')
		game->player->collectible_count++;
	game->map->map_lines[game->player->y_pos][game->player->x_pos] = '0';
	game->player->x_pos++;
	game->map->map_lines[game->player->y_pos][game->player->x_pos] = 'P';
	game->player->steps_count++;
	overlay_game_sprites(game);
	return (0);
}

int	move_player_south(t_game *game)
{
	if (game->map->map_lines[game->player->y_pos + 1][game->player->x_pos] == 'C')
		game->player->collectible_count++;
	game->map->map_lines[game->player->y_pos][game->player->x_pos] = '0';
	game->player->y_pos++;
	game->map->map_lines[game->player->y_pos][game->player->x_pos] = 'P';
	game->player->steps_count++;
	overlay_game_sprites(game);
	return (0);
}

int	move_player_north(t_game *game)
{
	if (game->map->map_lines[game->player->y_pos - 1][game->player->x_pos] == 'C')
		game->player->collectible_count++;
	game->map->map_lines[game->player->y_pos][game->player->x_pos] = '0';
	game->player->y_pos--;
	game->map->map_lines[game->player->y_pos][game->player->x_pos] = 'P';
	game->player->steps_count++;
	overlay_game_sprites(game);
	return (0);
}

int	register_movement(t_game *game, int key)
{
	if ((key == EAST)
		&& game->map->map_lines[game->player->y_pos][game->player->x_pos + 1] == 'E')
		check_collectibles(game);
	else if ((key == EAST)
		&& game->map->map_lines[game->player->y_pos][game->player->x_pos + 1] != '1')
		move_player_east(game);
	if ((key == SOUTH)
		&& game->map->map_lines[game->player->y_pos + 1][game->player->x_pos] == 'E')
		check_collectibles(game);
	else if ((key == SOUTH)
		&& game->map->map_lines[game->player->y_pos + 1][game->player->x_pos] != '1')
		move_player_south(game);
	if ((key == WEST)
		&& game->map->map_lines[game->player->y_pos][game->player->x_pos - 1] == 'E')
		check_collectibles(game);
	else if ((key == WEST)
		&& game->map->map_lines[game->player->y_pos][game->player->x_pos - 1] != '1')
		move_player_west(game);
	if ((key == NORTH)
		&& game->map->map_lines[game->player->y_pos - 1][game->player->x_pos] == 'E')
		check_collectibles(game);
	else if ((key == NORTH)
		&& game->map->map_lines[game->player->y_pos - 1][game->player->x_pos] != '1')
		move_player_north(game);
	return (0);
}