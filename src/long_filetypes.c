/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_filetypes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:04:40 by awindham          #+#    #+#             */
/*   Updated: 2019/02/25 17:00:24 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

char	long_filetypes(struct stat st)
{
	if ((S_ISDIR(st.st_mode)))
		return ('d');
	if ((S_ISLNK(st.st_mode)))
		return ('l');
	if ((S_ISCHR(st.st_mode)))
		return ('c');
	if ((S_ISBLK(st.st_mode)))
		return ('b');
	if ((S_ISSOCK(st.st_mode)))
		return ('s');
	if ((S_ISFIFO(st.st_mode)))
		return ('p');
	return ('-');
}
