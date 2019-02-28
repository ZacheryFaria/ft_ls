/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_getmaxwidth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:48:46 by awindham          #+#    #+#             */
/*   Updated: 2019/02/27 20:07:40 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_ls.h>

int	largest(char ***s, int i)
{
	int done;
	int j;

	done = 0;
	j = 0;
	while (s[j])
	{
		if (done < (int)ft_strlen(s[j][i]) && (g_show_hidden ||
			(!g_show_hidden && basename(s[j][10])[0] != '.')))
			done = (int)ft_strlen(s[j][i]);
		j++;
	}
	return (done + 1);
}

int	*long_getmaxwidth(char ***s)
{
	int *done;

	done = malloc(7 * sizeof(*done));
	done[0] = largest(s, 0) - 1;
	done[1] = largest(s, 1) - 1;
	done[2] = largest(s, 2) + 1;
	done[3] = largest(s, 3);
	done[4] = largest(s, 4);
	done[5] = largest(s, 5);
	done[6] = largest(s, 6);
	return (done);
}
