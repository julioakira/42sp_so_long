/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 05:02:41 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/06 05:11:33 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_and_nullify(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

static void	destroy_mlx_image(t_game *game, t_mlx_img *img)
{
	mlx_destroy_image(game->mlx, img->addr);
	free_and_nullify(img);
}

void	destroy_sprites(t_game *game)
{
	int	idx;

	idx = 0;
	while (game->sprites[idx])
	{
		destroy_mlx_image(game, game->sprites[idx]->sprite);
		free_and_nullify(game->sprites[idx]);
		idx++;
	}
	free_and_nullify(game->sprites);
}

void	destroy_player(t_game *game)
{
	if (game->player)
		free_and_nullify(game->player);
}
