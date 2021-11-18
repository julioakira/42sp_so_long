/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:06:13 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 03:22:14 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int n);
static char	*to_str(char *str, unsigned int n, int len);

static int	digit_counter(int n)
{
	int	r;
	int	counter;

	r = n;
	counter = !n;
	if (n < 0)
	{
		r *= (-1);
		counter++;
	}
	if (n > 0 && n < 10)
		return (1);
	while (r)
	{
		r /= 10;
		counter++;
	}
	return (counter);
}

static char	*to_str(char *str, unsigned int n, int len)
{
	while (n > 0)
	{
		str[len--] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				idx;
	unsigned int	nbr;
	int				n_digits;

	n_digits = digit_counter(n);
	result = (char *)ft_calloc(n_digits + 1, sizeof(char));
	idx = 0;
	if (!result)
		return (NULL);
	result[n_digits--] = '\0';
	if (n == 0)
	{
		result[idx++] = '0';
		return (result);
	}
	else if (n < 0)
	{
		nbr = -n;
		result[idx++] = '-';
	}
	else
		nbr = n;
	result = to_str(result, nbr, n_digits);
	return (result);
}
