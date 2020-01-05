/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:30:50 by ydavis            #+#    #+#             */
/*   Updated: 2019/10/26 18:33:59 by ydavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	unsigned char	i;

	i = (unsigned char)c;
	if (c <= 255 && c >= 0)
		if (i == ' ' || (i >= 9 && i <= 13))
			return (1);
	return (0);
}