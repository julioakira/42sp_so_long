/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:28:39 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/09 00:22:33 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

static void	eval_map_path(int argc)
{
	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr_fd("You need to provide a map\n", 1);
		else if (argc > 2)
			ft_putstr_fd("Too many arguments\n", 1);
		exit(EINVAL);
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
	printf("Argv: %s\n", argv[1]);
	new_game(&game);
	return (1);
}
