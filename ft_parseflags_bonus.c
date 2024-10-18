/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseflags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:18:11 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 18:53:20 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_flags(const char **str)
{
	int	value;

	value = 0;
	while (**str >= '0' && **str <= '9')
	{
		value = (value * 10) + (**str - '0');
		(*str)++;
	}
	return (value);
}

void	parse_flags_bonus(const char **format, t_flags *flags)
{
	while (**format == '-' || **format == '0' || **format == '+'
		|| **format == ' ' || **format == '#')
	{
		if (**format == '-')
			flags->left_align = 1;
		else if (**format == '0')
			flags->zero_pad = 1;
		else if (**format == '+')
			flags->plus_sign = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '#')
			flags->alternate_form = 1;
		(*format)++;
	}
	if (**format >= '0' && **format <= '9')
		flags->field_width = ft_atoi_flags(format);
	if (**format == '.')
	{
		(*format)++;
		flags->has_precision = 1;
		flags->precision = ft_atoi_flags(format);
	}
}
