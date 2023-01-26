/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:46:11 by vhyl              #+#    #+#             */
/*   Updated: 2023/01/24 18:48:09 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_string(char *s);
int	ft_print_decimal(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_ptr(uintptr_t n);
int	ft_print_hexa(int n, char fcase);

#endif
