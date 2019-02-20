/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:39:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/20 11:51:35 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <dirent.h>

int		recursive;
int		reverse;
int		show_hidden;
int		sort_time;
int		long_format;


int		dir_size(char *dirs);
char	**get_files(char *dirs);
char	**filter_default(char **files);
char	**sort_tab(char **tab, int (*cmp)(const char *s1, const char *s2));

#endif