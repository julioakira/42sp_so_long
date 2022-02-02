/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:46:26 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/02 05:13:05 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// Starts to count from zero
// If needed later, needs to adjust to start from 1, maybe?
// Receive player as argument maybe?
t_player	*spawn_player(t_game *game)
{
	t_player	*player;
	int			x_pos;
	int			y_pos;

	x_pos = 0;
	y_pos = 0;
	while (game->map->map_lines[y_pos][x_pos])
	{
		if (game->map->map_lines[y_pos][x_pos] == 'P')
			break ;
		if (x_pos == game->map->width - 1)
		{
			x_pos = 0;
			y_pos++;
		}
		x_pos++;
	}
	player = new_player(x_pos, y_pos);
	return (player);
}
