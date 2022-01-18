/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 04:19:25 by jakira-p          #+#    #+#             */
/*   Updated: 2022/01/17 23:59:58 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_sprite	*load_sprite(t_game *game, char *file_path, char type)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	sprite->type = type;
	sprite->sprite = ft_calloc(1, sizeof(t_mlx_img *));
	sprite->sprite[0] = img_from_file(game->mlx, file_path);
	sprite->sprite[1] = NULL;
	return (sprite);
}
