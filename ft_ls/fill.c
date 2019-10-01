/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 07:40:11 by ydavis            #+#    #+#             */
/*   Updated: 2019/10/01 18:38:59 by ydavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_details(t_fil *file)
{
	struct group	*grp;
	struct passwd	*tf;

	file->group = NULL;
	file->owner = NULL;
	if ((grp = getgrgid(file->stat.st_gid)))
		file->group = ft_strdup(grp->gr_name);
	else
	{
		just_perror(file->full_path);
		g_ret = 1;
	}
	if ((tf = getpwuid(file->stat.st_uid)))
		file->owner = ft_strdup(tf->pw_name);
	else
	{
		just_perror(file->full_path);
		g_ret = 1;
	}
}

char	*set_fullname(char *fold, char *file)
{
	char	*ret;
	int		foldlen;
	int		filelen;

	foldlen = ft_strlen(fold);
	filelen = ft_strlen(file);
	if (fold[foldlen - 1] != '/')
	{
		check_malloc(ret = ft_strnew(foldlen + filelen + 1));
		ret = ft_strcat(ret, fold);
		ret = ft_strcat(ret, "/");
		ret = ft_strcat(ret, file);
	}
	else
	{
		check_malloc(ret = ft_strnew(foldlen + filelen));
		ret = ft_strcat(ret, fold);
		ret = ft_strcat(ret, file);
	}
	return (ret);
}

void	set_numbers(t_cont *cont, int i, int flag)
{
	int plus_8;

	plus_8 = 0;
	while (cont->mlen >= plus_8)
		plus_8 += 8;
	cont->mlen = plus_8;
	if (!flag)
		return ;
	cont->dir_num = i - cont->fil_num;
	cont->num = cont->fil_num;
	set_max_len(cont);
}

void	init_mlen(t_cont *cont)
{
	cont->mlen = 0;
	cont->fil_num = 0;
	cont->dir_num = 0;
}

int		fill_files_from_path(t_cont *cont, t_fl fl)
{
	DIR				*d;
	t_fil			*head;
	int				i;

	init_mlen(cont);
	if (!(d = opendir(cont->name)))
	{
		just_perror(cont->name);
		g_ret = 1;
		cont->files = NULL;
		return (-1);
	}
	check_malloc(cont->files = (t_fil*)malloc(sizeof(t_fil)));
	head = cont->files;
	i = fill_cycle(d, cont, fl, head);
	check_head(&(cont->files), i);
	set_numbers(cont, 0, 0);
	cont->num = i;
	closedir(d);
	if (!i)
	{
		free(cont->files);
		cont->files = NULL;
	}
	return (0);
}
