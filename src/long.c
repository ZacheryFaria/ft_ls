/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:01:15 by awindham          #+#    #+#             */
/*   Updated: 2019/02/21 07:45:35 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>
#include <sys/stat.h>

/* 
** Unix file types,
** permissions,
** number of hard links,
** owner,
** group,
** size,
** last-modified date
*/
char* (*f[6])(struct stat st) =
{
	long_permissions,
	long_hardlinks,
	long_owner,
	long_group,
	long_size,
	long_lastmod
};

void	longflag(char *path)
{
	int i;
	struct stat st;

	stat(path, &st);
	i = 0;
	while (i < 6)
	{
		ft_printpad(10 , " ", (*f[i])(st), 0);
		ft_printf(" ");
		i++;
	}
}
