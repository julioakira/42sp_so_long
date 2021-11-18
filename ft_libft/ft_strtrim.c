/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:21:24 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/14 03:07:48 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_char_set(char const *set, char a);

static int	is_in_char_set(char const *set, char a)
{
	while (*set)
	{
		if (*set == a)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		f_idx;
	int		b_idx;
	char	*result;

	f_idx = 0;
	b_idx = ft_strlen(s1) - 1;
	while (is_in_char_set(set, s1[f_idx]))
		f_idx++;
	while (is_in_char_set(set, s1[b_idx]))
		b_idx--;
	result = ft_substr(s1, f_idx, b_idx - f_idx + 1);
	return (result);
}
