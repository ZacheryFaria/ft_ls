/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:47:19 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 14:48:15 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>

void	long_size(const char *path)
{
	struct stat st;

	stat(path, &st);
	ft_putnbr(st.st_size);
}
