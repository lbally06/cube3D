/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:31:10 by lbally            #+#    #+#             */
/*   Updated: 2022/11/05 05:49:28 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <strings.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

# define BUFFER_SIZE 50

typedef struct s_data_a {
	void				*mlx;
	void				*mlx_dow;
	void				*img;
	char				*adr;
	int					gg;
	int					start;
	char				**map;
	char				**map2;
	int					p;
	char				pp;
	int					fov;
	int					dirx;
	int					diry;
	double				posx;
	double				posy;
	double				planex;
	double				planey;
	double				time;
	double				oldtime;
	int					len;
	int					cap;
	int					bi_p_pix;
	int					line_len;
	int					endian;
	char				*mage;
	void				*c;
	char				*ceil;
	char				floor;
	void				*fl;
	char				*fllr;
	char				perso;
	char				wall;
	void				*wan;
	char				*wlln;
	void				*was;
	char				*wlls;
	void				*wae;
	char				*wlle;
	void				*waw;
	char				*wllw;
}					t_data_a;

char	*get_content(char *content);
char	*get_line(char *str);
char	*join_str(char const *s1, char const *s2);
char	*strdupp(const char *s1, t_data_a *d);
char	*ft_find_im(t_data_a *d);

int		ft_read(int fd, char **content, int ret, char *buff);
int		get_next_line(int fd, char **line);
int		has_return(char *str);
int		gnl2(int fd, char **av, char *line, t_data_a *d);
int		gnl(char **av, t_data_a *d);
int		main(int ac, char **av);
int		touch(int n);
int		ber2(char *line);
int		ber(char **av);
int		place(t_data_a *d, char n, int r);
int		parse(char **line, t_data_a *d);
int		quit(void);
int		opening(char **av);
int		touche(int key, t_data_a *d);
int		parse2(char **map, t_data_a *d);

size_t	ft_strlen(const char *s);

void	*ft_memmove(void *dst, const void *src, size_t len);
void	init(t_data_a *d);
void	creat_img(t_data_a *d);
void	remplace(t_data_a *d);
void	draw(t_data_a *d);

#endif