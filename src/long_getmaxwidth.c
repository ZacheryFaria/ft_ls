/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_getmaxwidth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:48:46 by awindham          #+#    #+#             */
/*   Updated: 2019/02/22 10:59:11 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int	largest(char ***s, int i)
{
	int done = 0;
	int j = 0;
	
	while (s[j])
	{
		if (done < (int)ft_strlen(s[j][i]))
			done = (int)ft_strlen(s[j][i]);
		j++;
	}
	return (done + 1);
}

int	*long_getmaxwidth(char ***s)
{
	int *done = malloc(7 * sizeof(*done));
	done[0] = largest(s, 0) - 1;
	done[1] = largest(s, 1);
	done[2] = largest(s, 2);
	done[3] = largest(s, 3);
	done[4] = largest(s, 4);
	done[5] = largest(s, 5);
	done[6] = largest(s, 6);
	return (done);
}
