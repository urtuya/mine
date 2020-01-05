/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:17:19 by ydavis            #+#    #+#             */
/*   Updated: 2019/10/26 18:19:09 by ydavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*find_str(t_lemin *lemin, char *str)
{
	t_node	*node;
	char	*ret;

	node = lemin->nodes;
	ret = NULL;
	while (node)
	{
		if (ft_strstr(str, node->name) == str)
		{
			ret = node->name;
			break ;
		}
		node = node->next;
	}
	if (!ret)
		error_msg("ERROR\n");
	return (ret);
}
