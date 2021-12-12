/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 04:15:00 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/11 17:17:58 by jakira-p         ###   ########.fr       */
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
	char	*map_chunk;
	int		is_valid;
	int		height;
	int		width;
	int		enclosing_walls;
	int		walls;
	int		collectibles;
	int		start;
	int		exit;
	int		empty_spaces;
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
	t_map		*map;
}	t_game;

#endif