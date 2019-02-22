/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:11:57 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 14:18:59 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_color(void)
{
	int i;
	int ii;

	i = 0;
	while (i++ < 10000)
	{
		ii = 0;
		while (ii++ < 7)
		{
			printf("\x1B[3%dm%s\n", ii, "FUCK TERMINALS");
		}
	}
	printf("\x1B[0m");
}
