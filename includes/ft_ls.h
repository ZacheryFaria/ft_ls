/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:39:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/21 13:18:16 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

extern int		recursive;
extern int		reverse;
extern int		show_hidden;
extern int		sort_time;
extern int		long_format;


int		dir_size(char *dirs);
char	**get_files(char *dirs);
char	**reverse_tab(char **tab);
char	**flag_hide(char **str);
char	**sort_tab(char **tab, int (*cmp)(const char *s1, const char *s2));
char	*basename(char *s);
int		isdir(const char *path);
int		time_cmp(const char *s1, const char *s2);
void	free_tab(char **tab);

void	longflag(char *path);
# include <sys/stat.h>
char	long_filetypes(struct stat st);
char	*long_permissions(struct stat st);
char	*long_hardlinks(struct stat st);
char	*long_owner(struct stat st);
char	*long_group(struct stat st);
char	*long_size(struct stat st);
char	*long_lastmod(struct stat st);

#endif