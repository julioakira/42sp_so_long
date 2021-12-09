/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:25:09 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/08 23:07:02 by jakira-p         ###   ########.fr       */
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


// Utils
void	free_and_nullify(void *ptr);

// Handlers
int		handle_close(t_game *game);
int		key_hooks(int key_code, t_game *game);

#endif
