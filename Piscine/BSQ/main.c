/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhyl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:29:52 by vhyl              #+#    #+#             */
/*   Updated: 2022/11/02 22:48:33 by vhyl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	main(int argc, char *argv[])
{
	char	*input;
	char	**map;
	t_inp	vars;
	int	**dp;
	int	i;

	i = 1;
	if (argc == 1)
	{
		i = 0;
		argv = read_standard();
	}
	while (argv[i] != 0)
	{
		input = read_input(argv[i]);
		i++;
		if (validator(input))
		{	write(1, "map error\n", 10);
			if (argv[i] != 0)
				write(1, "\n", 1);
			continue;
		}
		vars = first_row(input);
		map = fill_map(get_map(vars), input, vars);
		dp = ft_dp(get_dp(vars), map, &vars);
		map = fill_square(map, dp, vars);
		if (argv[i] != 0)
			write(1, "\n", 1);
		free_all(dp, input, vars, map);
	}
	return (0);
}


