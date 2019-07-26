/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:01:47 by vellery-          #+#    #+#             */
/*   Updated: 2019/06/28 19:01:48 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_some_chars(t_arg *arg, int len)
{
	if (arg->type == 'X' || arg->type == 'x' || arg->type == 'o' ||
			arg->type == 'O' || arg->type == 'b' || arg->type == 'B')
		arg->type == 'o' || arg->type == 'O' ? add_char(arg, ' ',
					arg->width - len - 1) : add_char(arg, ' ',
							arg->width - len - 2);
}

void		usave_to_buf_minus(t_arg *arg, char *str, int len)
{
	if (arg->preci == -1)
	{
		if (arg->flags[4])
			depend_on_type(arg);
		printf_concat(arg, str, -1);
		if (arg->flags[2])
			add_char(arg, '0', arg->width - len);
		else if (!arg->flags[2] && arg->flags[4])
			add_some_chars(arg, len);
		else
			add_char(arg, ' ', arg->width - len);
	}
	else
	{
		add_char(arg, '0', arg->preci - len);
		printf_concat(arg, str, -1);
		add_char(arg, ' ', arg->width - arg->preci);
	}
}

void		usave_to_buf_no_minus(t_arg *arg, char *str, int len)
{
	if (arg->preci <= 0)
	{
		if (arg->flags[2])
			add_char(arg, '0', arg->width - len);
		else if (!arg->flags[2] && arg->flags[4] && *str != '0')
		{
			add_char(arg, ' ', arg->width - len - 1);
			printf_concat(arg, "0", 1);
		}
		else
			add_char(arg, ' ', arg->width - len);
	}
	else
	{
		add_char(arg, ' ', arg->width - arg->preci);
		add_char(arg, '0', arg->preci - len);
	}
	printf_concat(arg, str, -1);
}

char		*get_in_ustring(t_arg *arg, va_list va, char **ptr)
{
	uintmax_t	val;
	char		*str;

	val = va_arg(va, uintmax_t);
	if (arg->length[0] == 'h')
		val = arg->length[1] && arg->length[1] == 'h' ?
				(unsigned char)val : (short unsigned int)val;
	else if (arg->length[0] == 'l')
		val = arg->length[1] && arg->length[1] == 'l' ?
				(unsigned long int)val : (long unsigned int)val;
	else if (arg->length[0] == 'j' || arg->length[0] == 'z')
		val = arg->length[0] == 'j' ? val : (size_t)val;
	else if (arg->length[0] == 't')
		val = (ptrdiff_t)val;
	else
		val = (unsigned int)val;
	if (arg->type == 'u' || arg->type == 'U' ||
					arg->type == 'd' || arg->type == 'D')
		str = ft_uintmaxtoa(val, 10);
	arg->type == 'o' || arg->type == 'O' ? str = ft_uintmaxtoa(val, 8) : NULL;
	arg->type == 'x' || arg->type == 'X' || arg->type == 'p' ?
				str = ft_uintmaxtoa(val, 16) : NULL;
	arg->type == 'b' || arg->type == 'B' ? str = ft_uintmaxtoa(val, 2) : NULL;
	*ptr = str;
	return (str);
}

void		set_unsigned(t_arg *arg, va_list va, char **ptr)
{
	char	*needed;
	int		len;

	arg->type = *arg->format++;
	if (*(arg->format - 1) == 'U')
	{
		arg->length[0] = 'l';
		arg->length[1] = '\0';
	}
	needed = get_in_ustring(arg, va, ptr);
	len = ft_strlen(needed);
	if (arg->preci > 0 && arg->preci < len)
		arg->preci = -1;
	arg->flags[2] = arg->preci >= 0 ? 0 : arg->flags[2];
	if (arg->preci == 0 && *needed == '0')
	{
		no_preci(arg);
		return ;
	}
	arg->flags[0] ? usave_to_buf_minus(arg, needed, len) :
				usave_to_buf_no_minus(arg, needed, len);
}
