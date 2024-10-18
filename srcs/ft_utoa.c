/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:13:21 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 14:15:14 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_utoa(unsigned int num, char *buffer, int precision)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	if (num == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return ;
	}
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i < precision)
		buffer[i] = '\0';
	while (j < i / 2)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}
}
