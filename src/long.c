/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:01:15 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 18:22:14 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>

void	longflag(char *path)
{
	/* Unix file types, */
	long_filetypes(path);
	/* permissions, */
	long_permissions(path);
	ft_putstr("  ");
	/* number of hard links, */
	long_hardlinks(path);
	ft_putstr(" ");
	/* owner, */
	long_owner(path);
	ft_putstr(" ");
	/* group, */
	long_group(path);
	ft_putstr(" ");
	/* size, */
	long_size(path);
	ft_putstr(" ");
	/* last-modified date, */
	long_lastmod(path);
}
