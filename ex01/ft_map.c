/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 02:38:01 by sohan             #+#    #+#             */
/*   Updated: 2021/04/15 07:11:03 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(length * sizeof(int));
	if (array == 0)
		return (0);
	while (tab[i])
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
