/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:02:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/21 23:02:32 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	initialize_data(t_cub3d *cub)
{
	if (Z) {atexit(leaks);}
	cub->gun = 0;
	cub->button = 0;
	cub->doors_n = 1;
	cub->heap = NULL;
	cub->map = NULL;
	cub->doors = NULL;
	cub->sprites = NULL;
	cub->mode = INTRO;
	cub->wall_width = 10;
	cub->img.__img = NULL;
	cub->img.__addr = NULL;
	cub->player.pos.x = 1.5;
	cub->player.pos.y = 1.5;
	cub->player.dir.x = 0;
	cub->player.dir.y = 1;
	cub->player.plan.x = -0.7;
	cub->player.pole = EASTH;
	cub->player.plan.y = 0;
	cub->line = NULL;
	cub->map_width = 0;
	cub->map_height = 0;
	cub->floor_color = hex_to_rgb(0x142F3B);
	cub->ceiling_color = hex_to_rgb(WHITE);
	cub->tex[0].file = ft_strdup("xpm/gris/south.xpm");
	cub->tex[1].file = ft_strdup("xpm/gris/north.xpm");
	cub->tex[2].file = ft_strdup("xpm/gris/east.xpm");
	cub->tex[3].file = ft_strdup("xpm/gris/west.xpm");
}

int	main(int ac, char **av)
{
	t_cub3d	cub;

	if (ac != 2)
		return (printf("Error\nbad number of arguments"), 1);
	initialize_data(&cub);
	if (!file_parse(&cub, av[1]))
		return (2);
	printf("NO : file -> %s\n", cub.tex[0].file);
	printf("SO : file -> %s\n", cub.tex[1].file);
	printf("WE : file -> %s\n", cub.tex[2].file);
	printf("EA : file -> %s\n", cub.tex[3].file);
	printf("F -> RGB(%d, %d, %d)\n",cub.floor_color.red, cub.floor_color.green, cub.floor_color.blue);
	printf("C -> RGB(%d, %d, %d)\n",cub.ceiling_color.red, cub.ceiling_color.green, cub.ceiling_color.blue);
	int i,j;
	i = -1;
	while (++i < cub.map_height)
	{
		j = -1;
		while (++j < cub.map_width)
			printf("%d ",cub.map[i][j].v);
		puts("\n");
	}
	// init_doors(&cub);
	// if (init_window(&cub))
		return (0);
}
