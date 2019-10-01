/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 06:53:18 by ydavis            #+#    #+#             */
/*   Updated: 2019/10/01 18:41:53 by ydavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_cont	*find_cont(t_cont *cont)
{
	t_dirs *tmp;

	tmp = cont->dirs;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->cont);
}

void	free_split(char ***split)
{
	int		i;
	char	**tmp;

	tmp = *split;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	set_len(int *cont, char *str)
{
	int		len;

	if (!str)
	{
		*cont = 0;
		return ;
	}
	len = ft_strlen(str);
	*cont = max(len, *cont);
}

void	init_length(t_cont *cont)
{
	cont->total = 0;
	cont->link_len = 0;
	cont->own_len = 0;
	cont->grp_len = 0;
	cont->size_len = 0;
}

void	set_max_len(t_cont *cont)
{
	t_fil	*head;
	char	*tmp;

	head = cont->files;
	init_length(cont);
	while (head)
	{
		if (head->is_dir && cont->is_root && cont->from_av)
		{
			head = head->next;
			continue ;
		}
		cont->total += head->stat.st_blocks;
		set_len(&(cont->own_len), head->owner);
		set_len(&(cont->grp_len), head->group);
		tmp = ft_intmaxtoa(head->stat.st_nlink, 10);
		set_len(&(cont->link_len), tmp);
		free(tmp);
		tmp = ft_intmaxtoa(head->stat.st_size, 10);
		set_len(&(cont->size_len), tmp);
		free(tmp);
		head = head->next;
	}
}
