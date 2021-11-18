/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:20:19 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/22 00:40:34 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	idx;
	size_t	s_idx;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	idx = 0;
	s_idx = 0;
	if (!result)
		return (NULL);
	while (s1[idx])
	{
		result[idx] = s1[idx];
		idx++;
	}
	while (s2[s_idx])
	{
		result[idx] = s2[s_idx];
		idx++;
		s_idx++;
	}
	result[idx] = '\0';
	return (result);
}
