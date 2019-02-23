/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:39:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/22 17:33:03 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>

extern int		g_recursive;
extern int		g_reverse;
extern int		g_show_hidden;
extern int		g_sort_time;
extern int		g_long_format;
extern int		g_color;

int		dir_size(char *dirs);
char	**get_files(char *dirs);
char	**reverse_tab(char **tab);
char	**flag_hide(char **str);
char	**sort_tab(char **tab, int (*cmp)(const char *s1, const char *s2));
char	*basename(char *s);
int		isdir(const char *path);
int		islink(const char *path);
int		time_cmp(const char *s1, const char *s2);
void	free_tab(char **tab);
int		array_len(char **arr);

void	qsort_tab(char **list, int len, int (*f)(const char *, const char *));

char	**longflag(char *path);
char	long_filetypes(struct stat st);
char	*long_permissions(struct stat st);
char	*long_hardlinks(struct stat st);
char	*long_owner(struct stat st);
char	*long_group(struct stat st);
char	*long_size(struct stat st);
char	*long_lastmod(struct stat st);
int		*long_getmaxwidth(char ***s);

void	print_color(void);

#endif
