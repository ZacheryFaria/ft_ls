/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:34:27 by awindham          #+#    #+#             */
/*   Updated: 2019/02/26 14:29:01 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>
#include <libft.h>

void	print_long(char ***done, int i, int j)
{
	int *maxwidth;

	j = -1;
	while (++j < i)
	{
		if (!(!g_show_hidden && basename(done[j][10])[0] == '.'))
		{
			maxwidth = long_getmaxwidth(done);
			ft_printpad(maxwidth[0], " ", 'r', done[j][0], 0);
			ft_printpad(maxwidth[1], " ", 'r', done[j][1], 0);
			ft_printpad(maxwidth[2], " ", 'l', done[j][2], 0);
			ft_printpad(maxwidth[3], " ", 'l', done[j][3], 0);
			ft_printpad(maxwidth[4], " ", 'r', done[j][4], 0);
			ft_printpad(maxwidth[4], " ", 'r', done[j][5], 0);
			ft_printpad(maxwidth[5], " ", 'r', done[j][6], 0);
			if (done[j][10])
				ft_printf("%s", basename(done[j][10]));
			if (done[j][11])
				ft_printf(" -> %s", done[j][11]);
			ft_printf("\n");
			free(maxwidth);
		}
	}
}

void	freeshit(char ***done)
{
	int i;

	i = 0;
	while (done[i])
	{
		free_tab(done[i]);
		if (done[i])
			free(done[i]);
		done[i] = 0;
		i++;
	}
	if (done)
		free(done);
}

void	print(int i, int j, char ***done)
{
	while (++j <= i)
	{
		if (!g_show_hidden && !g_fsort)
		{
			if (basename(done[j - 1][10])[0] != '.')
				ft_printf("%s\n", basename(done[j - 1][10]));
		}
		else
			ft_printf("%s\n", basename(done[j - 1][10]));
	}
}

void	cont(int i, int j, char ***done, int blocksize)
{
	if (i == 0)
		return ;
	if (g_long_format == 1)
	{
		if (!g_is_file && !g_dir_size_nohide)
			ft_printf("total %d\n", blocksize);
		print_long(done, i, j);
	}
	else
		print(i, j, done);
}

void	print_files(char **list)
{
	char	***done;
	int		i;
	int		j;
	long	blocksize;

	blocksize = 0;
	done = malloc(4096 * sizeof(done));
	i = -1;
	while (list[++i])
	{
		done[i] = longflag(list[i], &blocksize);
		if (done[i] == 0)
		{
			free(done);
			return ;
		}
	}
	done[i] = 0;
	j = 0;
	cont(i, j, done, blocksize);
	freeshit(done);
}
