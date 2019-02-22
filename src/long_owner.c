/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_owner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:37:44 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 10:46:31 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <pwd.h>

char	*long_owner(struct stat st)
{
	return (ft_strdup(getpwuid(st.st_uid)->pw_name));
}
