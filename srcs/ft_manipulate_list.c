/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulate_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:27:13 by rthys             #+#    #+#             */
/*   Updated: 2016/10/12 18:45:34 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_etri	*ft_add_list(t_coord *cd, t_etri *tetri, size_t i, size_t *j)
{
	t_etri	*new_t;
	size_t	k;

	k = 0;
	new_t = (t_etri *)malloc(sizeof(t_etri));
	new_t->rank = i + 1;
	new_t->let = tetri->let + 1;
	new_t->previous = tetri;
	new_t->tetri = (char **)malloc(sizeof(char *) * 6);
	while (TAB[*j][0] != '\n' && TAB[*j][0] != '0')
	{
		new_t->tetri[k] = (char *)malloc(sizeof(char) * 6);
		new_t->tetri[k] = ft_cpy_tetri(cd, j);
		k++;
		new_t->len = k;
	}
	*j = *j + 1;
	if (new_t->rank == NB_P - 2)
		new_t->next = NULL;
	NEXT = new_t;
	tetri = new_t;
	return (tetri);
}

t_etri	*ft_make_list(t_coord *cd)
{
	t_etri	*tetri;
	t_etri	*begin_list;
	size_t	i;
	size_t	*j;

	i = 0;
	j = (size_t *)malloc(sizeof(size_t));
	*j = 0;
	while (i < NB_P)
	{
		if (i == 0)
		{
			tetri = (t_etri *)malloc(sizeof(t_etri));
			RANK = i;
			tetri->let = 'A';
			PREV = NULL;
			ft_cpy_first(cd, tetri, j);
			begin_list = tetri;
		}
		else
			tetri = ft_add_list(cd, tetri, i, j);
		i++;
	}
	tetri = begin_list;
	return (tetri);
}

char	*ft_cpy_tetri(t_coord *cd, size_t *j)
{
	char	*str;

	str = ft_strdup(TAB[*j]);
	*j = *j + 1;
	return (str);
}

void		ft_cpy_first(t_coord *cd, t_etri *tetri, size_t *j)
{
	size_t	k;

	k = 0;
	TETRI = (char **)malloc(sizeof(char *) * 5);
	while (TAB[*j][0] != '\n' && TAB[*j][0] != '0')
	{
		TETRI[k] = (char *)malloc(sizeof(char) * 6);
		TETRI[k] = ft_cpy_tetri(cd, j);
		k++;
	}
	LEN = k;
	*j = *j + 1;
}