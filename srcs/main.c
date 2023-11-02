/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:00:46 by karisti-          #+#    #+#             */
/*   Updated: 2021/12/03 17:12:16 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_error(char *str, t_params *params)
{
	ft_putstr_fd("Error\n", 1);
	if (str && ft_strlen(str) > 0)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	if (params != NULL)
		antileaks(params);
	exit(1);
}

int	exit_clean(t_params *params)
{
	antileaks(params);
	printf("\nGame ended!\n");
	exit(0);
}

void	parse_cub_file(char *filename, t_params *params)
{
	int	fd;

	fd = ft_open_file(filename, params);
	parse_values(fd, params);
	get_map_size(fd, params);
	close(fd);
	fd = ft_open_file(filename, params);
	while (params->escape_lines--)
	{
		ft_get_next_line(fd, &params->line);
		free_line(params);
	}
	parse_map(fd, params);
	close(fd);
	if (params->map.init_dir == '\0')
		exit_error("Invalid map, missing start position", params);
	check_map_closed(params, -1, -1);
}

int	main(int argc, char *argv[])
{
	t_params	params;

	if (argc != 2)
		exit_error("Invalid arguments", NULL);
	init_params(&params);
	if (!check_extension(argv[1], ".cub"))
		exit_error("Invalid file extension, .cub needed", &params);
	parse_cub_file(argv[1], &params);
	build_mlx(&params);
	return (0);
}
