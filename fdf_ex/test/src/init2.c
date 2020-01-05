/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <vellery-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:52:35 by oargrave          #+#    #+#             */
/*   Updated: 2019/10/27 19:50:14 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void		check_valid(t_fdf *fdf, char *line)
{
	int		i;
	char	**tmp;

	if (!line || !*line)
		print_error("Error while reading map");
	check_malloc(tmp = ft_strsplit(line, ' '));
	i = 0;
	while (tmp[i])
		i++;
	if (!fdf->full->wid)
		fdf->full->wid = i;
	else if (fdf->full->wid != i)
		print_error("map error");
	ft_freesplit(tmp);
}

void			read_map(t_fdf *fdf, int fd)
{
	char	*line;
	int		hei_count;
	int		gnl;

	hei_count = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		check_valid(fdf, line);
		ft_strdel(&line);
		hei_count++;
	}
	fdf->full->hei = hei_count;
	close(fd);
	if (fdf->full->hei < 2 && fdf->full->wid < 2)
		print_error("Invalid map");
}

/*
** hooks two
*/

void			parallel_projection(t_fdf *fdf)
{
	fdf->proj = PARALLEL;
	fdf->siz = fdf->prev_siz * 2.1;
	fdf->ang.a_x = 120.0;
	fdf->h_zarr = 1.0;
	clean_main_map(fdf);
	find_min_max(fdf);
}

void			drawing_height(int keykode, t_fdf *fdf)
{
	fdf->ang.a_x = fdf->proj ? 120.0 : 0.0;
	fdf->h_zarr *= keykode == 24 ? 1.1 : 0.9;
	if (fdf->h_zarr > 7.0 && fdf->proj == ISO)
		fdf->h_zarr = 7.0;
	else if (fdf->h_zarr > 5.0 && fdf->proj == PARALLEL)
		fdf->h_zarr = 5.0;
	clean_main_map(fdf);
}
