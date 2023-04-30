/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:24:10 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/30 12:17:17 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	adjust(t_cub *cub, float dx, float dy, unsigned char flag)
{
	dx *= 4;
	dy *= 4;
	if (flag == 'a')
	{
		if (!is_wall(cub, cub->coord[X] + cub->pdx * 4, cub->coord[Y] + cub->pdy
				* 4))
		{
			cub->coord[X] += dx;
			cub->coord[Y] += dy;
		}
	}
	if (flag == 's')
	{
		if (!is_wall(cub, cub->coord[X] - cub->pdx * 4, cub->coord[Y] - cub->pdy
				* 4))
		{
			cub->coord[X] -= dx;
			cub->coord[Y] -= dy;
		}
	}
	cub->odo += 0.05;
}

static void	apply_moves(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, 265) || mlx_is_key_down(cub->mlx, 87))
	{
		cub->pdx = cosf(cub->p_a);
		cub->pdy = -sinf(cub->p_a);
		adjust(cub, cub->pdx, cub->pdy, 'a');
	}
	if (mlx_is_key_down(cub->mlx, 264) || mlx_is_key_down(cub->mlx, 83))
	{
		cub->pdx = cosf(cub->p_a);
		cub->pdy = -sinf(cub->p_a);
		adjust(cub, cub->pdx, cub->pdy, 's');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		cub->pdx = cosf((cub->p_a + deg_to_rad(90)));
		cub->pdy = -sinf((cub->p_a + deg_to_rad(90)));
		adjust(cub, cub->pdx, cub->pdy, 'a');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		cub->pdx = -cosf((cub->p_a - deg_to_rad(90)));
		cub->pdy = sinf((cub->p_a - deg_to_rad(90)));
		adjust(cub, cub->pdx, cub->pdy, 's');
	}
}

void	display_footer(t_cub *cub)
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = HEIGHT - 100; j < HEIGHT; j++)
			mlx_put_pixel(cub->win, i, j, 0x213AA9);
	}
	mlx_put_string(cub->mlx, "NORTH", WIDTH * 0.5 - 60, HEIGHT - 90);
	mlx_draw_texture(cub->win, &cub->map->north->texture, WIDTH * 0.5 - 64,
			HEIGHT - 70);
	mlx_put_string(cub->mlx, "SOUTH", WIDTH * 0.5 + 4, HEIGHT - 90);
	mlx_draw_texture(cub->win, &cub->map->south->texture, WIDTH * 0.5, HEIGHT
			- 70);
	mlx_put_string(cub->mlx, "EAST", WIDTH * 0.5 + 76, HEIGHT - 90);
	mlx_draw_texture(cub->win, &cub->map->east->texture, WIDTH * 0.5 + 64,
			HEIGHT - 70);
	mlx_put_string(cub->mlx, "WEST", WIDTH * 0.5 + 140, HEIGHT - 90);
	mlx_draw_texture(cub->win, &cub->map->west->texture, WIDTH * 0.5 + 128,
			HEIGHT - 70);
}

void	move_p_hook(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	apply_moves(cub);
	rotate(cub);
	cast_fov(cub);
	print_mini_map(cub);
	draw_fov(cub);
	display_footer(cub);
}
