/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_hardlinks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:28:01 by awindham          #+#    #+#             */
/*   Updated: 2019/02/21 07:10:51 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/stat.h>
#include <stdlib.h>

char	*long_hardlinks(struct stat st)
{
	return (ft_itoa(st.st_nlink));
}
