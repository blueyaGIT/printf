/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_buffer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:07:50 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 18:53:20 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	edge_cases(int num, char *buffer, int is_negative, int i)
{
	if (num == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return ;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
}

void	ft_itoa_buffer(int num, char *buffer, int precision)
{
	int		i;
	int		j;
	int		is_negative;
	char	temp;

	i = 0;
	is_negative = 0;
	j = 0;
	edge_cases(num, buffer, is_negative, i);
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i < precision)
		buffer[i++] = '0';
	if (is_negative)
		buffer[i++] = '-';
	buffer[i] = '\0';
	while (j < i / 2)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}
}
