/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:06:21 by vellery-          #+#    #+#             */
/*   Updated: 2018/12/08 00:07:05 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_change_val(int **mat, int str_pos, int stb_pos, int val)
{
	*(*(mat + str_pos) + stb_pos) = val;
}
