/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:26:58 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/20 20:42:05 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/struct.h"

int all_ones(char *line)
{
    while (*line && *line == '1')
        line++;
    return (!*line);
}

int parse_line(char *line, int *off, int *last)
{
    static  int bol;
    int         i;
    
    i = 0;
    while (line[i] && line[i] == ' ')
        i++;
    *off = i;
    while (line[i])
    {
        while (line[i] && valid_char(line[i]) && line[i] != ' ')
        {
            if (line[i] != '1' && line[i] != '0')
                bol++;
            i++;
        }
        if (bol > 1 || (line[i] && line[i] != ' ' && !valid_char(line[i])))
            return (0);
        *last = i - 1;
        while (line[i] && line[i] == ' ')
            i++;
    }
    return (1);
}

int parse_map(t_cub3d *cub)
{
    t_line  *c_line;
    t_line  *p_line;
  
    if (!all_ones(cub->line->line))
        return (0);
    p_line = cub->line;
    while (p_line->next)
    {
        c_line = p_line->next;
        if (c_line->off < p_line->last && (!check_last(p_line->line, \
        p_line->last - c_line->off) || !check_first(c_line->line, \
        p_line->last - c_line->off)))
            return (0);
        if (c_line->off > p_line->last && (!check_last(c_line->line, \
        p_line->last - c_line->off) || !check_first(p_line->line, \
        p_line->last - c_line->off)))
            return (0);
        if (c_line->line[c_line->off] != 1 && c_line->line[c_line->last] != 1)
            return (0);
        p_line = c_line;
        c_line = c_line->next;
    }
    return (all_ones(cub->line->line));
}

int valid_map(t_cub3d *cub, int fd)
{
    char    *line;
    t_line  *node;
    int     first;
    int     last;

    line = get_next_line(fd);
    while (line && empty(line))
        line = get_next_line(fd);
    while (line)
    {
        if (!parse_line(line->line, &first, &last))
            return (0);
        node = new_line(line, first, last)
        if (!node)
            return (0);
        line_add_back(&cub->line, line);
        cub->map_height++;
        line = get_next_line(fd);
    }
    if (cub->map_height < 3)
        return (0);
    return (parse_map(cub) && get_map_cord(cub));
}

