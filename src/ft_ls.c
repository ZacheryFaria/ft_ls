/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:15:54 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/15 13:39:22 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>
#include <stdio.h>
#include <ft_ls.h>
#include <sys/stat.h>
#include <stdlib.h>

int long_format = 0;
int recursive = 0;
int show_hidden = 0;
int sort_time = 0;
int reverse = 0;

void	parse_flag(char *str)
{
	if (*str == 'R')
		recursive = 1;
	if (*str == 'r')
		reverse = 1;
	if (*str == 'l')
		long_format = 1;
	if (*str == 'a')
		show_hidden = 1;
	if (*str == 't')
		sort_time = 1;
	str += 1;
	if (*str)
		parse_flag(str);
}

void	parse_args(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			parse_flag(argv[i] + 1);
		else
			break;
		i++;
	}
}

char	**ls(char *path)
{
	DIR				*dir;
	struct dirent	*entry;
	char 			**list;
	int				i;
	int				len;

	i = 0;
	dir = opendir(path);
	len = dir_size(path);
	list = malloc(sizeof(char *) * (len + 1));
	while ((entry = readdir(dir)) != NULL)
		list[i++] = ft_strjoin(path, entry->d_name);
	list[len] = NULL;
	free (entry);
	free (dir);
	return (list);
}

char	**format_list(char **list)
{
	if (!show_hidden)
		list = flag_hide(list);
	if (reverse)
		list = reverse_tab(list);		
	return (list);
}

int main(int argc, char **argv)
{
	char *dir = 0;
	if (argc > 1)
	{
		parse_args(argc, argv);
		dir = argv[argc - 1];
	}
	else if (argc == 1)
	{
		dir = ".";
	}
	if (dir[ft_strlen(dir) - 1] != '/')
		dir = ft_strjoin(dir, "/");
	char **list = ls(dir);
	list = sort_tab(list, ft_strcmp);
	list = format_list(list);
	while (*list)
	{
		if (long_format)
		{
			longflag(*list);
			ft_printf("%s\n", basename(*list));
		}
		else
			printf("%s\n", basename(*list));	
		list++;
	}
}
