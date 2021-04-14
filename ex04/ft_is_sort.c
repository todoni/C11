/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 02:47:50 by sohan             #+#    #+#             */
/*   Updated: 2021/04/15 07:14:18 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_ascend(int *tab, int length, int (*f)(int, int))
{
	while (--length)
	{
		if (f(*tab, *(tab + 1)) > 0)
			return (0);
		tab++;
	}
	return (1);
}

int	check_descend(int *tab, int length, int (*f)(int, int))
{
	while (--length)
	{
		if (f(*tab, *(tab + 1)) < 0)
			return (0);
		tab++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	if (check_ascend(tab, length, f) == 0 && \
					check_descend(tab, length, f) == 0)
		return (0);
	return (1);
}
