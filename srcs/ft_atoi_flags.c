/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:07:25 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/18 16:42:15 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_atoi_flags(const char **str)
{
	int	value;

	value = 0;
	while (**str >= '0' && **str <= '9')
	{
		value = (value * 10) + (**str - '0');
		(*str)++;
	}
	return (value);
}
