/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprntf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:31:25 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/17 17:36:16 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../ft_printf.h"

void	int_to_str(int num, char *str)
{
    int 	i;
	int		j;
	int		is_negative;
	char	temp;

	i = 0;
	is_negative = 0;
	j = 0;
    if (num < 0)
	{
        is_negative = 1;
        num = -num;
    }
    while (num > 0)
	{
        str[i++] = (num % 10) + '0';
        num /= 10;
    } 
    if (is_negative)
        str[i++] = '-';
    str[i] = '\0';
	while (j < i / 2)
	{
        temp = str[j];
        str[j] = str[i - 1 - j];
        str[i - 1 - j] = temp;
    }
}
void	my_strcpy(char *dest, const char *src)
{
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
}

int	my_sprintf(char *buffer, const char *format, ...) {
    va_list args;
    va_start(args, format);

    const char *traverse = format;
    char *buf_ptr = buffer;
    char temp[50];  // Temporary buffer for integers

    while (*traverse) {
        if (*traverse == '%') {
            traverse++;  // Skip '%'

            if (*traverse == 'd') {  // Handle integer
                int num = va_arg(args, int);
                int_to_str(num, temp);  // Convert int to string
                my_strcpy(buf_ptr, temp);  // Copy to buffer
                buf_ptr += my_strlen(temp);  // Advance buffer pointer
            } 
            else if (*traverse == 's') {  // Handle string
                char *str = va_arg(args, char *);
                my_strcpy(buf_ptr, str);  // Copy string to buffer
                buf_ptr += my_strlen(str);  // Advance buffer pointer
            }
        } else {
            *buf_ptr++ = *traverse;  // Copy normal character
        }
        traverse++;
    }

    *buf_ptr = '\0';  // Null-terminate the final string

    va_end(args);
    return buf_ptr - buffer;  // Return total length of the string
}

// Helper function: Calculate the length of a string
int my_strlen(const char *str) {
    int length = 0;
    while (*str++) {
        length++;
    }
    return length;
}
