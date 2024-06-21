/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:24:39 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/20 15:26:35 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/struct.h"

int	count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	parse_color(t_color *color, char *line)
{
	char	**splited;
	int		i;

	if (!is_num(line[ft_strlen(line) - 1]))
			return (0);
	splited = ft_split(line, ',');
	if (count(splited) != 3 && !all_num(ft_strtrim(splited[0])) \
	|| !all_num(ft_strtrim(splited[1])) \
	|| !all_num(ft_strtrim(splited[2])))
			return (0);
	color->red = ft_atoi(splited[0]);
	color->green = ft_atoi(splited[1]);
	color->blue = ft_atoi(splited[2]);
}

void	parse_texture(t_cub3d *cub, char *line, int i)
{
	char	**splited();

	splited = ft_split(line, ' ');
	if (count(splited) != 2)
		return (0);
	cub->tex[i] = ft_strdup(splited[1]);
	return (1);
}

int     valid_component(t_cub3d *cub, char *line)
{
	char    *trim;

	trim = ft_strtrim(line, " ");
	if (ft_strncmp(trim, "NO ", 3))
		return (parse_texture(cub, trim, 0), 1);
	if (ft_strncmp(trim, "EA ", 3))
		return (parse_texture(cub, trim, 1), 1);
	if (ft_strncmp(trim, "SO ", 3))
		return (parse_texture(cub, trim, 2), 1);
	if (ft_strncmp(trim, "WE ", 3))
		return (parse_texture(cub, trim, 3), 1);
	if (ft_strncmp(trim, "F ", 2))
		return (parse_color(&cub->floor_color, ft_strchr(trim, ' ')));
	if ( ft_strncmp(trim, "C ", 2))
		return (parse_color(&cub->ceiling_color, ft_strchr(trim, ' ')));
	return (0);
}

int     headers_parse(t_cub3d *cub, int fd)
{
	int     i;
	char    *line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < 6)
	{
		if (!empty(line)) // the line maybe empty
		{
			if (!valid_component(cub, line))
					return (0);
			i++;
		}
		if (i < 6) //in order to not lose the offset of the first line of map
				line = get_next_line(fd);
	}
	return (line != NULL);
}
