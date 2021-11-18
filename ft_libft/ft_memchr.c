/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:51:39 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/13 02:19:26 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	idx;
	char	*ptr;

	ptr = (char *)s;
	idx = 0;
	while (idx < n)
	{
		if ((unsigned char) ptr[idx] == (unsigned char) c)
			return (ptr + idx);
		idx++;
	}
	return (NULL);
}
