/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 03:28:39 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/06 01:46:05 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handler_c(va_list *ap, int *counter)
{
	char	c;

	c = (char)va_arg(*ap, int);
	ft_putchar(counter, c);
}

void	handler_s(va_list *ap, int *counter)
{
	char	*s;

	s = va_arg(*ap, char *);
	ft_putstr(counter, s);
}

void	handler_percent(va_list *ap, int *counter)
{
	(void)ap;
	ft_putchar(counter, '%');
}
