/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkode <bylkode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:44 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/20 12:12:42 by bylkode          ###   ########.fr       */
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
				mlx_put_pixel(cub->win, i, j, get_rgba(0, 0, 255, 100));
			if (j > cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, get_rgba(155, 055, 55, 255));
			j++;
		}
		i++;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 2)
	{
		cub = init_cub();
		if(!parse_map(cub, argv[1]))
			ft_msg_err("Bad Map Buddy!");
		init_game(cub);
		print_map_lines(cub->map->mini_m);
		// mlx_loop_hook(cub->mlx, &main_hook, cub);
		// mlx_loop_hook(cub->mlx, &move_p_hook, cub);
		// mlx_loop(cub->mlx);
		// mlx_terminate(cub->mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
