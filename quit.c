/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:42:19 by lbally            #+#    #+#             */
/*   Updated: 2022/11/05 05:49:38 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init(t_data_a *d)
{
	d->p = 0;
	d->fov = 60;
	d->cap = 0;
	d->len = 0;
	d->time = 0;
	d->oldtime = 0;
	d->planex = 0;
	d->planey = 0.66;
	d->dirx = -1;
	d->diry = 0;
	d->posx = 0;
	d->posy = 0;
	d->gg = 0;
	d->start = 0;
	d->floor = '0';
	d->wall = '1';
	d->perso = 'E';
}

int	quit(void)
{
	exit(0);
}

int	opening(char **av)
{
	if (open(av[1], O_DIRECTORY) != -1)
	{
		printf("Error\nDossier illisible\n");
		return (0);
	}
	return (1);
}
