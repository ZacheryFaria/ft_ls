/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_majir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:27:15 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/25 10:41:01 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/xattr.h>

char	*long_major(struct stat st)
{
	return (ft_itoa(major(st.st_rdev)));
}

char	*long_minor(struct stat st)
{
	return (ft_itoa(minor(st.st_rdev)));
}
