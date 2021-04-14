/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 04:41:51 by sohan             #+#    #+#             */
/*   Updated: 2021/04/15 07:04:53 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "ft_operations.h"

bool	is_valid_operator(char *op);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		check_exception(int nb);
void	ft_putnbr(int nb);

int		calculate(char op, int a, int b, int (**f_calc)(int, int))
{
	int result;

	result = 0;
	if (op == '+')
		result = f_calc[0](a, b);
	else if (op == '-')
		result = f_calc[1](a, b);
	else if (op == '*')
		result = f_calc[2](a, b);
	else if (op == '/')
		result = f_calc[3](a, b);
	else if (op == '%')
		result = f_calc[4](a, b);
	return (result);
}

bool	will_return(int argc, char **argv)
{
	int a;
	int b;

	if (argc != 4)
		return (true);
	if (!is_valid_operator(argv[2]))
	{
		write(1, "0\n", 2);
		return (true);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (*argv[2] == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (true);
	}
	if (*argv[2] == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (true);
	}
	return (false);
}

int		main(int argc, char **argv)
{
	int	(*f_calc[5])(int, int);
	int a;
	int b;
	int	result;

	f_calc[0] = &add;
	f_calc[1] = &substitute;
	f_calc[2] = &multiple;
	f_calc[3] = &divide;
	f_calc[4] = &modulo;
	if (!will_return(argc, argv))
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		result = calculate(*argv[2], a, b, f_calc);
		ft_putnbr(result);
	}
	return (0);
}
