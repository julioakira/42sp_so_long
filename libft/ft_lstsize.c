/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 03:40:55 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/18 01:18:07 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	if (!lst)
		return (0);
	size = 0;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	if (tmp->next == NULL)
		size++;
	return (size);
}
