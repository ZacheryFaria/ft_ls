/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:37:40 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 14:44:54 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <grp.h>

void	long_group(char *path)
{
	struct stat st;
	struct group *g;
	
	stat(path, &st);
	if(( g = getgrgid(st.st_gid)) == 0)
		ft_putstr("bad");
	else
		ft_putstr(g->gr_name);
}
