/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:15:54 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/15 13:39:22 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>
#include <stdio.h>
#include <ft_ls.h>
#include <sys/stat.h>

int main(void)
{
	char **list = get_files(".");
	list = sort_tab(list, ft_strcmp);
	while (*list)
	{
		printf("%-10s ", *list);
		struct stat buf;
		stat(*list, &buf);
		list++;
	}
}
