/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:50 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/09 18:49:36 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_is_negative(char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (&str[i]);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	str = ft_is_negative(str, &sign);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
		{
			if (sign == -1)
				return (res * -1);
			return (res);
		}
		i++;
	}
	if (sign == -1)
		return (res * -1);
	return (res);
}
