/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:49:53 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/25 16:32:55 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int n)
{
	char	*res;
	int	len;

	res = ft_itoa(n);
	len = ft_print_string(res);
	free(res);
	return (len);
}
