/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:55:19 by vhyl              #+#    #+#             */
/*   Updated: 2022/10/21 22:43:12 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_negative(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	return (nb);
}
void	ft_hexa(int nb)
{
	char	buffer[20];
	int	i;
	int	temp;

	i = 0;
	nb = ft_negative(nb);
	while (nb != 0)
	{
		temp = nb % 16;
		if (temp < 10)
			buffer[i] = temp + 48;
		else
			buffer[i] = temp + 55;
		i++;
		nb = nb / 16;
	}
	i--;
	while (i >= 0)
		write (1, &buffer[i--], 1);
}

void ft_putnbr(int nb)
{
	int	temp;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	nb = ft_negative(nb);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	temp = nb + '0';
	write(1, &temp, 1);
}

void ft_binary(int nb)
{
	int	buffer[32];
	int	i;
	
	nb = ft_negative(nb);
	i = 0;
	while (nb > 0)
	{
		buffer[i] = nb % 2 + '0';
		nb = nb / 2;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &buffer[i], 1);
		i--;
	}
}

void ft_octal(int nb)
{
	char	buffer[20];
	int	i;

	i = 0;
	nb = ft_negative(nb);
	while (nb != 0)
	{
		buffer[i] = nb % 8;
		nb = nb / 8;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write (1, &buffer[i], 1);
		i--;
	}
}

int main()
{
	int str = 4564;
	ft_binary(str);
//	ft_hexa(str);
//	ft_putnbr(str);
}
