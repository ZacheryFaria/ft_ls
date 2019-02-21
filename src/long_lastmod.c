/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_lastmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:49:24 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 19:04:50 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <time.h>

struct stat st;
char		*buf;

static void	pmonth()
{
	int i;
	int j;
	
	while (*buf++ != ' ')
		;
	i = 0;
	while (buf[i++] != ' ')
		;
	j = -1;
	while (j++ < 2)
		ft_putchar(buf[j]);
}

static void	pdate()
{
	while (!ft_isdigit(*buf))
		buf++;
	if (buf[1] == ' ')
		ft_putchar(' ');
	ft_putchar(buf[0]);
	if (isdigit(buf[1]))
		ft_putchar(buf[1]);
	buf += 3;
}

static void	ptime()
{	
	if (!ft_isdigit(buf[1]))
		ft_putchar(' ');
	while (ft_isdigit(*buf))
		ft_putchar(*buf++);
	ft_putchar(*buf++);
	while (ft_isdigit(*buf))
		ft_putchar(*buf++);
}

void		long_lastmod(const char *path)
{
	stat(path, &st);
	buf = ctime(&st.st_mtimespec.tv_sec);
	pmonth();
	ft_putchar(' ');
	pdate();
	ft_putchar(' ');
	ptime();
}
