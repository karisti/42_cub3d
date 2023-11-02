/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:45:22 by karisti-          #+#    #+#             */
/*   Updated: 2021/11/26 10:21:14 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_extension(char *file, char *ext)
{
	int		fname_len;
	int		ext_len;

	fname_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (fname_len < ext_len
		|| ft_strncmp(&file[fname_len - ext_len], ext, fname_len) != 0)
	{
		return (0);
	}
	return (1);
}

int	file_exists(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	ft_open_file(char *file, t_params *params)
{
	int	fd;

	fd = -1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("File doesn´t exist or unable to open", params);
	return (fd);
}
