/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:11:57 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 15:37:31 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <unistd.h>
#define FUCK(x,y,s) ft_printf("\033[%d;%dH%s", (x), (y), (s))

void	print_color(void)
{
	int					i;
	int					ii;
	struct timespec		t;
	struct timespec		s;

	t.tv_nsec = 50000000L;
	t.tv_sec = 0;
	i = 0;
	while (i++ < 20)
	{
		ii = 0;
		while (ii++ < 7)
		{
			nanosleep(&t, &s);
			ft_printf("\x1B[3%dm", ii);
			FUCK(10, 50, "FUCK TERMINALS");
		}
	}
	ft_printf("\x1B[0m");
	ft_printf("\033[99H");
}
