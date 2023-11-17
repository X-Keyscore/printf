/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:18:59 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/17 02:18:59 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(int d)
{
	char			*string;
	unsigned long int	quot;
	long long	ld;
	int				len;

	ld = (long long)d;
	len = 1;
	if (ld <= 0)
		len++;
	if (ld < 0)
		ld = ld * -1;
	quot = (unsigned long int)ld;
	while (quot)
	{
		quot /= 10;
		len++;
	}
	string = malloc(sizeof(char) * len);
	if (!string)
		return (0);
	string[0] = '-';
	ft_convert_base(string, (unsigned long int)ld, len, "0123456789");
	ft_print_str(string);
	free(string);
	return (len - 1);
}
