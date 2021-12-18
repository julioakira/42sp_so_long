/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:20:19 by jakira-p          #+#    #+#             */
/*   Updated: 2021/12/18 03:51:17 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*secondary;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	while (s2 && s2[s2_len])
		s2_len++;
	result = ft_calloc(s1_len + s2_len + 1, 1);
	if (result)
	{
		secondary = result;
		while (s1 && *s1)
			*secondary++ = *s1++;
		while (s2 && *s2)
			*secondary++ = *s2++;
		*secondary = 0;
		return (result);
	}
	return (NULL);
}
