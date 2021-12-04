/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:16:11 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/04 02:38:41 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>
// Segfaults when Esc is pressed
int	key_hooks(int key_code, t_game *game)
{
	if (key_code == 0xFF1B)
		mlx_destroy_window(game->mlx, game->window);
	else
		printf("Key pressed!\n");
	return (1);
}