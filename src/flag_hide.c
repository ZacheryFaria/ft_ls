/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:04:16 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/25 12:25:02 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	**flag_hide(char **str)
{
	char *base;

	while (*str)
	{
		base = basename(*str);
		if (*base == '.')
			str++;
		else
			break ;
	}
	return (str);
}
