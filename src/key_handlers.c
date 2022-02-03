/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:16:11 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/03 04:55:44 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// w -> 0x0077
// a -> 0x0061
// s -> 0x0073
// d -> 0x0064
// esc -> 0xFF1B
int	is_allowed_key(int key_code)
{
	if (key_code == NORTH || key_code == WEST
		|| key_code == SOUTH || key_code == EAST
		|| key_code == ESC)
		return (key_code);
	return (0);
}

// Valid movements go here and return key_code
// unless the key is not allowed
int	key_hooks(int key_code, t_game *game)
{
	if (!is_allowed_key(key_code))
		return (0);
	if (key_code == ESC)
		handle_close(game);
	else
		register_movement(game, key_code);
	return (0);
}
