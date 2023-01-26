/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:23 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/25 16:32:24 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	int	size;

	size = get_size(n);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (n != 0)
	{
		res[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (res);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*res;
	int	len;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	res = ft_unsigned_itoa(n);
	len = ft_print_string(res);
	free(res);
	return (len);
}
