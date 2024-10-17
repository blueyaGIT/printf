/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:57:35 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/17 11:03:48 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_pointer(uintptr_t ptr, int *printed_chars)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (ptr >= 16)
		ft_print_pointer(ptr / 16, printed_chars);
	*printed_chars += write(1, &hex_digits[ptr % 16], 1);
}
