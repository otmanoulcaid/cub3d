/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:27:56 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/06/20 17:46:15 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     is_num(char c)
{
	return (c <= '9' && c >= '0');
}

int     all_num(char *str)
{
	while (*str && is_num(*str))
			str++;
	return (!str)
}

int     ft_strcmp(char *s1, char *s2)
{
	if (!s1)
			return (-1);
	while (*s1 && *s2 && *s1 == *s2)
			(s1++, s2++);
	return (*s1 - *s2);
}

int     valid_char(char line)
{
	return (*line == 'N' || *line == 'E' || *line == 'W' || \
	*line == 'S' || *line == '0' || *line == '1');
}


int     empty(char *line)
{
	while (*line && *line == ' ')
			line++;
	return (!*line);
}