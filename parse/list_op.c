/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:22:20 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/21 16:50:41 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_line	*new_line(t_cub3d *cub, char *line, int off, int last)
{
	t_line	*node;

	node = talloc(&(cub->heap), sizeof(t_line));
	if (!node)
		return (NULL);
	node->last = last;
	node->off = off;
	node->line = line;
	node->next = NULL;
	return (node);
}

void	line_add_back(t_line **line, t_line *node)
{
	t_line	*tmp;

	if (!line || !node)
		return ;
	if (!*line)
	{
		*line = node;
		return ;
	}
	tmp = *line;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	clear_lines(t_line *line)
{
	t_line	*tmp;

	while (line)
	{
		tmp = line;
		line = line->next;
		(free(tmp->line), free(tmp));
	}
}
