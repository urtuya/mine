/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:38:06 by vellery-          #+#    #+#             */
/*   Updated: 2019/06/28 17:44:05 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <float.h>
# define BUFF_SIZE 1024

# define RES "\x1b[0m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"

typedef struct	s_arg
{
	int		flags[5];
	int		width;
	int		preci;
	char	length[3];
	char	type;
	char	*format;
	char	*head_format;
	char	*buf;
	char	*head;
	int		char_len;
	int		full_len;
	int		buf_len;
	char	*ptr_buf_save;
	int		color;
}				t_arg;

int				ft_printf(const char *format, ...);
int				ft_printf_(va_list args, const char *format);
void			save_format(t_arg *arg, const char *format);
void			save_this(t_arg *arg);
int				result(t_arg *arg);

void			set_all_fields(va_list va, t_arg *arg);
void			set_fl_width_prec(t_arg *arg, va_list va);
void			set_width(t_arg *arg, va_list va);
void			set_precision(t_arg *arg, va_list va);
int				set_param(int *param, char *format);
void			refresh(t_arg *arg);

char			*ft_intmaxtoa(intmax_t val, int base);
char			*ft_uintmaxtoa(uintmax_t val, int base);

void			set_systems_bin(t_arg *arg, va_list va, char **ptr);
void			save_to_buf_no_minus_bin(t_arg *arg, char *str, int len);
void			bin_no_preci(t_arg *arg, char *str, int len, int *flag);

void			set_type(t_arg *arg, va_list va, char **ptr);
void			set_length(t_arg *arg);

void			set_unsigned(t_arg *arg, va_list va, char **ptr);
char			*get_in_ustring(t_arg *arg, va_list va, char **ptr);
void			add_some_chars(t_arg *arg, int len);
void			usave_to_buf_no_minus(t_arg *arg, char *str, int len);
void			usave_to_buf_minus(t_arg *arg, char *str, int len);

void			set_uppercase(char **str);
void			no_preci(t_arg *arg);
void			add_char(t_arg *arg, char c, int n);
void			printf_concat(t_arg *arg, const char *str, int len);

void			set_d(t_arg *arg, va_list va, char **ptr);
char			*get_in_string(t_arg *arg, va_list va, char **ptr);
void			save_to_buf_no_minus(t_arg *arg, char *str, int len, int f);
void			save_to_buf_minus(t_arg *arg, char *str, int len, int f);
void			set_char(t_arg *arg, va_list va);

char			*get_f_in_str(t_arg *arg, va_list va, char **ptr);
char			*ft_ftoa(long double val, int preci);
void			set_f(t_arg *arg, va_list va, char **ptr);

void			depend_on_type(t_arg *arg);
int				capit(char type);
int				lower(char type);

void			invalid_type(t_arg *arg);
void			set_ptr(t_arg *arg, va_list va, char **ptr);
void			p_minus(t_arg *arg, char *str, int len);
void			p_no_minus(t_arg *arg, char *str, int len);
void			set_string(t_arg *arg, va_list va);
void			str_no_minus_flag(t_arg *arg, char *str, int len);
void			str_minus_flag(t_arg *arg, char *str, int len);
void			set_char(t_arg *arg, va_list va);

void			set_color(t_arg *arg);
#endif
