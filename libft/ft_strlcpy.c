/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 02:40:31 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/28 02:45:27 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	char	*c_dst;

	idx = 0;
	c_dst = dst;
	if (dstsize > 0)
	{
		while (idx < dstsize - 1)
		{
			if (src[idx] == '\0')
				break ;
			c_dst[idx] = src[idx];
			idx++;
		}
		c_dst[idx] = '\0';
	}
	return (ft_strlen(src));
}
