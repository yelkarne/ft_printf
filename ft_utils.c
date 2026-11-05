/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 23:35:45 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/06 01:46:23 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int *counter, char c)
{
	if (*counter == -1)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*counter = -1;
		return ;
	}
	(*counter)++;
}

void	ft_putstr(int *counter, char *s)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(counter, *s);
		s++;
	}
}

void	ft_putnbr_base(int *counter, unsigned long number, char *str, int base)
{
	if (number >= (unsigned long)base)
		ft_putnbr_base(counter, number / base, str, base);
	ft_putchar(counter, str[number % base]);
}

void	ft_putnbr(int *counter, int n)
{
	long int	number;

	number = n;
	if (number < 0)
	{
		number = number * -1;
		ft_putchar(counter, '-');
	}
	ft_putnbr_base(counter, number, "0123456789", 10);
}
