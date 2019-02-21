/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_owner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:37:44 by awindham          #+#    #+#             */
/*   Updated: 2019/02/21 06:53:49 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <pwd.h>

char	*long_owner(struct stat st)
{
	return (getpwuid(st.st_uid)->pw_name);
}
