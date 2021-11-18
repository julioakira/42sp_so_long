/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 01:38:56 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/12 00:21:39 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to the last occurence of c in the string s.
// If c is not found in s, returns a null pointer.
char	*ft_strrchr(const char *s, int c)
{
	char	*s_cpy;
	int		s_len;

	s_cpy = (char *) s;
	s_len = 0;
	while (*s_cpy)
	{
		s_cpy++;
		s_len++;
	}
	while (s_len >= 0)
	{
		if (*s_cpy == (char) c)
			return ((char *)s_cpy);
		s_cpy--;
		s_len--;
	}
	return (0);
}
