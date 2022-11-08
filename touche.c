/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touche.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:40:17 by lbally            #+#    #+#             */
/*   Updated: 2022/11/04 21:20:19 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*void	gauche(t_data_a *d)
{
	d->posy = d->posy - 1;
	if (d->map[d->posx][d->posy] != '1')
		draw(d);
	else
		d->posy = d->posy + 1;
}

void	droite(t_data_a *d)
{
	d->posy = d->posy + 1;
	if (d->map[d->posx][d->posy] != '1')
		draw(d);
	else
		d->posy = d->posy - 1;
}

void	haut(t_data_a *d)
{
	d->posx = d->posx - 1;
	if (d->map[d->posx][d->posy] != '1')
		draw(d);
	else
		d->posx = d->posx + 1;
}

void	bas(t_data_a *d)
{
	d->posx = d->posx + 1;
	if (d->map[d->posx][d->posy] != '1')
		draw(d);
	else
		d->posx = d->posx - 1;
}

int	touche(int key, t_data_a *d)
{
	if (key == 0 || key == 13 || key == 2 || key == 1)
	{
		if (key == 0)
			gauche(d);
		if (key == 13)
			haut(d);
		if (key == 2)
			droite(d);
		if (key == 1)
			bas(d);
	}
	if (key == 53)
		exit (0);
	return (0);
}
*/