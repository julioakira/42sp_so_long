/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:00:29 by jakira-p          #+#    #+#             */
/*   Updated: 2022/01/11 05:20:30 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_mlx_img	*img_from_file(void *mlx, char *img_path)
{
	t_mlx_img	*img;

	img = ft_calloc(1, sizeof(t_mlx_img));
	if (img)
	{
		img->addr = mlx_xpm_file_to_image(
				mlx,
				img_path,
				&img->width,
				&img->height);
		img->data = mlx_get_data_addr(
				mlx,
				&img->bpp,
				&img->size_line,
				&img->endian);
	}
	return (img);
}
