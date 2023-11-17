/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:40:28 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/15 12:40:28 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(const char type, va_list args)
{
	if (type == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long int)));
	else if (type == 'd')
		return (ft_print_int(va_arg(args, int)));
	else if (type == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (type == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_parse(const char *str, va_list args)
{
	int	len_print;
	int	i;

	i = 0;
	len_print = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_print += ft_print_type(str[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			len_print++;
			i++;
		}
	}
	return (len_print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len_print;

	va_start(args, str);
	len_print = ft_parse((char *)str, args);
	va_end(args);
	return (len_print);
}
