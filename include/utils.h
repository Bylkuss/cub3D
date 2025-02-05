/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:24:08 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/03 10:52:17 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include <stdbool.h>

# define UINT unsigned int
# define UNCH unsigned char

typedef struct s_mini_m
{
	char			*line;
	struct s_mini_m	*next;
	struct s_mini_m	*prev;
	int				coord[4];
	int				place;

}					t_mini_m;

/* *************** ***************           *************** *************** */
/*                                 FUNCTIONS                                 */
/* *************** ***************           *************** *************** */

/* ***************  LOGS  *************** */
int					ft_msg_err(char *error);
int					ft_msg_err_close(char *error, int *fd);
void				free_map_line(t_mini_m *mini_m);
int					ft_arraylen(char **array);

/* ***************  MAP_UTILS  *************** */
int					access_test(char *file, char *ext);
bool				is_empty_line(char *line);
int					is_map_line(char *line);

/* ***************  PARSE_UTILS  *************** */
char				*get_identifier(char *line, char *str);
char				**duplicate_map(char **map);
void				free_map(char **map);

/* ***************  LST_OPS  *************** */
t_mini_m			*ft_mini_mnew(char *line);
t_mini_m			*ft_last_mini_m(t_mini_m *lst);
void				ft_mini_m_add_back(t_mini_m **lst, char *line);

void				assign_free(char **idfs);
#endif
