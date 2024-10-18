/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:31:07 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/17 14:35:33 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex(unsigned int num, int uppercase, t_flags *flags)
{
    char buffer[50];
    const char *base;
    int i;
    int len;

	i = 49;
    buffer[i--] = '\0';
	base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    if (num == 0)
        buffer[i--] = '0';
    while (num > 0)
	{
        buffer[i--] = base[num % 16];
        num /= 16;
    }
    char *formatted = &buffer[i + 1];
    if (flags->has_precision)
        sprintf(buffer, "%.*s", flags->precision, formatted);
    else if (flags->zero_pad && !flags->left_align)
        sprintf(buffer, "%0*s", flags->field_width, formatted);
    else if (flags->left_align)
        sprintf(buffer, "%-*s", flags->field_width, formatted);
	formatted = buffer;
    len = write(1, formatted, strlen(formatted));
    return (len);
}
