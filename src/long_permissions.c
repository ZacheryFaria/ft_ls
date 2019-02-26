/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_permissions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:16:00 by awindham          #+#    #+#             */
/*   Updated: 2019/02/25 17:05:31 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <libft.h>
#include <ft_ls.h>

char	check_sticky_user(int mode)
{
	if (mode & S_IXUSR)
	{
		if (mode & S_ISUID)
			return ('s');
		else
			return ('x');
	}
	else
	{
		if (mode & S_ISUID)
			return ('S');
		else
			return ('-');
	}

}

char	check_sticky_group(int mode)
{
	if (mode & S_IXGRP)
	{
		if (mode & S_ISGID)
			return ('s');
		else
			return ('x');
	}
	else
	{
		if (mode & S_ISGID)
			return ('S');
		else
			return ('-');
	}
}

char	*long_permissions(struct stat st)
{
	char *done;

	done = ft_strnew(15);
	done[0] = long_filetypes(st);
	done[1] = ((st.st_mode & S_IRUSR) ? 'r' : '-');
	done[2] = ((st.st_mode & S_IWUSR) ? 'w' : '-');
	done[3] = check_sticky_user(st.st_mode);
	done[4] = ((st.st_mode & S_IRGRP) ? 'r' : '-');
	done[5] = ((st.st_mode & S_IWGRP) ? 'w' : '-');
	done[6] = check_sticky_group(st.st_mode);
	done[7] = ((st.st_mode & S_IROTH) ? 'r' : '-');
	done[8] = ((st.st_mode & S_IWOTH) ? 'w' : '-');
	done[9] = ((st.st_mode & S_IXOTH) ? 'x' : '-');
	done[11] = 0;
	return (done);
}
