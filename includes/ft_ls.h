/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:39:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/20 14:49:07 by awindham         ###   ########.fr       */
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

void	longflag(char *path);
void	long_filetypes(const char *path);
void	long_permissions(const char *path);
void	long_hardlinks(const char *path);
void	long_owner(const char *path);
void	long_group(const char *path);
void	long_size(const char *path);
void	long_lastmod(const char *path);

#endif