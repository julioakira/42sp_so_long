/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:25:09 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/19 03:36:29 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <libft.h>
#include <errno.h>
#include <fcntl.h>
#include "constants.h"
#include "structs.h"
// Remove later
#include <stdio.h>

// Check key hook events

// Initializers
void	new_game(t_game *game);
void	init_window(t_game *game);

// get_next_line
char	*get_next_line(int fd);

// Pointer Utils
void	free_and_nullify(void *ptr);

// Map Utils
int		open_map_file(char *filename);
int		is_valid_extension(char *map_path);
void	is_valid_map(t_map *map);

// Map Parsing
t_map	*retrieve_map(char *filename);
void	parse_map_elements(t_map *map);
void	free_map(t_map *map);

// Line Parsing Utils
void	validate_first_last_lines(t_map *map, char *line);
void	validate_middle_lines(t_map *map, char *line);

// Struct utils
t_map	*new_map(char **map_lines);

// Handlers
int		handle_close(t_game *game);
int		key_hooks(int key_code, t_game *game);

// Error utils
void	exit_and_print(int err_code, char *message);

#endif
