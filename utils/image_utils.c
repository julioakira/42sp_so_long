/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:00:29 by jakira-p          #+#    #+#             */
/*   Updated: 2022/04/12 05:22:05 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_mlx_img	*img_from_file(void *mlx, char *img_path)
{
	t_mlx_img	*img;

	img = new_img();
	img->addr = mlx_xpm_file_to_image(
			mlx,
			img_path,
			&img->width,
			&img->height);
	img->data = mlx_get_data_addr(
			mlx,
			&img->bpp,
			&img->size_line,
			&img->endian);
	return (img);
}

t_sprite	*sprite_from_img(t_game *game, char *file_path, char type)
{
	t_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_sprite));
	sprite->type = type;
	sprite->sprite = img_from_file(game->mlx, file_path);
	return (sprite);
}

int	overlay_game_sprites(t_game *game)
{
	int	idx;
	int	l_idx;

	idx = 0;
	l_idx = 0;
	while (l_idx < game->map->height)
	{
		while (idx < game->map->width)
		{
			mlx_put_image_to_window(
				game->mlx,
				game->window,
				select_sprite(game->sprites, game->map->map_lines[l_idx][idx],
					game->player->last_movement),
				64 * idx + 1,
				64 * l_idx + 1
				);
				idx++;
		}
		idx = 0;
		l_idx++;
	}
	write_steps_count(game);
	return (0);
}

int	game_tick(t_game *game)
{
	int	tick_rate;

	tick_rate = 10000;

	if (game->tick % tick_rate == 1000)
	{
		overlay_game_sprites(game);
	}
	game->tick++;
	return (0);
}