/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_lastmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:49:24 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 13:43:17 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <time.h>

char	*long_lastmod(struct stat st)
{
	char	*done;

	done = ctime(&st.st_mtimespec.tv_sec);
	done += 4;
	done[12] = 0;
	return (ft_strdup(done));
}
