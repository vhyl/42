/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:50 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/13 20:06:30 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static char	*ft_is_negative(char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (&str[i]);
}

static int	check_int_min(char *str)
{
	char	*min;

	min = "-2147483648";
	if (ft_strlen(str) != 11)
		return (0);
	while (*str && *min)
	{
		if (*str != *min)
			return (0);
		str++;
		min++;
	}
	if (*str)
		return (0);
	return (1);
}
int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;
	int	max;

	if (check_int_min((char *)str))
		return (-2147483648);
	i = 0;
	res = 0;
	str = ft_is_negative((char *)str, &sign);
	max = 214748364;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (res > max || (res == max && str[i] > '7'))
				return (0);
			res = res * 10 + str[i] - '0';
		}
		else
			return (0);
		i++;
	}
	return (res * sign);
}
