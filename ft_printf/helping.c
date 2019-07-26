/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:28:34 by vellery-          #+#    #+#             */
/*   Updated: 2019/06/28 19:28:36 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	refresh(t_arg *arg)
{
	arg->flags[0] = 0;
	arg->flags[1] = 0;
	arg->flags[2] = 0;
	arg->flags[3] = 0;
	arg->flags[4] = 0;
	arg->width = 0;
	arg->preci = -1;
	arg->length[0] = '\0';
	arg->length[1] = '\0';
	arg->type = '\0';
}

void	depend_on_type(t_arg *arg)
{
	if (arg->type == 'x')
		printf_concat(arg, "0x", 2);
	else if (arg->type == 'X')
		printf_concat(arg, "0X", 2);
	else if (arg->type == 'o' || arg->type == 'O')
		printf_concat(arg, "0", 1);
	else if (arg->type == 'b')
		printf_concat(arg, "0b", 2);
	else if (arg->type == 'B')
		printf_concat(arg, "0B", 2);
}

int		capit(char type)
{
	if (type >= 65 && type <= 90)
		return (1);
	return (0);
}

int		lower(char type)
{
	if (type >= 97 && type <= 122)
		return (1);
	return (0);
}

void	set_color(t_arg *arg)
{
	if (ft_strstr(arg->format, "red"))
		write(1, RED, 6);
	else if (ft_strstr(arg->format, "green"))
		write(1, GREEN, 6);
	else if (ft_strstr(arg->format, "blue"))
		write(1, BLUE, 6);
	else if (ft_strstr(arg->format, "magenta"))
		write(1, MAGENTA, 6);
	else if (ft_strstr(arg->format, "cyan"))
		write(1, CYAN, 6);
	else if (ft_strstr(arg->format, "yel"))
		write(1, YELLOW, 6);
	else
		return ;
	while (*arg->format++ != '}')
		;
	arg->color = 1;
}
