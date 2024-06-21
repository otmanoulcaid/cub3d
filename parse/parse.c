/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:29:12 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/21 08:34:53 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/struct.h"

int     file_parse(t_cub3d *cub, char *file)
{
	int     fd;

	if (ft_strcmp(ft_strrchr(file, '.'), ".cub"))
		return (putendl_fd("Error\nnot valid Extention", 2), 0)
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (putendl_fd("error\nfail to open file", 2), 0);
	if (!headers_parse(cub, fd))
		return (putendl_fd("Error\nnot valid Headers", 2), 0);
	if (!valid_map(fd))
		return (putendl_fd("Error\nnot a valid map", 2), 0);
}