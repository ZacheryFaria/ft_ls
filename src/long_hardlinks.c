/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_hardlinks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:28:01 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 13:36:31 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/stat.h>

void	long_hardlinks(path)
{
	struct stat st;
	if ((stat(path, &st)) == NULL)
		exit(-1);
	ft_putnbr(st.st_ino);
}
