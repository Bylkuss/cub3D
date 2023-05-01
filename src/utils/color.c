/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:48:10 by hsaadi            #+#    #+#             */
/*   Updated: 2023/05/01 14:52:44 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

UINT	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	load_color(UINT *c, char *line)
{
	static bool	status;
	char		*tmp;
	int			r;
	int			g;
	int			b;

	status = false;
	if (status)
		ft_msg_err("Reassigning of color.");
	status = true;
	tmp = ft_substr(line, 0, 3);
	r = atoi(tmp);
	tmp = ft_substr(line, 4, 3);
	g = atoi(tmp);
	tmp = ft_substr(line, 8, 3);
	b = atoi(tmp);
	*c = get_rgba(r, g, b, 255);
	free(tmp);
}
