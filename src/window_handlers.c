/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 02:05:53 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/04 02:37:40 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 800, 600, "Testing mlx");
	mlx_key_hook(game->window, key_hooks, &game);
	mlx_loop(game->mlx);
}