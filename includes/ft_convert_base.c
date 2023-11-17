/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:51:17 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/17 15:51:17 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_convert_base(char *string, unsigned long int d, int len, char *base)
{
	unsigned long int	quot;
	int				len_base;
	int				i;

	len_base = ft_strlen(base);
	i = len - 1;
	string[i--] = 0;
	if (d == 0)
		string[i] = '0';
	quot = d;
	while (quot && i >= 0)
	{
		string[i--] = base[quot % len_base];
		quot /= len_base;
	}
}
