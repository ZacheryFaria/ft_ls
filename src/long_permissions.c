/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_permissions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:16:00 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 13:20:01 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <libft.h>

void	long_permissions(const char *path)
{
	struct stat st;
	if (stat(path, &st) < 0)
		exit(-1);

	ft_putchar((S_ISDIR(st.st_mode))  ? 'd' : '-');
    ft_putchar((st.st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar((st.st_mode & S_IWUSR) ? 'w' : '-');
    ft_putchar((st.st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar((st.st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar((st.st_mode & S_IWGRP) ? 'w' : '-');
    ft_putchar((st.st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar((st.st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar((st.st_mode & S_IWOTH) ? 'w' : '-');
    ft_putchar((st.st_mode & S_IXOTH) ? 'x' : '-');
}