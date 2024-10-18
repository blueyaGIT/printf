/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:43:43 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 19:01:16 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	replace_if(int len, int padding,
			int space_padding, t_flags *flags)
{
	int	printed;

	printed = 0;
	if (!flags->left_align && flags->field_width > len + padding)
	{
		space_padding = flags->field_width - (len + padding);
		while (space_padding-- > 0)
			if (flags->zero_pad)
				printed += write(1, "0", 1);
		else
			printed += write(1, " ", 1);
	}
	return (printed);
}

int	ft_print_number(int num, t_flags *flags)
{
	int	len;
	int	padding;
	int	printed;
	int	space_padding;

	printed = 0;
	space_padding = 0;
	len = ft_numlen(num);
	if (flags->has_precision && flags->precision > len)
		padding = flags->precision - len;
	else
		padding = 0;
	printed = replace_if(len, padding, space_padding, flags);
	while (padding-- > 0)
		printed += write(1, "0", 1);
	ft_putnbr(num);
	printed += len;
	if (flags->left_align && flags->field_width > len + padding)
	{
		space_padding = flags->field_width - (len + padding);
		while (space_padding-- > 0)
			printed += write(1, " ", 1);
	}
	return (printed);
}

static void	replace_if_unsigned(t_flags *flags, char padding_char,
		int padding, int printed_chars)
{
	if (!flags->left_align && padding > 0)
	{
		while (padding > 0)
		{
			write(1, &padding_char, 1);
			printed_chars++;
			padding--;
		}
	}
}

int	ft_print_number_unsigned(unsigned int num, t_flags *flags)
{
	char	buffer[50];
	int		num_len;
	int		padding;
	int		printed_chars;
	char	padding_char;

	ft_utoa(num, buffer);
	num_len = ft_strlen(buffer);
	printed_chars = 0;
	if (flags->zero_pad && !flags->left_align)
		padding_char = '0';
	else
		padding_char = ' ';
	padding = flags->field_width - num_len;
	replace_if_unsigned(flags, padding_char, padding, printed_chars);
	printed_chars += write(1, buffer, num_len);
	if (flags->left_align && padding > 0)
	{
		while (padding-- > 0)
		{
			write(1, " ", 1);
			printed_chars++;
		}
	}
	return (printed_chars);
}
