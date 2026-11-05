/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 03:09:50 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/06 01:48:59 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conv	g_table[] = {
{'c', handler_c},
{'s', handler_s},
{'%', handler_percent},
{'d', handler_d},
{'i', handler_d},
{'u', handler_u},
{'x', handler_x},
{'X', handler_ux},
{'p', handler_p},
{0, NULL}
};

static void	dispatch(char spec, va_list *ap, int *counter)
{
	int	i;

	i = 0;
	while (g_table[i].handler)
	{
		if (g_table[i].specifier == spec)
		{
			g_table[i].handler(ap, counter);
			return ;
		}
		i++;
	}
	ft_putchar(counter, '%');
	ft_putchar(counter, spec);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	if (!format)
		return (-1);
	counter = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				va_end(ap);
				return (-1);
			}
			dispatch(*format, &ap, &counter);
		}
		else
			ft_putchar(&counter, *format);
		format++;
	}
	va_end(ap);
	return (counter);
}
