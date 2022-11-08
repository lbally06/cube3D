/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:37:32 by lbally            #+#    #+#             */
/*   Updated: 2022/11/05 01:52:50 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strdup(const char *s1)
{
	void	*str;
	char	*a;
	size_t	i;

	str = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	a = (char *)str;
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	remplace(t_data_a *d)
{
	char	*lolo;
	int		i;
	int		w;
	int		t;

	i = 0;
	w = 0;
	t = 0;
	d->gg = d->start;
	while (d->map[d->gg])
	{
		w = 0;
		while (d->map[d->gg][w])
			w++;
		if (i < w)
			i = w;
		d->gg++;
		t++;
	}
	w = 0;
	d->cap = t + 1;
	d->len = i + 1;
	d->map2 = malloc(sizeof(char *) * (t + 1));
	d->map2[t] = NULL;
	lolo = malloc(sizeof(char) * (i + 1));
	t = 0;
	while (d->map2[t])
	{
		lolo[i] = '\0';
		d->map2[t] = ft_strdup(lolo);
		t++;
	}
	t = 0;
	d->gg = d->start;
	printf("\n\n");
	while (d->map2[t])
	{
		w = 0;
		while (d->map[d->gg][w])
		{
			d->map2[t][w] = d->map[d->gg][w];
			if (d->map2[t][w] == ' ' || d->map2[t][w] == '\0')
				d->map2[t][w] = '1';
			if (d->map2[t][w] == d->pp)
			{
				d->posx = t;
				d->posy = w;
			}
			w++;
		}
		if (w < i)
		{
			while (w < i)
			{
				d->map2[t][w] = '1';
				w++;
			}
		}
		printf("LALA == %s\n", d->map2[t]);
		t++;
		d->gg++;
	}
}
