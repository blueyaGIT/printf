/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:35:38 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/15 10:36:42 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	print_number(int num, t_flags *flags)
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
