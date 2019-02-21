/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_permissions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:16:00 by awindham          #+#    #+#             */
/*   Updated: 2019/02/21 07:19:06 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <libft.h>
#include <ft_ls.h>

char	*long_permissions(struct stat st)
{
	char *done;

	done = malloc(11);
	done[0] = long_filetypes(st);
	done[1] = ((st.st_mode & S_IRUSR) ? 'r' : '-');
	done[2] = ((st.st_mode & S_IWUSR) ? 'w' : '-');
	done[3] = ((st.st_mode & S_IXUSR) ? 'x' : '-');
	done[4] = ((st.st_mode & S_IRGRP) ? 'r' : '-');
	done[5] = ((st.st_mode & S_IWGRP) ? 'w' : '-');
	done[6] = ((st.st_mode & S_IXGRP) ? 'x' : '-');
	done[7] = ((st.st_mode & S_IROTH) ? 'r' : '-');
	done[8] = ((st.st_mode & S_IWOTH) ? 'w' : '-');
	done[9] = ((st.st_mode & S_IXOTH) ? 'x' : '-');
	done[10] = 0;
	return (done);
}
