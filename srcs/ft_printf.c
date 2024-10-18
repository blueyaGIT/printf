/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:59:21 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 15:00:38 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
	implement stair-functions to cehck every possible *format type
	%c - done
	%s - done
	%p - done
	%d - done
	%i - done
	%u - done
	%x - done
	%X - done
	%% - done
	%mix - done
*/

static void	manual_switch(const char *format,
	int *printed_chars, va_list args, t_flags *flags)
{
	if (*format == 'c')
		*printed_chars += write(1,
				&(char){(unsigned char)va_arg(args, int)}, 1);
	else if (*format == 'p')
	{
		*printed_chars += write(1, "0x", 2);
		ft_print_pointer((uintptr_t)va_arg(args, void *), printed_chars);
	}
	else if (*format == 's')
		ft_print_string(va_arg(args, char *), printed_chars);
	else if (*format == 'd' || *format == 'i')
		*printed_chars += ft_print_number(va_arg(args, int), flags);
	else if (*format == 'u')
		*printed_chars += ft_print_number_unsigned(va_arg(args,
					unsigned int), flags);
	else if (*format == 'x')
		*printed_chars += ft_print_hex(va_arg(args, unsigned int), 0, flags);
	else if (*format == 'X')
		*printed_chars += ft_print_hex(va_arg(args, unsigned int), 1, flags);
	else if (*format == '%')
		*printed_chars += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		printed_chars;

	printed_chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format = parse_flags(format + 1, &flags);
			format = parse_width(format, &flags, args);
			format = parse_precision(format, &flags, args);
			manual_switch(format, &printed_chars, args, &flags);
		}
		else
			printed_chars += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
