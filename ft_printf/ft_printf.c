/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:40:21 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/25 23:32:32 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(va_list args, char ftype)
{
	int	res;

	res = 0;
	if (ftype == 'c')
		res = ft_print_char(va_arg(args, int));
	else if (ftype == 's')
		res = ft_print_string(va_arg(args, char *));
	else if (ftype == 'p')
		res = ft_print_ptr(va_arg(args, uintptr_t));
	else if (ftype == 'd' || ftype == 'i')
		res = ft_print_decimal(va_arg(args, int));
	else if (ftype == 'u')
		res = ft_print_unsigned(va_arg(args, unsigned int));
	else if (ftype == 'x' || ftype == 'X')
		res = ft_print_hexa(va_arg(args, int), ftype);
	else if (ftype == '%')
	{
		res = 1;
		write(1, "%", 1);
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	size;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_conversions(args, str[i + 1]);
			i++;
		}
		else
			size += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}
