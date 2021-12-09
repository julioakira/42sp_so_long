/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:28:39 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/08 22:00:57 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// initialize game more cleanly
int main(void)
{
	t_game	game;

	game.mlx = NULL;
	game.window = NULL;

	new_game(&game);
	return (1);
}
