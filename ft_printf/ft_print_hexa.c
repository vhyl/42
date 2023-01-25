/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:46:36 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/25 22:43:12 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size_hexa(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}
static char	*ft_itoa_hexa(int n, char fcase)
{
	char	*res;
	int	size;

	size = get_size_hexa(n);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (n < 0)
		res[0] = '-';
	while (n != 0)
	{
		res[size - 1] = n % 16 + fcase;
		n /= 16;
		size--;
	}
	return (res);
}

int	ft_print_hexa(int n, char fcase)
{
	char	*res;
	int	len;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (fcase == 'x')
		fcase = 'a';
	else
		fcase = 'A';
	res = ft__itoa_hexa(n, fcase);
	len = ft_print_string(res);
	free(res);
	return (len);
}
