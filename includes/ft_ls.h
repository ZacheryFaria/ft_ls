/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:39:55 by zfaria            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/20 13:08:15 by zfaria           ###   ########.fr       */
=======
/*   Updated: 2019/02/20 13:11:17 by awindham         ###   ########.fr       */
>>>>>>> e0c293346bfe8621a9d23e73d3bd5fda4eec84d2
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
char	**reverse_tab(char **tab);
char	**flag_hide(char **str);
char	**sort_tab(char **tab, int (*cmp)(const char *s1, const char *s2));

void	longflag(char *path);
void	long_filetypes(const char *path);


#endif