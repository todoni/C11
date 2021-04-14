/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 06:09:14 by sohan             #+#    #+#             */
/*   Updated: 2021/04/15 06:58:56 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	is_valid_operator(char *op)
{
	int len;

	len = 0;
	while (op[len])
		len++;
	if (len != 1)
		return (false);
	if (*op == '-' || *op == '+' || *op == '*' || *op == '/' || *op == '%')
		return (true);
	return (false);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int	result;
	int	n_power_of_ten;

	n_power_of_ten = 1;
	result = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\t' || \
							*str == '\n' || *str == '\v' || \
							*str == '\f' || *str == '\r'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n_power_of_ten *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	str--;
	while (*str >= '0' && *str <= '9')
	{
		result = result + (*str - 48) * n_power_of_ten;
		n_power_of_ten *= 10;
		str--;
	}
	return (result);
}

int		check_exception(int nb)
{
	if (nb == -2147483648)
	{
		nb = nb + 1;
		nb = -nb;
		write(1, "-", 1);
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char	nbr[10];
	int		i;
	int		init;

	init = nb;
	nb = check_exception(nb);
	i = 0;
	while (nb != 0)
	{
		nbr[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	if (init == -2147483648)
	{
		nbr[0] = nbr[0] + 1;
	}
	while (i >= 1)
	{
		write(1, &nbr[i - 1], 1);
		i--;
	}
	write(1, "\n", 1);
}
