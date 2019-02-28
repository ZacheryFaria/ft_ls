/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:12:05 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/27 21:05:01 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/xattr.h>

char	*(*g_ay[6])(struct stat st) =
{
	long_permissions,
	long_hardlinks,
	long_owner,
	long_group,
	long_size,
	long_lastmod
};

char	*(*g_aay[7])(struct stat st) =
{
	long_permissions,
	long_hardlinks,
	long_owner,
	long_group,
	long_major,
	long_minor,
	long_lastmod
};

void	xattr(char *path, char **lflag, int i)
{
	lflag[10] = path;
	lflag[11] = 0;
	if (lflag[0][0] == 'l')
		lflag[11] = long_link(path);
	lflag[i] = 0;
	lflag[0][10] = listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0 ?
		'@' : ' ';
}

char	**longflag(char *path, long *blocksize)
{
	int				i;
	struct stat		st;
	char			**lflag;

	lflag = malloc(12 * sizeof(lflag));
	lstat(path, &st);
	i = -1;
	if (g_show_hidden || (!g_show_hidden && basename(path)[0] != '.'))
		*blocksize += (st.st_size / 512) + (st.st_size % 512 > 0);
	while (++i < 7)
	{
		if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
			lflag[i] = g_aay[i](st);
		else
		{
			if (i == 6)
				break ;
			lflag[i] = (*g_ay[i])(st);
		}
	}
	xattr(path, lflag, i);
	return (lflag);
}
