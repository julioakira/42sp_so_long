/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 02:40:49 by jakira-p          #+#    #+#             */
/*   Updated: 2022/01/18 02:42:51 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// 1L << 2 -> ButtonPressMask
void	new_game(t_game *game, t_map *map)
{
	void	*sprite;
	void	*sprite2;
	int		height;
	int		width;

	height = 32;
	width = 32;
	game->mlx = mlx_init();
	game->window = mlx_new_window(
			game->mlx,
			map->width * 64,
			map->height * 64,
			WINDOW_TITLE
			);
	mlx_hook(game->window, 17, 1L << 2, handle_close, game);
	mlx_key_hook(game->window, key_hooks, game);
	// Testing sprites into window
	sprite = mlx_xpm_file_to_image(game->mlx, PLAYER_SPRITE, &width, &height);
	sprite2 = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE_SPRITE, &width, &height);
	mlx_put_image_to_window(game->mlx, game->window, sprite, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, sprite2, 64, 0);
	mlx_loop(game->mlx);
}
