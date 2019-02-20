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

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		parse_args(argc, argv);
	}

	printf("R-%d, r-%d, t-%d, l-%d, a-%d\n", recursive, reverse, sort_time, long_format, show_hidden);

	char **list = get_files(argv[argc - 1]);
	list = sort_tab(list, ft_strcmp);
	while (*list)
	{
		printf("%s\n", *list);
		struct stat buf;
		stat(*list, &buf);
		list++;
	}
}
