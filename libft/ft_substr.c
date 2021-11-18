/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:19:05 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/20 02:29:53 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_smaller(size_t a, size_t b);

static size_t	get_smaller(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_piece_len;
	char	*substr;
	size_t	idx;
	size_t	smaller;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	idx = 0;
	s_piece_len = ft_strlen(&s[start]);
	smaller = get_smaller(len, s_piece_len);
	substr = ft_calloc(smaller + 1, sizeof (char));
	if (!substr)
		return (NULL);
	while (idx < len && s[start + idx])
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	return (substr);
}
