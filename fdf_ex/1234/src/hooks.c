/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:51:52 by oargrave          #+#    #+#             */
/*   Updated: 2019/10/28 00:09:56 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		key_press(int keykode, t_fdf *fdf)
{
	if (keykode != 19 && keykode != 18 && keykode != 27 && keykode != 24
		&& keykode != 20 && keykode != 6 && keykode != 53)
		return (0);
	if (keykode == 53)
		exit(0);
	fdf->ang.a_y = 0.0;
	fdf->ang.a_z = 0.0;
	if (keykode == 19)
		parallel_projection(fdf);
	else if (keykode == 18)
	{
		fdf->proj = ISO;
		fdf->siz = fdf->prev_siz;
		fdf->ang.a_x = 0.0;
		clean_main_map(fdf);
	}
	else if ((keykode == 27 || keykode == 24))
		drawing_height(keykode, fdf);
	if (keykode == 20 || keykode == 6)
		color_rendering(keykode, fdf);
	mlx_clear_window(fdf->full->mlx, fdf->full->win);
	print_help(fdf->full);
	draw(fdf, fdf->proj ? matrix : set_iso_coords);
	return (0);
}

void	color_rendering(int keykode, t_fdf *fdf)
{
	fdf->ang.a_x = 0.0;
	if (keykode == 20)
	{
		if (fdf->color == 0x9933FF || fdf->color == 0x0000FF)
			fdf->color = 0xFF0000;
		else if (fdf->color == 0xFF0000)
			fdf->color = 0x00FF00;
		else if (fdf->color == 0x00FF00)
			fdf->color = 0x0000FF;
	}
	if (keykode == 6)
		fdf->color = 0x9933FF;
}

int		mouse_press(int btn, int x, int y, t_fdf *fdf)
{
	if (x < 0 || x > HEI || y < 0 || y > WID)
		return (1);
	fdf->ang.a_x = 0.0;
	fdf->ang.a_y = 0.0;
	fdf->ang.a_z = 0.0;
	if (btn == 1)
		fdf->ms.left = 1;
	else if ((btn == 4 || btn == 5))
	{
		fdf->siz *= btn == 4 ? 1.1 : 0.9;
		mlx_clear_window(fdf->full->mlx, fdf->full->win);
		draw(fdf, fdf->proj ? matrix : set_iso_coords);
		print_help(fdf->full);
	}
	return (0);
}

int		mouse_release(int btn, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (btn == 1)
		fdf->ms.left = 0;
	return (0);
}

int		mouse_move(int x, int y, t_fdf *fdf)
{
	int	prev_x;
	int	prev_y;

	if (x < 0 || x > HEI || y < 0 || y > WID)
		return (1);
	prev_x = fdf->ms.x;
	prev_y = fdf->ms.y;
	fdf->ms.x = x;
	fdf->ms.y = y;
	if (fdf->ms.left == 1)
	{
		fdf->ang.a_y = (double)(y - prev_y) * 0.2;
		fdf->ang.a_x = (double)(x - prev_x) * 0.2;
		fdf->ang.a_z = (double)((x - prev_x) / 2 + (y - prev_y) / 2) * 0.2;
		mlx_clear_window(fdf->full->mlx, fdf->full->win);
		draw(fdf, fdf->proj ? matrix : set_iso_coords);
		print_help(fdf->full);
	}
	return (0);
}
