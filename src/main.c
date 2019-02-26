/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:39:30 by zfaria            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/25 13:07:48 by zfaria           ###   ########.fr       */
=======
/*   Updated: 2019/02/25 17:30:17 by awindham         ###   ########.fr       */
>>>>>>> 306c27bb809e2da3ac94af4e5985b6c514cc4716
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
	if (*str == 'G')
		g_color = 1;
	if (*str == 'A')
	{
		g_show_hidden = 1;
		g_show_hidden_root = 1;
	}
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
			return (i);
		i++;
	}
	return (-1);
}

int		main(int argc, char **argv)
{
	char	*dir;
	int		flags;
	int		multi_arg;

	flags = 0;
	dir = 0;
	if (argc > 1)
<<<<<<< HEAD
	{
		flags = parse_args(argc, argv);
		dir = argv[flags];
=======
		flags = parse_args(argc, argv);
	multi_arg = flags < argc - 1 ? 1 : 0;
	while (flags < argc)
	{
		if (multi_arg)
			ft_printf("%s:\n", argv[flags]);
		if (argc == 1 || flags == 0)
			dir = ".";
		else
			dir = argv[flags];
		if (dir[ft_strlen(dir) - 1] != '/')
			dir = ft_strjoin(dir, "/");
		ls(dir, 1);
		flags++;
		if (flags < argc)
			ft_printf("\n");
>>>>>>> 306c27bb809e2da3ac94af4e5985b6c514cc4716
	}
	if (argc == 1 || flags == -1)
		dir = ".";
	if (dir[ft_strlen(dir) - 1] != '/')
		dir = ft_strjoin(dir, "/");
	ls(dir, 1);
	if (g_color)
		print_color();
	return (0);
}
