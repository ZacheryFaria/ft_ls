/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:12:05 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/22 13:22:48 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/xattr.h>

/* 
** Unix file types,
** permissions,
** number of hard links,
** owner,
** group,
** size,
** last-modified date
*/

char* (*f[6])(struct stat st) =
{
	long_permissions,
	long_hardlinks,
	long_owner,
	long_group,
	long_size,
	long_lastmod
};

char	**longflag(char *path)
{
	int i;
	struct stat st;
	char **shit = malloc(9 * sizeof(shit));
	char *buf;

	lstat(path, &st);
	i = 0;
	while (i < 6)
	{
		shit[i] = (*f[i])(st);
		i++;
	}
	shit[i++] = path;	
	if (shit[0][0] == 'l')
	{
		buf = ft_strnew(1024);
		readlink(path, buf, 1023);
		shit[i++] = ft_strdup(basename(buf));
		free(buf);
		buf = 0;
	}
	shit[i] = 0;
	shit[0][10] = listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0 ?
		'@' : ' ';
	return (shit);
}
