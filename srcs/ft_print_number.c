/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:43:43 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/17 13:14:45 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_number(int num, t_flags *flags)
{
	char	buffer[50];
	int		len;

	len = 0;
	if (flags->has_precision)
		sprintf(buffer, "%.*d", flags->precision, num);
	else if (flags->zero_pad && !flags->left_align)
		sprintf(buffer, "%0*d", flags->field_width, num);
	else
		sprintf(buffer, "%d", num);
	len = write(1, buffer, strlen(buffer));
	return (len);
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
