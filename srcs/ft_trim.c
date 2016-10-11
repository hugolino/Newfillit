/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:52:42 by rthys             #+#    #+#             */
/*   Updated: 2016/10/11 18:02:30 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_trim(char **tab, char *buf, int *pieces, int *found)
{
	char	*trim;
	int		i;

	i = 0;
	trim = (char *)malloc(sizeof(char) * ft_strlen(buf) + 2);
	while (*pieces < ft_countl(buf) + 1)
	{
		*found = 0;
		trim = ft_strcat(trim, ft_is_square(tab, buf, pieces, found));
		trim = ft_strcat(trim, ft_is_z(tab, buf, pieces, found));
		trim = ft_strcat(trim, ft_is_z_up(tab, buf, pieces, found));
		trim = ft_strcat(trim, ft_is_line_hor(tab, buf, pieces, found));
		trim = ft_strcat(trim, ft_is_line_ver(tab, buf, pieces, found));
		trim = ft_strcat(trim, ft_is_s(tab, buf, pieces, found));
		trim = ft_strcat(trim, ft_is_s_up(tab, buf, pieces, found));
		trim = ft_strcat(trim, ft_test_t(tab, buf, pieces, found));
		trim = ft_strcat(trim, ft_test_l(tab, buf, pieces, found));
		*pieces += 5;
	}
	return (trim);
}

char	*ft_sub_trim(char **tab, char *buf)
{
	int		*pieces;
	char	*trim;
	int		*found;

	pieces = (int *)malloc(sizeof(int));
	*pieces = 0;
	found = (int *)malloc(sizeof(int));
	trim = ft_trim(tab, buf, pieces, found);
	return (trim);
}

void	ft_count_pieces(t_coord *cd)
{
	size_t i;
	size_t nb;

	i = 0;
	nb = 0;
	while (BUF[i])
	{
		if (BUF[i] == '\n' && BUF[i - 1] == '\n')
			nb++;
		i++;
	}
	NB_P = nb + 1;
}

char	**ft_cpy_tab(char **tab2, t_coord *cd)
{
	char	**tab1;
	size_t	y;

	y = 0;
	tab1 = (char **)malloc(sizeof(char *) * COTE);
	while (y < COTE)
	{
		tab1[y] = (char *)malloc(sizeof(char) * COTE);
		ft_strcpy(tab1[y], tab2[y]);
		y++;
	}
	return (tab1);
}
