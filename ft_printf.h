/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:03:41 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/15 10:48:26 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>  // For va_list
# include <stddef.h>  // For size_t
# include <stdbool.h> // For boolean values
# include <ctype.h>
# include <stdio.h>

/*
Enumeration for the different format specifiers.
e_format_type: An enum to keep track of the type 
of format specifier. It makes your code cleaner and
ensures that each specifier is represented consistently.
*/
typedef enum e_format_type {
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	INTEGER,
	UNSIGNED,
	HEX_LOWER,
	HEX_UPPER,
	PERCENT
}	t_format_type;

// Structure to hold flag and field information for each conversion.
typedef struct s_flags {
	bool	left_align;
	bool	zero_pad;
	bool	alternate_form;
	bool	force_sign;
	bool	space;
	int		field_width;
	int		precision;
	bool	has_precision;
}	t_flags;

// Structure to hold information about a specific format specifier.
typedef struct s_format {
	t_format_type	type;
	union {
		char			c;
		char			*s;
		void			*p;
		int				d;
		unsigned int	u;
		unsigned int	x;
	}	u_value;
}	t_format;

// Function prototype for ft_printf.
int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			print_number(int num, t_flags *flags);

void		init_flags(t_flags *flags);

const char	*parse_flags(const char *format, t_flags *flags);
const char	*parse_width(const char *format, t_flags *flags, va_list args);
const char	*parse_precision(const char *format, t_flags *flags, va_list args);
const char	*parse_format(const char *format, t_flags *flags, va_list args);

#endif /* LIBFTPRINTF_H */