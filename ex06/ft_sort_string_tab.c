/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 03:31:51 by sohan             #+#    #+#             */
/*   Updated: 2021/04/15 07:13:07 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		compare_tab(char *tab1, char *tab2)
{
	int	diff;

	diff = 0;
	while (*tab1 == *tab2 && *tab1 != '\0')
	{
		tab1++;
		tab2++;
	}
	diff = *tab1 - *tab2;
	return (diff);
}

void	ft_sort_string_tab(char **tab)
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
			if (compare_tab(tab[i], tab[i + 1]) > 0)
				swap(tab + i, tab + i + 1);
			i++;
		}
		num_tab--;
		i = 0;
	}
}
