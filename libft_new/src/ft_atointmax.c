#include "libft.h"

int set_base(char **num, int base, int *ret)
{
	*ret = 0;
	while (**num && ft_isspace(**num))
		(*num)++;
	if (base == 0)
	{
		if (**num == '0')
		{
			(*num) += 1;
			if (**num == 'x')
			{
				(*num) += 1;
				base = 16;
			}
			else
				base = **num == 'b' ? 2 : 8;
		}
		else
			base = 10;
	}
	else if (base == 16)
	{
		if (*num[0] == '0' && *num[1] == 'x')
			(*num) += 2;
	}
	return (base);
}

char	cvt_in_sign(int digit, char **str, int base, int flag)
{
	static char arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	100, 100, 100, 100, 100, 100, 100,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35,
	100, 100, 100, 100, 100, 100,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35};

	if (!flag && base == 10 && **str == '-')
	{
		(*str) += 1;
		return (-1);
	}
	else if (!flag)
		return (1);
	else
		return (arr[digit]);
}

int			if_sign(char **str, int base)
{
	if (base == 10 && **str == '-')
	{
		(*str) += 1;
		return (-1);
	}
	return (1);
}

intmax_t	get_ret_from_base(int base, intmax_t ret, int digit)
{
	if (base == 8)
		ret = (ret << 3) + digit;
	else if (base == 10)
		ret = (10 * ret) + digit;
	else if (base == 16)
	{
		digit = cvt_in(digit);
		ret = (ret << 4) + digit;
	}
	return (ret);
}

intmax_t	ft_atointmax(char *str, int base)
{
	int			digit;
	int			sign;
	intmax_t	ret;

	base = set_base(&str, base, &ret);
	sign = if_sign(&str, base);
	while (*str)
	{
		digit = *str - '0';
		if (((base == 8 || base == 10) && digit > base - 1) ||
			(base == 16 && digit > ('z' - '0')))
			break ;
		if (base == 8 || base == 10 || base == 16)
			ret = get_get_from_base(base, ret, digit);
		else
		{
			if (digit > ('z' - '0'))
				break ;
			digit = cvt_in(digit);
			if (digit >= base)
				break ;
			ret = ret * base + digit;
		}
		str++;
	}
	return (ret * sign);
}