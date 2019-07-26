/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_x_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:13:00 by vellery-          #+#    #+#             */
/*   Updated: 2019/06/28 18:13:01 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bin_no_preci(t_arg *arg, char *str, int len, int *flag)
{
	if (!arg->flags[2] && arg->flags[4] && *str != '0')
	{
		if (capit(arg->type) || lower(arg->type))
			arg->type == 'x' || arg->type == 'X' || arg->type == 'b'
				|| arg->type == 'B' ? add_char(arg, ' ', arg->width - len - 2) :
					add_char(arg, ' ', arg->width - len - 1);
		depend_on_type(arg);
		*flag = 1;
	}
	else if (arg->flags[2] && arg->flags[4] && *str != '0')
	{
		depend_on_type(arg);
		if (arg->type == 'X' || arg->type == 'x' ||
					arg->type == 'b' || arg->type == 'B')
			add_char(arg, '0', arg->width - len - 2);
		else if (arg->type == 'O' || arg->type == 'o')
			add_char(arg, '0', arg->width - len - 1);
		*flag = 1;
	}
}

void	save_to_buf_no_minus_bin(t_arg *arg, char *str, int len)
{
	int		flag;

	flag = 0;
	if (arg->preci <= 0)
	{
		bin_no_preci(arg, str, len, &flag);
		if (arg->flags[2] && !flag)
			add_char(arg, '0', arg->width - len);
		else if (!arg->flags[4] && !flag)
			add_char(arg, ' ', arg->width - len);
	}
	else
	{
		if (arg->flags[4] && (*str != '0'))
			depend_on_type(arg);
		add_char(arg, ' ', arg->width - arg->preci);
		(arg->type == 'o' || arg->type == 'O') && arg->flags[4] && *str != '0' ?
				add_char(arg, '0', arg->preci - len - 1) :
						add_char(arg, '0', arg->preci - len);
	}
	printf_concat(arg, str, len);
}

void	set_systems_bin(t_arg *arg, va_list va, char **ptr)
{
	char	*needed;
	int		len;

	arg->type = *arg->format++;
	if (*(arg->format - 1) == 'O' || *(arg->format - 1) == 'B')
	{
		arg->length[0] = arg->length[0] ? arg->length[0] : 'l';
		arg->length[1] = arg->length[1] ? arg->length[0] : '\0';
	}
	needed = get_in_ustring(arg, va, ptr);
	len = ft_strlen(needed);
	arg->preci = arg->preci > 0 && arg->preci <
			len ? -1 : arg->preci;
	if (arg->preci == 0 && *needed == '0' && ((!arg->flags[4] &&
					(arg->type == 'o' || arg->type == 'O')) ||
							(arg->type == 'x' || arg->type == 'X')))
	{
		no_preci(arg);
		return ;
	}
	arg->flags[2] = arg->flags[0] || arg->preci >= 0 ? 0 : arg->flags[2];
	if (arg->type >= 'A' && arg->type <= 'Z')
		set_uppercase(&needed);
	arg->flags[0] ? usave_to_buf_minus(arg, needed, len) :
				save_to_buf_no_minus_bin(arg, needed, len);
}
