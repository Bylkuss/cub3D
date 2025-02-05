/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:25:28 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/01 14:51:16 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_square(t_cub *cub, uint32_t x, uint32_t y, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = y * cub->map->cell_size + 1;
	while (j <= (y * cub->map->cell_size) + cub->map->cell_size - 1)
	{
		i = x * cub->map->cell_size + 1;
		mlx_put_pixel(cub->win, i, j, color);
		while (i <= (x * cub->map->cell_size) + cub->map->cell_size - 1)
		{
			mlx_put_pixel(cub->win, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_bg(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < ((cub->map->height - 1) * cub->map->cell_size))
	{
		j = 0;
		while (j < (cub->map->width * cub->map->cell_size))
		{
			mlx_put_pixel(cub->win, j, i, BG);
			j++;
		}
		i++;
	}
}

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	dep = 0;
	mini_m = cub->map->mini_m;
	j = 0;
	draw_bg(cub);
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (mini_m->line[i] == '1')
				print_square(cub, i + dep, j, WALLS);
			else
				print_square(cub, i + dep, j, VOID);
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
}

void	draw_fov(t_cub *cub)
{
	float	i;
	float	incr;
	float	start;

	i = 0;
	incr = 0;
	start = cub->p_a + (cub->fov * 0.5);
	incr = cub->fov / WIDTH;
	while (i < WIDTH)
	{
		fov(cub, start);
		start -= incr;
		start = normalize_angle(start);
		i++;
	}
}

void	cast_fov(t_cub *cub)
{
	float	i;
	float	incr;

	i = 0;
	incr = 0;
	cub->starting_a = cub->p_a + (cub->fov * 0.5);
	incr = cub->fov / WIDTH;
	while (i < WIDTH)
	{
		cast_ray(cub, cub->starting_a, i);
		cub->starting_a -= incr;
		cub->starting_a = normalize_angle(cub->starting_a);
		i++;
	}
}
