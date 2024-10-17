/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:56:06 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/17 10:57:07 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_string(const char *str, int *printed_chars)
{
	if (!str)
		str = "(null)";
	while (*str)
		*printed_chars += write(1, str++, 1);
}
