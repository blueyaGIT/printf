/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:24:52 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 18:53:20 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	temp;

	temp = 0;
	if (!str)
		str = "(null)";
	while (str[temp])
		ft_putchar(str[temp++]);
	return (temp);
}
