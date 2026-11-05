/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 23:30:29 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/06 01:46:10 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handler_d(va_list *ap, int *counter)
{
	int	d;

	d = va_arg(*ap, int);
	ft_putnbr(counter, d);
}

void	handler_u(va_list *ap, int *counter)
{
	unsigned int	u;

	u = va_arg(*ap, unsigned int);
	ft_putnbr_base(counter, u, "0123456789", 10);
}

void	handler_x(va_list *ap, int *counter)
{
	unsigned int	x;

	x = va_arg(*ap, unsigned int);
	ft_putnbr_base(counter, x, "0123456789abcdef", 16);
}

void	handler_ux(va_list *ap, int *counter)
{
	unsigned int	ux;

	ux = va_arg(*ap, unsigned int);
	ft_putnbr_base(counter, ux, "0123456789ABCDEF", 16);
}

void	handler_p(va_list *ap, int *counter)
{
	void	*p;

	p = va_arg(*ap, void *);
	if (p == NULL)
		ft_putstr(counter, "(nil)");
	else
	{
		ft_putstr(counter, "0x");
		ft_putnbr_base(counter, (unsigned long)p, "0123456789abcdef", 16);
	}
}
