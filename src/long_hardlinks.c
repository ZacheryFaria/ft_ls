/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_hardlinks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:28:01 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 13:46:09 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/stat.h>
#include <stdlib.h>

void	long_hardlinks(char *path)
{
	struct stat st;
	if ((stat(path, &st)) < 0)
		exit(-1);
	ft_putnbr(st.st_nlink);
}
