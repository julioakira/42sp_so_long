/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:16:41 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/20 02:28:24 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s);
	dup = malloc(s_len + 1);
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (ptr);
}
