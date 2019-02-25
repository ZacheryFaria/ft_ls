/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:12:05 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/25 10:47:51 by zfaria           ###   ########.fr       */
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

char	**longflag(char *path)
{
	int				i;
	struct stat		st;
	char			**shit;

	shit = malloc(12 * sizeof(shit));
	lstat(path, &st);
	i = -1;
	while (++i < 7)
	{
		if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
			shit[i] = g_aay[i](st);
		else
		{
			if (i == 6)
				break ;
			shit[i] = (*g_ay[i])(st);
		}
	}
	shit[10] = path;
	shit[11] = 0;
	if (shit[0][0] == 'l')
		shit[11] = long_link(path);
	shit[i] = 0;
	shit[0][10] = listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0 ?
		'@' : ' ';
	return (shit);
}
