/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:00:29 by jakira-p          #+#    #+#             */
/*   Updated: 2022/01/20 04:02:59 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_mlx_img	*img_from_file(void *mlx, char *img_path)
{
	t_mlx_img	*img;
	// Initialize img struct with a function
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