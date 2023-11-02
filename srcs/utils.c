/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:40:32 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 01:57:35 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	antileaks1(t_params *params)
{
	int		i;

	i = -1;
	if (params->map.grid)
	{
		while (++i < params->map.height)
		{
			if (params->map.grid[i])
				free(params->map.grid[i]);
		}
		free(params->map.grid);
	}
	free_line(params);
}

void	antileaks(t_params *params)
{
	if (params->rgb_ceil)
		free(params->rgb_ceil);
	if (params->rgb_floor)
		free(params->rgb_floor);
	if (params->texture_no)
		free(params->texture_no);
	if (params->texture_so)
		free(params->texture_so);
	if (params->texture_we)
		free(params->texture_we);
	if (params->texture_ea)
		free(params->texture_ea);
	antileaks1(params);
}

/*
void	print_data(t_params	*params)
{
	int	*rgb_floor = (int *)params->rgb_floor;
	int	*rgb_ceil = (int *)params->rgb_ceil;
	int	i;
	int	j;

	printf("NO: %s\n", params->texture_no);
	printf("SO: %s\n", params->texture_so);
	printf("WE: %s\n", params->texture_we);
	printf("EA: %s\n", params->texture_ea);
	printf("FLOOR: (%i, %i, %i) = %li\n", rgb_floor[0],
		rgb_floor[1], rgb_floor[2], params->floor_colour);
	printf("CEIL: (%i, %i, %i) = %li\n", rgb_ceil[0],
		rgb_ceil[1], rgb_ceil[2], params->ceil_colour);
	printf("\n -- MAP -- \n");
	printf("Map height: %d\n", params->map.height);
	printf("Map width: %d\n", params->map.width);
	printf("Map init x: %d\n", params->map.init_x);
	printf("Map init y: %d\n", params->map.init_y);
	printf("Map init dir: %c\n", params->map.init_dir);

	i = 0;
	while (i < params->map.height)
	{
		j = 0;
		while (j < (int)ft_strlen(params->map.grid[i]))
		{
			printf("%c", params->map.grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
*/
