/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:19:06 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/17 02:19:06 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_uint(unsigned int u)
{
	char			*string;
	unsigned long int	quot;
	int				len;

	u = (unsigned long int)u;
	len = 1;
	if (u == 0)
		len++;
	quot = u;
	while (quot)
	{
		quot /= 10;
		len++;
	}
	string = malloc(sizeof(char) * len);
	if (!string)
		return (0);
	ft_convert_base(string, u, len, "0123456789");
	ft_print_str(string);
	free(string);
	return (len - 1);
}
