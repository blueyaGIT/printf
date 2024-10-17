/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:20:08 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/17 11:20:21 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_number(int n, int *printed_chars)
{
	char	buffer[12];
	int		i;
	int		is_negative;

	i = 11;
	is_negative = 0;
	buffer[i--] = '\0';
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	if (n == 0)
		buffer[i--] = '0';
	while (n > 0)
	{
		buffer[i--] = '0' + (n % 10);
		n /= 10;
	}
	if (is_negative)
		buffer[i--] = '-';

	*printed_chars += write(1, &buffer[i + 1], 11 - i);
}
