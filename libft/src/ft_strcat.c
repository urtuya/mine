/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:02:39 by vellery-          #+#    #+#             */
/*   Updated: 2018/12/25 22:30:16 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*str1;
	char	*str2;

	str1 = s1;
	str2 = (char*)s2;
	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = '\0';
	return (s1);
}