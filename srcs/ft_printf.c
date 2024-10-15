/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:59:21 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/15 10:24:40 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	printed_chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 'c')
				printed_chars += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				printed_chars += ft_putstr(va_arg(args, char *));
		}
		else
		{
			printed_chars += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
