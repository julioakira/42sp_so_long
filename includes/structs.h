/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 04:15:00 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/07 04:27:35 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

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
// Needs to add t_map map and int move_count
typedef struct s_game {
	void		*mlx;
	void		*window;
}	t_game;

#endif