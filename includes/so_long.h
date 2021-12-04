/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:25:09 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/04 02:37:25 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <mlx.h>
#include <libft.h>

// Check key hook events

typedef struct s_moves {
	int east;
	int	south;
	int	west;
	int	north;
}	t_moves;

// What constitutes a player?
// Add sprite later
typedef struct s_player {
	t_moves	*moves;
}	t_player;

typedef struct s_map {
	int	walls;
	int	collectibles;
	int	free_spaces;
}	t_map;

// Maybe we will have a sprite variable here?
typedef struct s_object {
	int	x_coord;
	int	y_coord;
}	t_object;

// 	t_player	player;
typedef struct s_game {
	void		*mlx;
	void		*window;
	int			move_count;
}	t_game;

// Struct utils
t_moves		*init_moves(void);
t_player	*init_player(void);
t_game		*init_game(void);

// Handlers
void	init_window(t_game *game);
int		key_hooks();

#endif
