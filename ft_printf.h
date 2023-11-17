/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:40:42 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/15 12:40:42 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(const char *s);

void	ft_convert_base(char *string, unsigned long int d, int len, char *base);

int		ft_print_char(char c);

int		ft_print_str(char *s);

int		ft_print_ptr(unsigned long int p);

int		ft_print_int(int d);

int		ft_print_uint(unsigned int u);

int		ft_print_hex(unsigned int d, char *base);

int		ft_print_type(const char type, va_list args);

int		ft_parse(const char *str, va_list args);

int		ft_printf(const char *, ...);

#endif