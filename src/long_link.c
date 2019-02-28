/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:19:33 by awindham          #+#    #+#             */
/*   Updated: 2019/02/27 18:51:43 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

char	*long_link(char *path)
{
	char *done;

	done = ft_strnew(1024);
	readlink(path, done, 1023);
	return (done);
}
