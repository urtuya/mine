/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:24:38 by ydavis            #+#    #+#             */
/*   Updated: 2019/10/27 20:46:34 by ydavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_fastest(t_lemin *lemin)
{
	int		i;

	if (!lemin->fastest)
		check_malloc(lemin->fastest = (int*)malloc(sizeof(int) *
					lemin->node_count));
	i = 0;
	while (i < lemin->node_count)
	{
		lemin->fastest[i] = lemin->node_count + 1;
		i++;
	}
	lemin->fastest[lemin->start_index] = 0;
}

int		least_dist(t_lemin *lemin)
{
	int		i;
	int		least;
	int		min;

	i = 0;
	min = lemin->node_count + 1;
	least = -1;
	while (i < lemin->node_count)
	{
		if (lemin->fastest[i] < min && !lemin->visited[i])
		{
			min = lemin->fastest[i];
			least = i;
		}
		i++;
	}
	return (least);
}

void	set_fastest(t_lemin *lemin, int i, int j, int dist)
{
	lemin->edges[j][j] = i + 1;
	lemin->fastest[j] = dist;
}

void	clear_visited(t_lemin *lemin, int flag)
{
	int		i;
	int		j;
	t_path	*path;

	i = 0;
	while (i < lemin->node_count)
	{
		lemin->visited[i] = 0;
		path = lemin->paths;
		if (flag)
			while (path)
			{
				j = 0;
				while (path->path[j])
				{
					if (!ft_strcmp(lemin->names[i], path->path[j]->name) &&
							!path->path[j]->start && !path->path[j]->end)
						lemin->visited[i] = 1;
					j++;
				}
				path = path->next;
			}
		i++;
	}
}

t_path	*dijkstra(t_lemin *lemin)
{
	int		i;
	int		j;
	int		dist;

	init_fastest(lemin);
	while (1)
	{
		if ((i = least_dist(lemin)) < 0)
			break ;
		lemin->visited[i] = 1;
		j = 0;
		while (j < lemin->node_count)
		{
			if (i != j && lemin->edges[i][j] && !lemin->visited[j])
			{
				dist = lemin->edges[i][j] + lemin->fastest[i];
				if (lemin->fastest[j] > dist)
					set_fastest(lemin, i, j, dist);
			}
			j++;
		}
	}
	return (backtrack(lemin));
}
