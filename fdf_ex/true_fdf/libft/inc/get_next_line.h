/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <vellery-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 20:42:41 by vellery-          #+#    #+#             */
/*   Updated: 2019/10/27 19:44:20 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 500

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int	get_next_line(int fd, char **line);

#endif
