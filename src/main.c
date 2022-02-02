/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:28:39 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/02 02:48:28 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	eval_map_path(int argc)
{
	if (argc != 2)
	{
		if (argc == 1)
			exit_and_print(EINVAL, "You need to provide a map.\n");
		else if (argc > 2)
			exit_and_print(EINVAL, "Too many arguments.\n");
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.mlx = NULL;
	game.window = NULL;
	eval_map_path(argc);
	is_valid_extension(argv[1]);
	game.map = retrieve_map(argv[1]);
	is_valid_map(game.map);
	new_game(&game, game.map);
	return (1);
}
