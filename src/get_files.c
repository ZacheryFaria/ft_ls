/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:07:24 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/19 13:22:23 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>
#include <stdlib.h>
#include <ft_ls.h>

char	**get_files(char *dirs)
{
	DIR				*dir;
	struct dirent	*entry;
	char 			**list;
	int				i;
	int				len;

	i = 0;
	dir = opendir(dirs);
	len = dir_size(dirs);
	list = malloc(sizeof(char *) * (len + 1));
	while ((entry = readdir(dir)) != NULL)
		list[i++] = ft_strdup(entry->d_name);
	list[len] = NULL;
	free (entry);
	free (dir);
	return (list);
}
