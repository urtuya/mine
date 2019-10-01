/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 02:08:07 by ydavis            #+#    #+#             */
/*   Updated: 2019/10/01 19:22:25 by ydavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_xattr(char *path)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;
	char		sym;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	xattr = xattr < 0 ? 0 : xattr;
	sym = ' ';
	if (xattr > 0)
		sym = '@';
	else if (acl != NULL)
		sym = '+';
	acl_free(acl);
	ft_printf("%c ", sym);
}

void	print_time(struct stat stat)
{
	char		**split;
	char		*ret;
	static long	tmp = 0;
	int			i;

	if (!tmp)
		time(&tmp);
	ret = ctime(&stat.st_mtime);
	ret = ret + 4;
	if (ft_labs(tmp - stat.st_mtime) >= ((365 / 2) * 86400))
	{
		split = ft_strsplit(ret, ' ');
		i = ft_strlen(split[3]);
		split[3][i - 1] = '\0';
		ft_printf(" %s", split[0]);
		if (ft_strlen(split[1]) == 1)
			ft_printf(" ");
		ft_printf(" %s", split[1]);
		ft_printf("  %s", split[3]);
		free_split(&split);
	}
	else
	{
		*(ret + ft_strlen(ret) - 8) = '\0';
		ft_printf(" %-.*s", (int)ft_strlen(ret) - 1, ret);
	}
}

void	detail_print(t_cont *cont, t_fl fl)
{
	int		i;
	t_fil	*file;

	(void)fl;
	i = 0;
	while (cont->faddr[i])
	{
		file = cont->faddr[i];
		if (file->is_dir && cont->from_av && cont->is_root)
		{
			i++;
			continue ;
		}
		print_type(file->stat.st_mode);
		print_permissions(file->stat.st_mode);
		print_xattr(file->full_path);
		ft_printf("%*hu ", cont->link_len, file->stat.st_nlink);
		print_owngroup(file, cont);
		print_size(cont, file);
		print_time(file->stat);
		ft_printf(" %s", file->name);
		print_link(file);
		ft_printf("\n");
		i++;
	}
}

void	onestr_print(t_cont *cont, t_fl fl)
{
	int i;

	(void)fl;
	i = 0;
	while (cont->faddr[i])
	{
		if (cont->faddr[i]->is_dir && cont->from_av && cont->is_root)
		{
			i++;
			continue ;
		}
		ft_printf("%s\n", cont->faddr[i]->name);
		i++;
	}
}

void	print_master(t_cont *cont, t_fl fl, int ac)
{
	void	(*print)(t_cont *cont, t_fl fl);

	(void)ac;
	if (fl.l)
		print = detail_print;
	else if (fl.one)
		print = onestr_print;
	else
		print = normal_print;
	if (fl.l && (!cont->from_av || !cont->is_root) && cont->num)
		ft_printf("total %d\n", cont->total);
	print(cont, fl);
}
