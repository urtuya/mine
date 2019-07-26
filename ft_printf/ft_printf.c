/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:37:45 by vellery-          #+#    #+#             */
/*   Updated: 2019/06/28 17:37:46 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		result(t_arg *arg)
{
	int ret;
	int i;

	i = 0;
	ret = arg->buf_len + arg->char_len + arg->full_len;
	write(1, arg->head, ret);
	if (arg->color)
		write(1, RES, 4);
	if (arg->head)
		free(arg->head);
	if (arg->head_format)
		free(arg->head_format);
	free(arg);
	return (ret);
}

void	save_this(t_arg *arg)
{
	*arg->buf++ = *arg->format++;
	arg->full_len++;
}

void	save_format(t_arg *arg, const char *format)
{
	if (!(arg->format = ft_strdup(format)))
		return ;
	arg->head_format = arg->format;
	arg->buf = ft_strnew(BUFF_SIZE);
	arg->ptr_buf_save = NULL;
	arg->head = arg->buf;
	arg->length[0] = '\0';
	arg->length[1] = '\0';
	arg->length[2] = '\0';
	arg->char_len = 0;
	arg->full_len = 0;
	arg->buf_len = 0;
	arg->color = 0;
}

int		ft_printf_(va_list args, const char *format)
{
	t_arg	*arg;

	arg = (t_arg*)malloc(sizeof(t_arg));
	save_format(arg, format);
	while (*arg->format)
	{
		if (*arg->format == '{')
			set_color(arg);
		if (*arg->format == '%' && *(arg->format + 1) != '%')
			set_all_fields(args, arg);
		else if (*arg->format == '%' && *(arg->format + 1) == '%')
		{
			save_this(arg);
			arg->format++;
		}
		else
			save_this(arg);
	}
	return (result(arg));
}

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	ret = 0;
	va_start(args, format);
	ret = ft_printf_(args, format);
	va_end(args);
	return (ret);
}
