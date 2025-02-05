/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:45:34 by hsaadi            #+#    #+#             */
/*   Updated: 2023/05/03 14:18:57 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Check if the file is valid
 *
 * @param file The path to the file to check
 * @param ext The extension of the file to check
 * @return int Returns 1 if the file is valid, 0 if not
 */
int	access_test(char *file, char *ext)
{
	int		fd;
	char	*str;

	if (!file)
		return (0);
	str = ft_strtrim(file, "\n");
	if (!str)
		return (0);
	if (strcmp(str + strlen(str) - strlen(ext), ext))
	{
		free(str);
		ft_msg_err("Wrong file type: ext <map | texture>");
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(str);
		ft_msg_err("Can't open file <map | texture>");
	}
	free(str);
	close(fd);
	return (1);
}

bool	is_id(char *line, char *str)
{
	char	*tmp;

	tmp = get_identifier(line, str);
	if (tmp)
	{
		free(tmp);
		return (true);
	}
	free(tmp);
	return (false);
}

/**
 * @brief Assign the path to the right identifier
 *
 * @param line The line to check
 * @return char** Returns an array of strings containing the path to the
 * different identifiers
 */
void	assign_path(t_map *map, char *line)
{
	if (is_id(line, "NO"))
		map->idfs[0] = get_identifier(line, "NO");
	if (is_id(line, "SO"))
		map->idfs[1] = get_identifier(line, "SO");
	if (is_id(line, "WE"))
		map->idfs[2] = get_identifier(line, "WE");
	if (is_id(line, "EA"))
		map->idfs[3] = get_identifier(line, "EA");
	if (is_id(line, "F"))
		map->idfs[4] = get_identifier(line, "F");
	if (is_id(line, "C"))
		map->idfs[5] = get_identifier(line, "C");
}

/**
 * @brief 
 * 
 * @param map 
 * @param idfs 
 * @param line 
 * @return true 
 * @return false 
 */
static bool	manage_colors(t_map *map, int line)
{
	if (line == 4 && map->idfs[4])
	{
		if (!load_color(&map->floor, map->idfs[4]))
			return (false);
	}
	else if (line == 5 && map->idfs[5])
	{
		if (!load_color(&map->ceil, map->idfs[5]))
			return (false);
	}
	return (true);
}

/**
 * @brief Nabage setting lines and store them in the map struct
 *
* @param line The line to check and store. Check if it's a setting
	line and if the path is valid then store it in the map struct.
 * @return bool Returns true if the line is a map line, false if not
 */
bool	manage_settings(t_map *map, char *line)
{
	map->mxln++;
	assign_path(map, line);
	if (is_id(line, "NO") && access_test(map->idfs[0], ".png"))
		map->north = mlx_load_png(map->idfs[0]);
	else if (is_id(line, "SO") && access_test(map->idfs[1], ".png"))
		map->south = mlx_load_png(map->idfs[1]);
	else if (is_id(line, "WE") && access_test(map->idfs[2], ".png"))
		map->west = mlx_load_png(map->idfs[2]);
	else if (is_id(line, "EA") && access_test(map->idfs[3], ".png"))
		map->east = mlx_load_png(map->idfs[3]);
	else if (is_id(line, "F"))
		return (manage_colors(map, 4));
	else if (is_id(line, "C"))
		return (manage_colors(map, 5));
	else
		return (false);
	return (true);
}
