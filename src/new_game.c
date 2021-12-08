/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 02:40:49 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/07 04:52:00 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// 1L << 2 -> ButtonPressMask
void	new_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	mlx_hook(game->window, 17, 1L << 2, handle_close, &game);
	mlx_key_hook(game->window, key_hooks, &game);
	mlx_loop(game->mlx);
}