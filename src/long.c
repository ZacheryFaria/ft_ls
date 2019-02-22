/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2019/02/20 13:01:15 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 12:46:12 by awindham         ###   ########.fr       */
=======
/*   Created: 2019/02/22 12:56:25 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/22 12:56:26 by zfaria           ###   ########.fr       */
>>>>>>> 7a9dff509a68cb3e39fce18d4ad5bf6836a44d6a
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

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
<<<<<<< HEAD
		shit[i] = ft_strnew(1024);
		readlink(path, shit[i++], 1023);
=======
		buf = ft_strnew(1024);
		readlink(path, buf, 1023);
		shit[i++] = ft_strdup(basename(buf));
		free(buf);
		buf = 0;
>>>>>>> 7a9dff509a68cb3e39fce18d4ad5bf6836a44d6a
	}
	shit[i] = 0;
	return (shit);
}
