/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_lastmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:49:24 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 14:52:29 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <time.h>

void	long_lastmod(const char *path)
{
	struct stat st;
	
	stat(path, &st);
	ft_putstr(ctime(&st.st_mtimespec.tv_sec));
}