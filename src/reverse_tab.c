/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:52:12 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/20 13:19:06 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**reverse_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (tab[i])
		i++;
	i--;
	while (j < i / 2)
	{
		tmp = tab[i - j];
		tab[i - j] = tab[j];
		tab[j] = tmp;
		j++;
	}
	return (tab);
}
