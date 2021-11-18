/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:48:40 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/21 05:58:54 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If needle length == 0 haystack is returned.
// If needle does not occur on haystack, NULL is returned.
// Otherwise, a pointer to the first characters of the
// first occurence of needle is returned

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	n_len;
	size_t	h_len;

	n_len = ft_strlen(needle);
	h_len = ft_strlen(haystack);
	if (!n_len)
		return ((char *) haystack);
	if (!h_len || !len)
		return (NULL);
	if (h_len < n_len)
		return (NULL);
	idx = 0;
	while (idx <= len - n_len)
	{
		if ((*haystack == *needle)
			&& (!ft_strncmp(haystack, needle, n_len)))
			return ((char *)haystack);
		haystack++;
		idx++;
	}
	return (NULL);
}
