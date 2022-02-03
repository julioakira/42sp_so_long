/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:12:53 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/03 04:13:01 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// Starts to count from zero
void	spawn_player(t_game *game)
{
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
	game->player = new_player(x_pos, y_pos);
}
