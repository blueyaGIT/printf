/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:43:43 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 14:58:07 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#include "../ft_printf.h"

int	ft_numlen(int num)
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

int	ft_print_number_unsigned(unsigned int num, t_flags *flags)
{
	char	buffer[50];
	int		len;

	if (flags->has_precision)
		sprintf(buffer, "%.*u", flags->precision, num);
	else if (flags->zero_pad && !flags->left_align)
		sprintf(buffer, "%0*u", flags->field_width, num);
	else if (flags->left_align)
		sprintf(buffer, "%-*u", flags->field_width, num);
	else
		sprintf(buffer, "%u", num);
	len = write(1, buffer, strlen(buffer));
	return (len);
}
