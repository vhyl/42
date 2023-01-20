/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:56:09 by vhyl              #+#    #+#             */
/*   Updated: 2022/10/15 12:48:07 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	x--;
	y--;
	while (j <= y && x >= 0)
	{
		while (i <= x)
		{
			if ((i == 0 && j == 0) || (i == x && j == y && x != 0 && y != 0))
                                ft_putchar('/');
			else if ((i == x && j == 0) || (i == 0 && j == y))
				ft_putchar('\\');
			else if (j == 0 || j == y || i == 0 || i == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
			i++;
		}
		i = 0;
		j++;
		ft_putchar('\n');
	}
}
