/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:37:08 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/21 12:59:11 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>

int		time_cmp(const char *s1, const char *s2)
{
	struct stat st1;
	struct stat st2;
	long		diff;
	long		diffn;

	stat(s1, &st1);
	stat(s2, &st2);
	diff = st2.st_mtimespec.tv_sec - st1.st_mtimespec.tv_sec;
	diffn = st2.st_mtimespec.tv_nsec - st1.st_mtimespec.tv_nsec;
	if (diff == 0)
		return (diffn);
	return (diff);
}
