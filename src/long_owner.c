/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_owner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:37:44 by awindham          #+#    #+#             */
/*   Updated: 2019/02/27 19:27:55 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <pwd.h>
#include <errno.h>

char	*long_owner(struct stat st)
{
	struct passwd *pw;

	pw = getpwuid(st.st_uid);
	if (!pw)
	{
		ft_printf("ft_ls: %s\n", strerror(errno));
		return (0);
	}
	return (ft_strdup(pw->pw_name));
}
