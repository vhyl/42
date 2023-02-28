/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:00:19 by vhyl              #+#    #+#             */
/*   Updated: 2023/02/28 15:00:29 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

long	ft_atoi2(const char *str)
{
	int	i;
	long	res;
	int	sign;

	i = 0;
	res = 0;
	str = ft_is_negative((char *)str, &sign);
	if (!(*str))
		return (2147483648);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			return (2147483648);
		i++;
	}
	return (res * (long)sign);
}
