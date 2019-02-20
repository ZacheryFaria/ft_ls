/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_lastmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:49:24 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 15:17:28 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <time.h>

void	long_lastmod(const char *path)
{
	struct stat	st;
	char		*buf;
	int			i;

	stat(path, &st);
	buf = ctime(&st.st_mtimespec.tv_sec);
	while (*buf++ != ' ')
		;
	i = 0;
	while (buf[i++] != ' ')
		;
	while (buf[i++] != ' ')
		;
	buf[i] = 0;
	ft_putstr(buf);
}
