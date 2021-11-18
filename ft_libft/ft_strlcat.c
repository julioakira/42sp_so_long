/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 00:53:25 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/28 03:28:22 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dstsize needs to have space for NUL
// ft_strlcat needs to NUL terminate, even if
// that means copying src - 1 characters
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_idx;
	size_t	src_len;
	size_t	dst_len;

	src_idx = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[src_idx] != '\0' && dstsize > dst_len + 1)
	{
		dst[dst_len] = src[src_idx];
		src_idx++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (dst_len + ft_strlen(&src[src_idx]));
}
