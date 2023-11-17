/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:18:56 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/17 02:18:56 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex(unsigned int d, char *base)
{
	char			*string;
	unsigned long int	quot;
	int				len;

	d = (unsigned long int)d;
	len = 1;
	if (d == 0)
		len++;
	quot = d;
	while (quot)
	{
		quot /= 16;
		len++;
	}
	string = malloc(sizeof(char) * len);
	if (!string)
		return (0);
	ft_convert_base(string, d, len, base);
	ft_print_str(string);
	free(string);
	return (len - 1);
}
