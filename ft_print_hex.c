/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:31:07 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 18:53:20 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen_hex(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static void	ft_putnbr_hex(unsigned int num, int uppercase)
{
	const char	*base_lower;
	const char	*base_upper;
	const char	*base;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (uppercase)
		base = base_upper;
	else
		base = base_lower;
	if (num >= 16)
		ft_putnbr_hex(num / 16, uppercase);
	write(1, &base[num % 16], 1);
}

static void	inside_if(int padding, int printed, t_flags *flags)
{
	while (padding-- > 0)
	{
		if (flags->zero_pad)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		printed++;
	}
}

int	ft_print_hex(unsigned int num, int uppercase, t_flags *flags)
{
	int	len;
	int	padding;
	int	printed;

	len = ft_numlen_hex(num);
	padding = flags->field_width - len;
	printed = 0;
	if (!flags->left_align && padding > 0)
	{
		inside_if(padding, printed, flags);
	}
	ft_putnbr_hex(num, uppercase);
	printed += len;
	if (flags->left_align && padding > 0)
	{
		while (padding-- > 0)
		{
			write(1, " ", 1);
			printed++;
		}
	}
	return (printed);
}
