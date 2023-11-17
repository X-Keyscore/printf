/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:19:01 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/17 02:19:01 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_ptr(unsigned long int p)
{
	unsigned long int	quot;
	char				*string;
	int					len;

	len = 1;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
		
	quot = p;
	while (quot)
	{
		quot /= 16;
		len++;
	}
	string = malloc(sizeof(char) * len);
	if (!string)
		return (0);
	write(1, "0x", 2);
	ft_convert_base(string, p, len, "0123456789abcdef");
	ft_print_str(string);
	free(string);
	return (len + 1);
}
