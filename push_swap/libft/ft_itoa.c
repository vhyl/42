/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:29:47 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/16 19:44:07 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
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

static char	*ft_rev_str(char *str)
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

static char	*zero_min(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else if (n == -2147483648)
	{
		str[0] = '8';
		str[1] = '4';
		str[2] = '6';
		str[3] = '3';
		str[4] = '8';
		str[5] = '4';
		str[6] = '7';
		str[7] = '4';
		str[8] = '1';
		str[9] = '2';
		str[10] = '-';
		str[11] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		vars[2];
	char	*res;

	res = malloc((get_size(n) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_bzero(res, (get_size(n) + 1));
	res = zero_min(n, res);
	vars[0] = 0;
	vars[1] = 1;
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		vars[1] = -1;
	}
	while (n > 0)
	{
		res[vars[0]++] = n % 10 + '0';
		n /= 10;
	}
	if (vars[1] == -1)
		res[vars[0]++] = '-';
	res = ft_rev_str(res);
	return (res);
}
