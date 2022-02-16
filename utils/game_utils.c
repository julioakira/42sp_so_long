/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:58:48 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/16 04:03:18 by jakira-p         ###   ########.fr       */
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

void	write_steps_count(t_game *game)
{
	char	*joined;
	char	*steps_count;

	steps_count = ft_itoa(game->player->steps_count);
	joined = ft_strjoin("Movement Counter: ", steps_count);
	free(steps_count);
	mlx_string_put(game->mlx, game->window, 10, 20, 0x000, joined);
	free(joined);
}