/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:58:48 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/03 05:14:16 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_collectibles(t_game *game)
{
	if (game->player->collectible_count == game->map->collectibles)
	{
		ft_putstr_fd("Congratz, you won!\n", 1);
		handle_close(game);
	}
	else
	{
		ft_putstr_fd("You need to collect all items before leaving!\n", 1);
	}
}