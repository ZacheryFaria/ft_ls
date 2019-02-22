/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:26:41 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/21 16:14:26 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft.h>
#include <dirent.h>
#include <stdio.h>
#include <ft_ls.h>
#include <sys/stat.h>
#include <stdlib.h>

int g_long_format = 0;
int g_recursive = 0;
int g_show_hidden = 0;
int g_sort_time = 0;
int g_reverse = 0;

void	parse_flag(char *str)
{
	if (*str == 'R')
		g_recursive = 1;
	if (*str == 'r')
		g_reverse = 1;
	if (*str == 'l')
		g_long_format = 1;
	if (*str == 'a')
		g_show_hidden = 1;
	if (*str == 't')
		g_sort_time = 1;
	str += 1;
	if (*str)
		parse_flag(str);
}

int		parse_args(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			parse_flag(argv[i] + 1);
		else
			return(i);
		i++;
	}
	return (-1);
}

void	print_files(char **list)
{
	char ***done = malloc(1024);
	int i = 0;
	int j = 0;
	int *maxwidth;

	while (list[i])
	{
		done[i] = longflag(list[i]);
		i++;
	}
	done[i] = 0;
	j = -1;
	if (g_long_format == 1)
		while (++j < i)
		{
			maxwidth = long_getmaxwidth(done);
			ft_printpad(maxwidth[0], " ", done[j][0], 0);
			ft_printpad(maxwidth[1], " ", done[j][1], 0);
			ft_printpad(maxwidth[2], " ", done[j][2], 0);
			ft_printpad(maxwidth[3], " ", done[j][3], 0);
			ft_printpad(maxwidth[4], " ", done[j][4], 0);
			ft_printpad(maxwidth[5], " ", done[j][5], 0);
			ft_printf(" %s\n", done[j][6]);
		}
	else
		while (++j < i)
			ft_printf("%s\n", done[j][6]);

}

char	**format_list(char **list)
{
	list = sort_tab(list, ft_strcmp);
	if (!g_show_hidden)
		list = flag_hide(list);
	if (g_sort_time)
		list = sort_tab(list, time_cmp);
	if (g_reverse)
		list = reverse_tab(list);
	return (list);
}

void	ls(char *path, int first)
{
	DIR				*dir;
	struct	dirent	*entry;
	char 			**list;
	int				i;
	int				len;

	i = 0;
	dir = opendir(path);
	len = dir_size(path);
	list = malloc(sizeof(char *) * (len + 1));
	if (!dir)
		return ;
	while ((entry = readdir(dir)) != NULL)
		list[i++] = ft_strjoin(path, entry->d_name);
	closedir(dir);
	list[len] = NULL;
	free(entry);
	if (g_recursive)
		if (!first)
			ft_printf("\n%s:\n", ft_strsub(path, 0, ft_strlen(path) - 1));
	list = format_list(list);
	print_files(list);
	if (g_recursive)
	{
		while (*list)
		{
			if (isdir(*list) == 1 && ft_strcmp(basename(*list), ".") 
				&& ft_strcmp(basename(*list), "..") && islink(*list) != 1)
				ls(ft_strjoin(*list, "/"), 0);
			list++;
		}
	}
	free_tab(list);
}

int main(int argc, char **argv)
{
	char *dir = 0;
	int flags = 0;

	if (argc > 1)
	{
		flags = parse_args(argc, argv);
		dir = argv[flags];
	}
	if (argc == 1 || flags == -1)
	{
		dir = ".";
	}
	if (dir[ft_strlen(dir) - 1] != '/')
		dir = ft_strjoin(dir, "/");
	ls(dir, 1);
	
}
