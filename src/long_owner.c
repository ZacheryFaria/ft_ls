/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_owner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:37:44 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 15:32:39 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <pwd.h>

void	long_owner(char *path)
{
	struct stat st;

	stat(path, &st);
	ft_putstr(getpwuid(st.st_uid)->pw_name);
}
