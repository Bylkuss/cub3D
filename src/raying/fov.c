/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:51:31 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/01 13:43:03 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_wall(t_cub *cub, float destx, float desty)
{
	int	x;
	int	y;

	x = (int)floorf(destx / cub->map->sq_size);
	y = (int)floorf(desty / cub->map->sq_size);
	return (cub->map->map[y][x] == '1');
}

bool	fov(t_cub *cub, float angle)
{
	int		i;
	float	x;
	float	y;
	float	ray_coord[2];

	ray_coord[X] = cub->ray_x;
	ray_coord[Y] = cub->ray_y;
	i = 0;
	ray_coord[X] = cos(angle);
	ray_coord[Y] = -sin(angle);
	while (1)
	{
		x = cub->coord[X] + ray_coord[X] * i;
		y = cub->coord[Y] + ray_coord[Y] * i;
		if (is_wall(cub, x, y))
			return (false);
		mlx_put_pixel(cub->win, x * (cub->map->cell_size / cub->map->sq_size), y
			* (cub->map->cell_size / cub->map->sq_size), 0xffffffff);
		i++;
	}
	return (true);
}
