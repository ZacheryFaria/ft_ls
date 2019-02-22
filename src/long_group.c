/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:37:40 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 10:46:59 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <grp.h>

char	*long_group(struct stat st)
{
	struct group	*g;

	if ((g = getgrgid(st.st_gid)) == 0)
		return ("bad");
	else
		return (ft_strdup(g->gr_name));
}
