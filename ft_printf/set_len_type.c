/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:18:09 by vellery-          #+#    #+#             */
/*   Updated: 2019/06/28 19:18:10 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_length(t_arg *arg)
{
	if (*arg->format == 'h')
		*(arg->format + 1) && *(arg->format + 1) == 'h' ?
				ft_strcpy(arg->length, "hh") : ft_strcpy(arg->length, "h");
	else if (*arg->format == 'l')
		*(arg->format + 1) && *(arg->format + 1) == 'l' ?
				ft_strcpy(arg->length, "ll") : ft_strcpy(arg->length, "l");
	else if (*arg->format == 'z' || *arg->format == 'j')
		arg->length[0] = *arg->format == 'z' ? 'z' : 'j';
	else if (*arg->format == 'L' || *arg->format == 't')
		arg->length[0] = *arg->format == 'L' ? 'L' : 't';
	if (arg->length[0])
		arg->format += arg->length[0] && arg->length[1] ? 2 : 1;
}

void	set_type(t_arg *arg, va_list va, char **ptr)
{
	if (*arg->format == 'd' || *arg->format == 'i' ||
			(*arg->format == 'D' && arg->length[0] != 'z'))
		set_d(arg, va, ptr);
	else if (*arg->format == 'u' || *arg->format == 'U' ||
				(((*arg->format == 'd') || *arg->format == 'i'
						|| *arg->format == 'D') && arg->length[0] == 'z'))
		set_unsigned(arg, va, ptr);
	else if (*arg->format == 'o' || *arg->format == 'O' || *arg->format == 'x'
		|| *arg->format == 'X' || *arg->format == 'b' || *arg->format == 'B')
		set_systems_bin(arg, va, ptr);
	else if (*arg->format == 'c' || *arg->format == 'C')
		set_char(arg, va);
	else if (*arg->format == 's' || *arg->format == 'S')
		set_string(arg, va);
	else if (*arg->format == 'p')
		set_ptr(arg, va, ptr);
	else if (*arg->format == 'f' || *arg->format == 'F')
		set_f(arg, va, ptr);
	else if (*arg->format != '\0')
		invalid_type(arg);
}
