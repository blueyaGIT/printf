/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:59:21 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/15 12:58:43 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
	implement stair-functions to cehck every possible *format type
*/

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
			if (*format == 'd')
				printed_chars += print_number(va_arg(args, int), &flags);
			else if (*format == 'c')
				printed_chars += write(1,
						&(char){(unsigned char)va_arg(args, int)}, 1);
		}
		else
			printed_chars += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
