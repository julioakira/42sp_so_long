/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:41:00 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/04 02:24:54 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_moves		*init_moves(void)
{
	t_moves	*new_moves;

	new_moves = ft_calloc(1, sizeof(t_moves));
	if (new_moves)
		return (new_moves);
	return (new_moves);
}

t_player	*init_player(void)
{
	t_player	*new_player;

	new_player = ft_calloc(1, sizeof(t_player));
	if (new_player)
		new_player->moves = init_moves();
	return (new_player);
}

t_game		*init_game(void)
{
	t_game	*new_game;

	new_game = ft_calloc(1, sizeof(t_game));
	if (!new_game)
		return (NULL);
	return (new_game);
}