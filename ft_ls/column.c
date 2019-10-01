/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:17:39 by ydavis            #+#    #+#             */
/*   Updated: 2019/09/29 21:10:40 by ydavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_size(t_cont *cont)
{
	struct winsize	ws;
	float			max_col;
	float			num_lines;
	float			real_col_num;

	if (cont->mlen == 0 || cont->num == 0)
		return (0);
	ioctl(0, TIOCGWINSZ, &ws);
	max_col = ws.ws_col / cont->mlen;
	num_lines = cont->num / max_col;
	if (num_lines - (int)num_lines)
		num_lines++;
	real_col_num = (float)cont->num / (int)num_lines;
	if (real_col_num - (int)real_col_num != 0)
		real_col_num++;
	cont->col = (int)real_col_num;
	cont->lin = (int)num_lines;
	if (cont->col < 1 || cont->lin < 1)
		return (2);
	return (1);
}

void	concat_filenames(char *to, char *name, int max_len, int full_len)
{
	int i;

	i = 0;
	while (to[i])
		i++;
	ft_strcat(to + i, name);
	i += ft_strlen(name);
	if (max_len != full_len)
		while (i < max_len)
			to[i++] = ' ';
	to[i] = '\0';
}

void	structure_cycle(t_cont *cont, int i)
{
	int		j;
	int		num;
	char	*name;

	j = 0;
	num = i;
	while (j < cont->col)
	{
		if (num < cont->num && (!cont->faddr[num]->is_dir || !cont->from_av))
			name = cont->faddr[num]->name;
		else
			name = NULL;
		if (name)
			concat_filenames(cont->ret[i], name, cont->mlen * (j + 1),
				cont->mlen * cont->col);
		num += cont->lin;
		j++;
	}
}

void	get_structured(t_cont *cont)
{
	int		i;

	check_malloc(cont->ret = (char**)malloc(sizeof(char*) * (cont->lin + 1)));
	i = 0;
	while (i < cont->lin)
	{
		check_malloc(cont->ret[i] = ft_strnew(cont->mlen * cont->col));
		i++;
	}
	cont->ret[i] = NULL;
	i = 0;
	while (i < cont->lin)
	{
		structure_cycle(cont, i);
		i++;
	}
}

void	normal_print(t_cont *cont, t_fl fl)
{
	int i;
	int flag;

	i = 0;
	flag = get_size(cont);
	if (flag == 2)
	{
		onestr_print(cont, fl);
		return ;
	}
	if (!flag)
		return ;
	get_structured(cont);
	while (cont->ret[i])
	{
		ft_printf("%s\n", cont->ret[i]);
		free(cont->ret[i]);
		i++;
	}
	free(cont->ret);
}
