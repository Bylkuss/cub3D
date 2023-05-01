/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:44 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/01 16:03:45 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	main_hook(void *param)
{
	int32_t	i;
	int32_t	j;
	t_cub	*cub;

	cub = (t_cub *)param;
	i = 0;
	while (i < cub->mlx->width)
	{
		j = 0;
		while (j < cub->mlx->height)
		{
			if (j < cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, cub->map->ceil);
			else if (j > cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, cub->map->floor);
			j++;
		}
		i++;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}

void	free_game(t_cub *cub)
{
	free_map(cub->map->mini_map);
	free_map(cub->map->map);
	mlx_delete_xpm42(cub->map->east);
	mlx_delete_xpm42(cub->map->north);
	mlx_delete_xpm42(cub->map->south);
	mlx_delete_xpm42(cub->map->west);


	
	if(cub->map)
		free(cub->map);
	if(cub)
		free(cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 2)
	{
		cub = init_cub();
		if (!parse_map(cub, argv[1]))
			ft_msg_err("Bad Map Buddy!");
		init_game(cub);
		mlx_loop_hook(cub->mlx, &main_hook, cub);
		mlx_loop_hook(cub->mlx, &move_p_hook, cub);
		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		free_game(cub);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
