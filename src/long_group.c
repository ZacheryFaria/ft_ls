/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:37:40 by awindham          #+#    #+#             */
/*   Updated: 2019/02/21 06:51:57 by awindham         ###   ########.fr       */
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
		return (g->gr_name);
}
