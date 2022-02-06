/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:58:48 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/06 05:13:00 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_collectibles(t_game *game)
{
	int	c;

	c = game->map->collectibles - game->player->collectible_count;
	if (game->player->collectible_count == game->map->collectibles)
	{
		ft_putstr_fd("Congratz, you won!\n", 1);
		handle_close(game);
	}
	else
	{
		ft_putstr_fd("You still have ", 1);
		ft_putnbr_fd(c, 1);
		ft_putstr_fd(" keys left to collect.\n", 1);
	}
}
