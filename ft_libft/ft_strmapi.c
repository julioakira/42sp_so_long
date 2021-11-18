/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:49:04 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/13 02:13:21 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_cpy;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	s_cpy = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!s_cpy)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		s_cpy[idx] = f(idx, s[idx]);
		idx++;
	}
	return (s_cpy);
}
