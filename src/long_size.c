/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:47:19 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 13:43:58 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>

char	*long_size(struct stat st)
{
	return (ft_itoa(st.st_size));
}
