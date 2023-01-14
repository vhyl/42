/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:29:47 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/14 00:53:57 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_rev_str(char *str)
{
	char	temp;
	int		start;
	int		end;
	int		len;

	start = 0;
	len = ft_strlen(str);
	end = len - 1;
	while (start < len / 2)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

char	*zero_min(int n, char *str)
{
	if (n == 0)
		str = "0";
	else if (n == -2147483648)
		str = "-2147483648";
	return (str);
}

char	*ft_itoa(int n)
{
	int		vars[3];
	char	*res;

	vars[0] = get_size(n) + 1;
	res = malloc(vars[0] * sizeof(char));
	ft_bzero(res, vars[0]);
	res = zero_min(n, res);
	if (res[0] != '\0')
		return (res);
	vars[1] = 0;
	vars[2] = 1;
	if (n < 0)
	{
		n *= -1;
		vars[2] = -1;
	}
	while (n != 0)
	{
		res[vars[1]++] = n % 10 + '0';
		n /= 10;
	}
	if (vars[2] == -1)
		res[vars[1]++] = '-';
	res = ft_rev_str(res);
	return (res);
}
