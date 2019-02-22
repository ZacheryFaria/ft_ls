/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:25:00 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/22 13:59:51 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**sort_tab(char **tab, int (*cmp)(const char *s1, const char *s2))
{
	char	*last;
	int		sorted;
	int		i;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (tab[i + 1])
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				last = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = last;
				sorted = 0;
			}
			i++;
		}
	}
	return (tab);
}
