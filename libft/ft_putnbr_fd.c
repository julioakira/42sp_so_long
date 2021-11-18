/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:52:31 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/13 17:25:48 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_length(int n);
static int		power(int base, int exponent);
static void		get_digit(int num, int n, int fd);
static void		ft_min_int(int fd);

static int	ft_get_length(int n)
{
	int	length;

	length = !n;
	while (n)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

static int	power(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent > 0)
	{
		result = result * base;
		exponent--;
	}
	return (result);
}

static void	get_digit(int num, int pos, int fd)
{
	int	result;

	result = num / power(10, pos);
	result = result % 10;
	result = result + '0';
	write(fd, &result, 1);
}

static void	ft_min_int(int fd)
{
	write(fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	length;
	int	counter;

	counter = 1;
	length = ft_get_length(n);
	if (n == -2147483648)
		ft_min_int(fd);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		while (counter <= length)
		{
			get_digit(n, length - counter, fd);
			counter++;
		}
	}
	else if (n >= 0)
	{
		while (counter <= length)
		{
			get_digit(n, length - counter, fd);
			counter++;
		}
	}
}
