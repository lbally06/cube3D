/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:38:57 by lbally            #+#    #+#             */
/*   Updated: 2022/11/04 21:20:03 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_find_im(t_data_a *d)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (d->map[d->gg][i] == 'N' || d->map[d->gg][i] == 'O'
		|| d->map[d->gg][i] == 'S' || d->map[d->gg][i] == 'W'
		|| d->map[d->gg][i] == 'E' || d->map[d->gg][i] == 'A'
		|| d->map[d->gg][i] == 'F' || d->map[d->gg][i] == 'C'
		|| d->map[d->gg][i] == ' ')
		i++;
	j = i;
	while (d->map[d->gg][j])
		j++;
	str = malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (d->map[d->gg][i])
	{
		str[j] = d->map[d->gg][i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*
void	creat_img(t_data_a *d)
{
	int	taille1;
	int	taille2;

	taille1 = 64;
	taille2 = 64;
	d->fl = mlx_put_pixel(d->mlx,
			&taille1, &taille2,
			"0x100050255");
	d->c = mlx_put_pixel(d->mlx,
			&taille1, &taille2,
			"0x000255100");
	d->wan = mlx_put_pixel(d->mlx,
			&taille1, &taille2,
			"0x255000200");
}
	d->fl = mlx_put_pixel(d->mlx,
			&taille1, &taille2,
			d->fllr);
	d->wan = mlx_xpm_file_to_image(d->mlx,
			d->wlln,
			&taille1, &taille2);
	d->was = mlx_xpm_file_to_image(d->mlx,
			d->wlls,
			&taille1, &taille2);
	d->waw = mlx_xpm_file_to_image(d->mlx,
			d->wllw,
			&taille1, &taille2);
	d->wae = mlx_xpm_file_to_image(d->mlx,
			d->wlle,
			&taille1, &taille2);
	d->c = mlx_put_pixel(d->mlx,
			&taille1, &taille2,
			d->ceil);
*/

/*void	draw(t_data_a *d)
{
}*/
