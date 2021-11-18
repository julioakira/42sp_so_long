/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:59:40 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/13 02:19:11 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;
	char	*s1_cpy;
	char	*s2_cpy;

	idx = 0;
	s1_cpy = (char *)s1;
	s2_cpy = (char *)s2;
	while (idx < n)
	{
		if (s1_cpy[idx] != s2_cpy[idx])
			return ((unsigned char)s1_cpy[idx] - (unsigned char)s2_cpy[idx]);
		idx++;
	}
	return (0);
}
