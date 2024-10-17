/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:59:21 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/17 11:20:09 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
	implement stair-functions to cehck every possible *format type
	%c - done
	%s - done
	%p - done
	%d - done
	%i - 
	%u - 
	%x - 
	%X - 
	%% - 
	%mix - 
*/

static void	manual_switch(const char *format, int *printed_chars, va_list args)
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
	else if (*format == 'i' || *format == 'd')
		ft_print_number(va_arg(args, int), printed_chars);
}

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
			manual_switch(format, &printed_chars, args);
		}
		else
			printed_chars += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
