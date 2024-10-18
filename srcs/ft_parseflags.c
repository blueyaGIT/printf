/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:33:01 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 15:46:53 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Helper function to initialize the t_flags structure.
void	init_flags(t_flags *flags)
{
	flags->left_align = false;
	flags->zero_pad = false;
	flags->alternate_form = false;
	flags->force_sign = false;
	flags->space = false;
	flags->field_width = 0;
	flags->precision = 0;
	flags->has_precision = false;
}

// Parse the flags and field width from the format string.
const char	*parse_flags(const char *format, t_flags *flags)
{
	init_flags(flags);
	while (*format)
	{
		if (*format == '-')
			flags->left_align = true;
		else if (*format == '0')
			flags->zero_pad = true;
		else if (*format == '#')
			flags->alternate_form = true;
		else if (*format == '+')
			flags->force_sign = true;
		else if (*format == ' ')
			flags->space = true;
		else
			break ;
		format++;
	}
	return (format);
}

const char	*parse_width(const char *format, t_flags *flags, va_list args)
{
	if (*format == '*')
	{
		flags->field_width = va_arg(args, int);
		if (flags->field_width < 0)
		{
			flags->left_align = true;
			flags->field_width = -flags->field_width;
		}
		format++;
	}
	else
	{
		while (*format >= '0' && *format <= '9')
		{
			flags->field_width = flags->field_width * 10 + (*format - '0');
			format++;
		}
	}
	return (format);
}

const char	*parse_precision(const char *format, t_flags *flags, va_list args)
{
	if (*format == '.')
	{
		flags->has_precision = true;
		format++;
		if (*format == '*')
		{
			flags->precision = va_arg(args, int);
			if (flags->precision < 0)
				flags->has_precision = false;
			format++;
		}
		else
		{
			flags->precision = 0;
			while (*format >= '0' && *format <= '9')
			{
				flags->precision = flags->precision * 10 + (*format - '0');
				format++;
			}
		}
	}
	return (format);
}
