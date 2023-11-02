/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:45:17 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 10:28:59 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	all_values_avilable(t_params *params)
{
	if (params->texture_no != NULL && params->texture_so != NULL
		&& params->texture_we != NULL && params->texture_ea != NULL
		&& params->rgb_ceil != NULL && params->rgb_floor != NULL)
		return (1);
	return (0);
}

int	parse_texture(t_params *params, void **p)
{
	int	i;

	i = 2;
	while (params->line[i] && params->line[i] == ' ')
		i++;
	if ((char *)*p != NULL)
		exit_error("Invaid texture, duplicated param", params);
	*p = ft_substr(params->line, i, ft_strlen(params->line));
	if (!file_exists(*p))
		exit_error("Invalid texture, doesn´t exist or unable to open", params);
	return (1);
}

int	parse_colour(t_params *params, void **p)
{
	char	**sp;
	int		i;

	i = 1;
	while (params->line[i] && params->line[i] == ' ')
		i++;
	if (*p != NULL)
		exit_error("Invaid colour, duplicated param", params);
	*p = (int *)ft_calloc(3, sizeof(int));
	sp = ft_split(&params->line[i], ',');
	i = 0;
	while (sp[i])
	{
		if (i >= 3 || !ft_strisnum(sp[i]))
			exit_error("Invalid colour, not correct RGB number", params);
		((int *)*p)[i] = ft_atoi(sp[i]);
		if (((int *)*p)[i] < 0 || ((int *)*p)[i] > 255)
			exit_error("Invalid colour, not between 0 and 255", params);
		free(sp[i]);
		i++;
	}
	if (i != 3)
		exit_error("Invalid colour, not correct RGB number", params);
	free(sp);
	return (1);
}

int	get_data(t_params *params)
{
	if (ft_strlen(params->line) == 0)
		return (1);
	if (params->line[0] == 'C')
		return (parse_colour(params, &params->rgb_ceil));
	if (params->line[0] == 'F')
		return (parse_colour(params, &params->rgb_floor));
	if (ft_strlen(params->line) < 2)
		return (0);
	if (params->line[0] == 'N' && params->line[1] == 'O')
		return (parse_texture(params, &params->texture_no));
	if (params->line[0] == 'S' && params->line[1] == 'O')
		return (parse_texture(params, &params->texture_so));
	if (params->line[0] == 'E' && params->line[1] == 'A')
		return (parse_texture(params, &params->texture_ea));
	if (params->line[0] == 'W' && params->line[1] == 'E')
		return (parse_texture(params, &params->texture_we));
	return (0);
}

void	parse_values(int fd, t_params *params)
{
	int		i;

	i = -1;
	while (ft_get_next_line(fd, &params->line) != 0 && params->line)
	{
		if (!get_data(params))
			exit_error("Invalid identifier", params);
		if (all_values_avilable(params))
			break ;
		free_line(params);
		i++;
	}
	free_line(params);
	params->escape_lines = i + 2;
	if (!all_values_avilable(params))
		exit_error("Missing some params", params);
}
