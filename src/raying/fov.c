/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:51:31 by loadjou           #+#    #+#             */
/*   Updated: 2023/03/09 15:25:58 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool    is_wall(t_cub *cub, int32_t destx, int32_t desty)
{
    return(cub->map->map[desty / cub->map->sq_size ][destx / cub->map->sq_size ] == '1');
}