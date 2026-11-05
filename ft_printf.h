/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 03:38:21 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/06 01:46:16 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_conv
{
	char	specifier;
	void	(*handler)(va_list *ap, int *counter);
}			t_conv;

int			ft_printf(const char *format, ...);
void		ft_putchar(int *counter, char c);
void		ft_putstr(int *counter, char *s);
void		ft_putnbr_base(int *counter, unsigned long number, char *str,
				int base);
void		ft_putnbr(int *counter, int n);
void		handler_c(va_list *ap, int *counter);
void		handler_s(va_list *ap, int *counter);
void		handler_percent(va_list *ap, int *counter);
void		handler_d(va_list *ap, int *counter);
void		handler_u(va_list *ap, int *counter);
void		handler_x(va_list *ap, int *counter);
void		handler_ux(va_list *ap, int *counter);
void		handler_p(va_list *ap, int *counter);

#endif
