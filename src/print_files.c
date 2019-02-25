/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:34:27 by awindham          #+#    #+#             */
/*   Updated: 2019/02/25 10:56:05 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>
#include <libft.h>

void	print_long(char ***done, int i, int j)
{
	int *maxwidth;

	j = 0;
	while (j < i)
	{
		maxwidth = long_getmaxwidth(done);
		ft_printpad(maxwidth[0], " ", done[j][0], 0);
		ft_printpad(maxwidth[1], " ", done[j][1], 0);
		ft_printpad(maxwidth[2], " ", done[j][2], 0);
		ft_printpad(maxwidth[3], " ", done[j][3], 0);
		ft_printpad(maxwidth[4], " ", done[j][4], 0);
		ft_printpad(maxwidth[4], " ", done[j][5], 0);
		ft_printpad(maxwidth[5], " ", done[j][6], 0);

		if (done[j][10])
			ft_printf(" %s", basename(done[j][10]));
		if (done[j][11])
			ft_printf(" -> %s", done[j][11]);
		ft_printf("\n");
		free(maxwidth);
		maxwidth = 0;
		j++;
	}
}

void	freeshit(char ***done, int i)
{
	while (i >= 0)
	{
		free_tab(done[i]);
		if (done[i])
			free(done[i]);
		done[i] = 0;
		i--;
	}
	if (done)
		free(done);
}

void	print_files(char **list)
{
	char	***done;
	int		i;
	int		j;

	done = malloc(4096 * sizeof(done));
	i = -1;
	while (list[++i])
		done[i] = longflag(ft_strdup(list[i]));
	done[i] = 0;
	j = 0;
	if (g_long_format == 1)
		print_long(done, i, j);
	else
		while (++j <= i)
			ft_printf("%s\n", basename(done[j - 1][10]));
	i--;
	freeshit(done, i);
	done = 0;
}
