/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:14:06 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/21 14:28:29 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int	islink(const char *path)
{
	struct stat st;

	if (lstat(path, &st) < 0)
		return (-1);
	if ((S_ISLNK(st.st_mode)))
		return (1);
	else
		return (0);
}
