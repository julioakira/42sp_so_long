/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 02:34:22 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/08 22:06:36 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

// destroy functions segfaults
int	handle_close(t_game *game)
{
	if (game->mlx)
	{
		mlx_clear_window(game->mlx, game->window);
		printf("passing here\n");
		mlx_destroy_window(game->mlx, game->window);
		printf("does not pass here\n");
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}