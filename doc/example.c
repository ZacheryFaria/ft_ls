/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:10:23 by awindham          #+#    #+#             */
/*   Updated: 2019/02/19 12:39:58 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

enum {
	Pathmax = 1024,
	
	File, Dir,
};

int recursive = 0;

char *
basename(char *s)
{
	char *p;
	
	if((p = strrchr(s, '/')) == 0)
		p = s;
	if(*p == '/')
		p++;
	return p;
}

void
output(char *path, int type)
{
	switch(type){
	case File:
		outputlong(path);
		printf("%s\n", basename(path));
		break;
	case Dir:
		if(recursive)
			printf("\n%s:\n", path);
		else
			printf("%s\n", basename(path));
		break;
	}
}

int
ls(char *path)
{
	DIR *d;
	struct dirent *e;
	struct stat st;
	char buf[Pathmax];

	if((d = opendir(path)) == NULL)
		exit(1);
	while((e = readdir(d)) != NULL){
		if(strcmp(e->d_name, ".") == 0
		|| strcmp(e->d_name, "..") == 0)
			continue;
		snprintf(buf, sizeof buf, "%s/%s", path, e->d_name);
		if(stat(buf, &st) < 0)
			exit(1);
		if(S_ISREG(st.st_mode)){
			output(buf, File);
		}else if(S_ISDIR(st.st_mode)){
			output(buf, Dir);
			if(recursive)
				ls(buf);
		}
	}
	closedir(d);
	return 0;
}

int
main(int argc, char *argv[])
{
	recursive = 1;

	if(argc == 1)
		ls(".");
	else
		while(--argc)
			ls(argv[argc]);
	return 0;
}