#include "head.h"

static void	init_line(t_line *ln, t_coor cr1, t_coor cr2)
{
	ln->dx = cr2.x - cr1.x;
	ln->dy = cr2.y - cr1.y;
	ln->abs_dx = abs(ln->dx);
	ln->abs_dy = abs(ln->dy);
	ln->sx = 2.0 * ln->abs_dy - ln->abs_dx;
	ln->sy = 2.0 * ln->abs_dx - ln->abs_dy;
}

static void	init_xy(t_line *ln, t_coor cr1, t_coor cr2, int axis)
{
	if (!axis && ln->dx >= 0)
	{
		ln->x = cr1.x;
		ln->y = cr1.y;
		ln->xe = cr2.x;
	}
	else if (!axis && ln->dx < 0)
	{
		ln->x = cr2.x;
		ln->y = cr2.y;
		ln->xe = cr1.x;
	}
	else if (axis && ln->dy >= 0)
	{
		ln->x = cr1.x;
		ln->y = cr1.y;
		ln->ye = cr2.y;
	}
	else if (axis && ln->dy < 0)
	{
		ln->x = cr2.x;
		ln->y = cr2.y;
		ln->ye = cr1.y;
	}
}

static void	draw_x(t_line ln, t_map *fdf, int color)
{
	while (ln.x < ln.xe)
	{
		if (!(ln.x + fdf->offx < 0 || ln.x + fdf->offx > HEI ||
				ln.y + fdf->offy < 0 || ln.y + fdf->offy > WID))
			mlx_pixel_put(fdf->mlx, fdf->win, ln.x + fdf->offx,
						ln.y + fdf->offy, color);
		ln.x++;
		if (ln.sx < 0)
			ln.sx += 2 * ln.abs_dy;
		else
		{
			ln.y += (ln.dx < 0 && ln.dy < 0) || (ln.dx > 0 && ln.dy > 0) ?
					1 : -1;
			ln.sx += 2 * (ln.abs_dy - ln.abs_dx);
		}
	}
}

static void	draw_y(t_line ln, t_map *fdf, int color)
{
	while (ln.y < ln.ye)
	{
		if (!(ln.x + fdf->offx < 0 || ln.x + fdf->offx > HEI ||
				ln.y + fdf->offy < 0 || ln.y + fdf->offy > WID))
			mlx_pixel_put(fdf->mlx, fdf->win, ln.x + fdf->offx,
						ln.y + fdf->offy, color);
		ln.y++;
		if (ln.sy <= 0)
			ln.sy += 2 * ln.abs_dx;
		else
		{
			ln.x += (ln.dx < 0 && ln.dy < 0) || (ln.dx > 0 && ln.dy > 0) ?
					1 : -1;
			ln.sy += 2 * (ln.abs_dx - ln.abs_dy);
		}
	}
}

void	draw_line(t_map *fdf, t_coor cr1, t_coor cr2, int color)
{
	t_line ln;

	init_line(&ln, cr1, cr2);
	if (ln.abs_dy <= ln.abs_dx)
	{
		init_xy(&ln, cr1, cr2, 0);
		draw_x(ln, fdf, color);
	}
	else
	{
		init_xy(&ln, cr1, cr2, 1);
		draw_y(ln, fdf, color);
	}
}
