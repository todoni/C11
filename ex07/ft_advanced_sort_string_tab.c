/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 03:56:43 by sohan             #+#    #+#             */
/*   Updated: 2021/04/15 07:13:28 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	num_tab;
	int	i;

	num_tab = 0;
	i = 0;
	while (tab[num_tab])
	{
		num_tab++;
	}
	while (num_tab != 0)
	{
		while (i < num_tab - 1)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
				swap(tab + i, tab + i + 1);
			i++;
		}
		num_tab--;
		i = 0;
	}
}
