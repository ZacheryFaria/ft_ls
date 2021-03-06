/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:39:30 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/26 14:55:39 by zfaria           ###   ########.fr       */
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
int g_color = 0;
int	g_fsort = 0;
int	g_show_hidden_root = 0;

void	badopt(char opt)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ft_ls [-Rrlat] [file ...]\n", 2);
	exit(1);
}

void	parse_flag(char *str)
{
	if (*str == 'R')
		g_recursive = 1;
	else if (*str == 'r')
		g_reverse = 1;
	else if (*str == 'l')
		g_long_format = 1;
	else if (*str == 'a')
		g_show_hidden = 1;
	else if (*str == 't')
		g_sort_time = 1;
	else if (*str == 'G')
		g_color = 1;
	else if (*str == '1')
	{
	}
	else
		badopt(*str);
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
			return (i - 1);
		i++;
	}
	return (i - 1);
}

void	almost_ls(int flags, int argc, char **argv)
{
	char	*dir;
	int		m;

	m = flags < argc - 2 ? 1 : 0;
	while (flags < argc - 1)
	{
		if (m)
			ft_printf("%s:\n", argv[flags + 1]);
		dir = argv[flags + 1];
		if (dir[ft_strlen(dir) - 1] != '/')
			dir = ft_strjoin(dir, "/");
		ls(dir, 1);
		flags++;
		if (flags < argc - 1)
			ft_putendl("");
	}
}

int		main(int argc, char **argv)
{
	char	*dir;
	int		flags;

	flags = 0;
	dir = 0;
	if (argc > 1)
		flags = parse_args(argc, argv);
	if (argc == 1 || 1 == argc - flags)
		ls("./", 1);
	else
		almost_ls(flags, argc, argv);
	if (g_color)
		print_color();
	return (0);
}
