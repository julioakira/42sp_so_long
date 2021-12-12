/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:28:22 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/11 21:22:03 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// Allowed characters -> 01CEP
// 0 -> Empty space
// 1 -> Wall
// C -> Collectible
// P -> Player spawn
// E -> Map Exit
static void	is_valid_character(char c)
{
	int	is_valid;

	is_valid = ft_strchr("01CEP", c) == NULL;
	if (is_valid == 1)
		exit_and_print(EINVAL, "Error: Invalid map character\n");
}

static void	count_character(t_map *map, char c)
{
	if (c == '0')
		map->empty_spaces++;
	if (c == '1')
		map->walls++;
	if (c == 'C')
		map->collectibles++;
	if (c == 'P')
		map->start++;
	if (c == 'E')
		map->exit++;
}

// Might not need to loop twice to validate characters and map.
static void	validate_and_count_characters(t_map *map, char *line)
{
	size_t	idx;
	size_t	line_len;

	idx = 0;
	line_len = ft_strlen(line);
	while (line[idx])
	{
		if (idx == 0 || idx == line_len)
		{
			if (line[idx] != '1')
				exit_and_print(EINVAL, "Error: Map must be wall enclosed\n");
			else
			{
				map->enclosing_walls++;
				map->walls++;
			}
		}
		else
		{
			is_valid_character(line[idx]);
			count_character(map, line[idx]);
		}
		idx++;
	}
}

void	validate_first_last_lines(t_map *map, char *line)
{
	while (*line)
	{
		if (*line != 1)
			exit_and_print(EINVAL, "Error: Map must be wall enclosed\n");
		line++;
		map->enclosing_walls++;
		map->walls++;
		map->height++;
		map->width = ft_strlen(line);
	}
}

void	validate_middle_lines(t_map *map, char *line)
{
	if (line == NULL || ft_strlen(line) == 0)
		exit_and_print(EINVAL, "Error: Map must be rectangular\n");
	validate_and_count_characters(map, line);
}
