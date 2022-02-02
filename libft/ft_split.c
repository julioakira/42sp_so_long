/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:47:52 by jakira-p          #+#    #+#             */
/*   Updated: 2022/02/02 02:32:32 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_pieces(char *str, char sep);
static void		split_string(char *str, char token, char **str_arr);

static size_t	count_pieces(char *str, char token)
{
	char		*str_cpy;
	size_t		counter;

	str_cpy = (char *)str;
	counter = 0;
	while (*str_cpy)
	{
		if (*str_cpy != token)
		{
			while (*str_cpy != token && *str_cpy)
				str_cpy++;
			counter++;
		}
		if (*str_cpy)
			str_cpy++;
	}
	return (counter);
}

static void	split_string(char *str, char token, char **str_arr)
{
	size_t	str_idx;
	size_t	arr_idx;

	arr_idx = 0;
	while (*str)
	{
		str_idx = 0;
		if (*str != token)
		{
			while (str[str_idx] != token && str[str_idx])
			{
				str_idx++;
			}
			str_arr[arr_idx++] = ft_substr(str, 0, str_idx);
			str += str_idx - 1;
		}
		if (*str)
			str++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	*s_cpy;
	char	**result;
	size_t	idx;

	result = NULL;
	if (s)
	{
		s_cpy = (char *) s;
		idx = count_pieces(s_cpy, c);
		result = (char **) ft_calloc(idx + 1, sizeof (char *));
		if (!result)
			return (NULL);
		split_string(s_cpy, c, result);
		result[idx] = NULL;
	}
	return (result);
}
