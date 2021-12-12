/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:28:39 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/11 19:52:59 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	eval_map_path(int argc)
{
	if (argc != 2)
	{
		if (argc == 1)
			exit_and_print(EINVAL, "You need to provide a map\n");
		else if (argc > 2)
			exit_and_print(EINVAL, "Too many arguments\n");
	}
}

// Dummy using argv just to avoid errors
// Now we need to evaluate the map itself
int	main(int argc, char **argv)
{
	t_game	game;

	game.mlx = NULL;
	game.window = NULL;
	eval_map_path(argc);
	is_valid_extension(argv[1]);
	new_game(&game);
	return (1);
}
