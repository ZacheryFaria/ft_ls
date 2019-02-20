/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:01:15 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 13:48:28 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	longflag(char *path)
{
	/* Unix file types, */
	long_filetypes(path);
	/* permissions, */
	long_permissions(path);
	/* number of hard links, */
	long_hardlinks(path);
	/* owner, */
	long_owner(path);
	/* group, */
	/* size, */
	/* last-modified date, */
	/* filename */
}