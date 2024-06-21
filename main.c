/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:02:16 by tamehri           #+#    #+#             */
/*   Updated: 2024/06/20 20:48:01 by ooulcaid         ###   ########.fr       */
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
	cub->mapS = NULL;
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
	cub->min = 0;
	cub->max = 0;
	cub->floor_color = hex_to_rgb(0x142F3B);
	cub->ceiling_color = hex_to_rgb(WHITE);
	cub->tex[0].file = ft_strdup("xpm/gris/south.xpm");
	cub->tex[1].file = ft_strdup("xpm/gris/north.xpm");
	cub->tex[2].file = ft_strdup("xpm/gris/east.xpm");
	cub->tex[3].file = ft_strdup("xpm/gris/west.xpm");
}

int	main()
{
	t_cub3d	cub;

	if (ac != 2)
		return (printf("Error\nbad number of arguments"), 1);
	initialize_data(&cub);
	if (!parse_file(argv[1]))
		return (2);
	// initialize_data(&cub);
	// init_doors(&cub);
	// if (init_window(&cub))
	// 	return (0);
}
