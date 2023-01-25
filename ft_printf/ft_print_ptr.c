/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:03:02 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/25 22:42:40 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size_hexa(uintptr_t n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static char	*ft_itoa_hexa(uintptr_t n)
{
	char	*res;
	int	size;

	size = get_size_hexa(n);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (n != 0)
	{
		res[size - 1] = n % 16 + 'a';
		n /= 16;
		size--;
	}
	return (res);
}

int	ft_print_ptr(uintptr_t n)
{
	char	*res;
	int	len;

	if (n == 0)
	{
		write(1, "(nil)", 1);
		return (5);
	}
	write(1, "0x", 2);
	res = ft_itoa_hexa(n);
	len = ft_print_string(res) + 2;
	free(res);
	return (len);
}
