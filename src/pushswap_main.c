/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:41:40 by jslave            #+#    #+#             */
/*   Updated: 2020/02/22 13:41:46 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*
 * 3  числа от 2 до 3 инструкций
 * 5 чисел не больше 12
 * 100 чисел :
 * -меньше 700 оценка 5
 * -меньше 900 оценка 4//
 * меньше 1100 оценка 3
 * меньше 1300 оценка 2
 * меньше 1500 оценка 1
 *
 * 500 чисел :
 * -меньше 5500 оценка 5
 * -меньше 7000 оценка 4
 * меньше 8500 оценка 3//
 * меньше 10000 оценка 2
 * меньше 11500 оценка 1
 */

int 		main(int ac, char **av)
{
	t_pushswap *ps;
	char **str_av;

	ps = NULL;
	if (ac <= 1)
		exit(1);
	if (ac == 2)
	{
		str_av = parse_string_arg(av[1]);
		if (!str_av || check_validity(find_2d_arr_size(str_av), str_av, 0) != 1 || !(ps = create_stacks(find_2d_arr_size(str_av), str_av, "str")))
			error_out(ps);
		push_swap(ps);
		memfree(str_av, find_2d_arr_size(str_av));
		free_ps(ps);
	}
	else
		if (check_validity(ac, av, 1) == 1)
	{
		if (!(ps = create_stacks(ac, av, NULL)))
			error_out(ps);
		push_swap(ps);
		free_ps(ps);
	}
	else
		error_out(ps);
	return (0);
}
