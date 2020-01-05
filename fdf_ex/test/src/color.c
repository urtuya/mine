#include "head.h"

int get_light(int start, int end, double percentage)
{
	int	ret;
	ret = ((float)end + (percentage) * (start - end));// + percentage * end);
    if (ret == 0)
	{
		printf("start = %d end = %d percent = %f\n", start, end, percentage);
	}
	return (ret);//(int)((1 - percentage) * start + percentage * end));
}

double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_color(t_line ln, t_color color)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (color.start == color.end)
        return (color.end);
    if (ln.abs_dx >= ln.abs_dy)
        percentage = percent(ln.xstart, ln.xe, ln.x);
    else
        percentage = percent(ln.ystart, ln.ye, ln.y);
	printf("PECENTAGE: %f\n", percentage);
    red = get_light((color.start >> 16) & 0xFF, (color.end >> 16) & 0xFF, percentage);
    green = get_light((color.start >> 8) & 0xFF, (color.end >> 8) & 0xFF, percentage);
    blue = get_light(color.start & 0xFF, color.end & 0xFF, percentage);
	
	return ((red << 16) | (green << 8) | blue);
}

void	set_color(t_color *color, t_fdf *fdf, t_coor cr1, t_coor cr2)
{
	int		red;
	int		green;
	int		blue;
	printf("z1 = %d dist = %d\n", cr1.z, fdf->col.dist);
	printf("z2 = %d dist = %d\n", cr2.z, fdf->col.dist);

	red = ((fdf->col.start >> 16) & 0xFF) + (((fdf->col.end >> 16) & 0xFF) - ((fdf->col.start >> 16) & 0xFF)) * cr1.z / fdf->col.dist;
	green = ((fdf->col.start >> 8) & 0xFF) + (((fdf->col.end >> 8) & 0xFF) - ((fdf->col.start >> 8) & 0xFF)) * cr1.z / fdf->col.dist;
	blue = (fdf->col.start & 0xFF) + ((fdf->col.end & 0xFF) - (fdf->col.start & 0xFF)) * cr1.z / fdf->col.dist;

	color->start = red << 16 | green << 8 | blue;

	red = ((fdf->col.start >> 16) & 0xFF) + (((fdf->col.end >> 16) & 0xFF) - ((fdf->col.start >> 16) & 0xFF)) * cr2.z / fdf->col.dist;
	green = ((fdf->col.start >> 8) & 0xFF) + (((fdf->col.end >> 8) & 0xFF) - ((fdf->col.start >> 8) & 0xFF)) * cr2.z / fdf->col.dist;
	blue = (fdf->col.start & 0xFF) + ((fdf->col.end & 0xFF) - (fdf->col.start & 0xFF)) * cr2.z / fdf->col.dist;

	color->end = red << 16 | green << 8 | blue;
	printf("FDFend: %d\n", fdf->col.end);
	printf("FDFstart: %d\n", fdf->col.start);
	printf("start %d\n", color->start);
	printf("end %d\n", color->end);
	// return(color);
}