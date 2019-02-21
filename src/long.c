/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:01:15 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 18:31:38 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>

/* 
** Unix file types,
** permissions,
** number of hard links,
** owner,
** group,
** size,
** last-modified date
*/
void (*f[6])(const char *) =
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

	i = 0;
	while (i < 6)
	{
		(*f[i])(path);
		ft_putchar(' ');
		i++;
	}
}
