/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:28:04 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 22:49:31 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "structs.h"
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_inp
{
	char	space;
	char	obstacle;
	char	square;
	int	row;
	int	column;
	int	max;
}	t_inp;

int	find_min(int a, int b, int c);
int	**ft_dp(int **dp, char **map, t_inp *vars);
char	**fill_square(char **map, int **dp, t_inp vars);
t_pos	find_max(int	**dp, t_inp vars);
void	print(char **map, t_inp vars);
int	number_of_columns(char *str);
int	number_of_rows(char *str);
t_inp	first_row(char *str);
int	count_rows(char *input);
int	validator(char *input);
char	*read_input(char *name);
int	**get_dp(t_inp vars);
char	**fill_map(char **map, char *inp, t_inp vars);
char	**get_map(t_inp vars);
int     check_chars(char *input, t_inp vars);
int     check_columns(char *input);
char    **read_standard();
void	free_all(int **dp, char *input, t_inp, char **map);
#endif
