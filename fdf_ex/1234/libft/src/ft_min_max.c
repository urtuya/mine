/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <vellery-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:43:08 by vellery-          #+#    #+#             */
/*   Updated: 2019/10/27 19:43:53 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_min(intmax_t a, intmax_t b)
{
	return (a < b ? a : b);
}

intmax_t	ft_max(intmax_t a, intmax_t b)
{
	return (a > b ? a : b);
}
