#include "head.h"

static void		draw_lines(t_fdf *fdf, t_3dmap map1, t_3dmap map2)
{
	t_coor	cr1;
	t_coor	cr2;
	int		color;

	cr1.x = (int)map1.x;
	cr1.y = fdf->proj == PARALLEL ? (int)map1.z : (int)map1.y;
	cr2.x = (int)map2.x;
	cr2.y = fdf->proj == PARALLEL ? (int)map2.z : (int)map2.y;
	color = fdf->color;
	draw_line(fdf->full, cr1, cr2, color);
}

void			draw(t_fdf *fdf, void (*projection)(t_3dmap *map, double val, double val2))
{
	int		i;
	int		j;
	t_3dmap	now;
	t_3dmap	next;

	rotate(fdf);
	i = -1;
	while (++i < fdf->full->hei)
	{
		j = -1;
		while (++j < fdf->full->wid)
		{
			now = fdf->map[i][j];
			projection(&now, fdf->r, fdf->siz);
			if (j < fdf->full->wid - 1)
			{
				next = fdf->map[i][j + 1];
				projection(&next, fdf->r, fdf->siz);
				draw_lines(fdf, now, next);
			}
			if (i < fdf->full->hei - 1)
			{
				next = fdf->map[i + 1][j];
				projection(&next, fdf->r, fdf->siz);
				draw_lines(fdf, now, next);
			}
		}
	}
}