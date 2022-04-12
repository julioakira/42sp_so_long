/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 04:15:00 by jakira-p          #+#    #+#             */
/*   Updated: 2022/04/12 04:24:57 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// https://github.com/keuhdall/images_example
// https://qst0.github.io/ft_libgfx/man_mlx_new_image.html
typedef struct s_mlx_img {
	void	*addr;
	void	*data;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		bpp;
}	t_mlx_img;

typedef struct s_sprites {
	t_mlx_img	*sprite;
	char		type;
}	t_sprite;

// What constitutes a player?
// Besides position, what else do we need?
typedef struct s_player {
	int			x_pos;
	int			y_pos;
	char		last_movement;
	int			collectible_count;
	int			steps_count;
}	t_player;

typedef struct s_map {
	char	**map_lines;
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

// 	t_player	player;
// Needs to int move_count
typedef struct s_game {
	void		*mlx;
	int			tick;
	void		*window;
	t_map		*map;
	t_player	*player;
	t_sprite	**sprites;
}	t_game;

#endif