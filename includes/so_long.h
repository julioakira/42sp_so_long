/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:25:09 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/11 20:24:01 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#include <mlx.h>
#include <libft.h>
#include <errno.h>
#include "constants.h"
#include "structs.h"

// Check key hook events

// Initializers
void	new_game(t_game *game);
void	init_window(t_game *game);

// get_next_line
char	*get_next_line(int fd);

// Pointer Utils
void	free_and_nullify(void *ptr);

// Map Utils
int		is_valid_extension(char *map_path);
int		is_valid_map(t_map *map);

// Line Parsing Utils
void	validate_first_last_lines(t_map *map, char *line);
void	validate_middle_lines(t_map *map, char *line);

// Struct utils
t_map	*new_map(char *map_chunk);

// Handlers
int		handle_close(t_game *game);
int		key_hooks(int key_code, t_game *game);

// Error utils
void	exit_and_print(int err_code, char *message);

#endif
