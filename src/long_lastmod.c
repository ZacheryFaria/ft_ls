/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_lastmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:49:24 by awindham          #+#    #+#             */
/*   Updated: 2019/02/25 15:52:27 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <time.h>

#define SIX 15552000

char	*long_lastmod(struct stat st)
{
	char	*done;
	time_t	curr;
	time_t	file_time;

	time(&curr);
	file_time = st.st_mtimespec.tv_sec;
	done = ctime(&st.st_mtimespec.tv_sec);
	done += 4;	
	if (file_time - curr > SIX || curr - file_time > SIX)
	{
		ft_memmove(done + 7, done + 15, 5);
		done[12] = 0;
	}
	else
		done[12] = 0;
	return (ft_strdup(done));
}
