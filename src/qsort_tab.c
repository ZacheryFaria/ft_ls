/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:16:32 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/22 13:49:20 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	swap_str_ptrs(char **arg1, char **arg2)
{
	char *tmp;

	tmp = *arg1;
	*arg1 = *arg2;
	*arg2 = tmp;
}

void	qsort_tab(char **list, int len, int (*f)(const char *, const char *))
{
	int i;
	int pvt;

	if (len <= 1)
		return ;
	pvt = 0;
	swap_str_ptrs(list + ((int)rand() % len), list + len - 1);
	i = 0;
	while (i < len - 1)
	{
		if (f(list[i], list[len - 1]) < 0)
			swap_str_ptrs(list + i, list + pvt++);
		i++;
	}
	swap_str_ptrs(list + pvt, list + len - 1);
	qsort_tab(list, pvt++, f);
	qsort_tab(list + pvt, len - pvt, f);
}
