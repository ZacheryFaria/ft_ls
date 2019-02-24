/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:46:34 by awindham          #+#    #+#             */
/*   Updated: 2019/02/24 11:00:09 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>
#include <ft_ls.h>
#include <stdlib.h>

char	**format_list(char **list)
{
	qsort_tab(list, array_len(list), ft_strcmp);
	if (!g_show_hidden)
		list = flag_hide(list);
	if (g_sort_time)
		qsort_tab(list, array_len(list), time_cmp);
	if (g_reverse)
		list = reverse_tab(list);
	return (list);
}

void	printpath(char *path, int first)
{
	char *tmp;

	if (!first)
	{
		tmp = ft_strsub(path, 0, ft_strlen(path) - 1);
		ft_printf("\n%s:\n", tmp);
		ft_strdel(&tmp);
	}
}

void	recurse(char **list)
{
	char	*tmp;
	int		i;

	i = 0;
	while (list[i])
	{
		if (isdir(list[i]) == 1 && ft_strcmp(basename(list[i]), ".")
			&& ft_strcmp(basename(list[i]), "..") && islink(list[i]) != 1)
		{
			tmp = ft_strjoin(list[i], "/");
			ls(tmp, 0);
			ft_strdel(&tmp);
		}
		i++;
	}
}

void	ls(char *path, int first)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**list;
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
		printpath(path, first);
	list = format_list(list);
	print_files(list);
	i = 0;
	if (g_recursive)
		recurse(list);
	free_tab(list);
}
