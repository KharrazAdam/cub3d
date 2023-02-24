/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:57:40 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/24 22:17:45 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void    tab_init_1(float tab[4][4])
{
	tab[0][0] = -5;
	tab[0][1] = 2;
	tab[0][2] = 6;
	tab[0][3] = -8;
    
	tab[1][0] = 1;
	tab[1][1] = -5;
	tab[1][2] = 1;
	tab[1][3] = 8;

	tab[2][0] = 7;
	tab[2][1] = 7;
	tab[2][2] = -6;
	tab[2][3] = -7;
 
	tab[3][0] = 1;
	tab[3][1] = -3;
	tab[3][2] = 7;
	tab[3][3] = 4;
}

bool    matrice_equal(t_matrice a, t_matrice b)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (fabs(a.mat[i][j] - b.mat[i][j]) > EPSILON)
				return false;
			j++;
		}
		i++;
	}
	return true;
}

t_matrice   matrice_init(float grp[4][4])
{
	t_matrice   ret;

	ret.mat[0][0] = grp[0][0];
	ret.mat[0][1] = grp[0][1];
	ret.mat[0][2] = grp[0][2];
	ret.mat[0][3] = grp[0][3];
	ret.mat[1][0] = grp[1][0];
	ret.mat[1][1] = grp[1][1];
	ret.mat[1][2] = grp[1][2];
	ret.mat[1][3] = grp[1][3];
	ret.mat[2][0] = grp[2][0];
	ret.mat[2][1] = grp[2][1];
	ret.mat[2][2] = grp[2][2];
	ret.mat[2][3] = grp[2][3];
	ret.mat[3][0] = grp[3][0];
	ret.mat[3][1] = grp[3][1];
	ret.mat[3][2] = grp[3][2];
	ret.mat[3][3] = grp[3][3];
	return (ret);
}


void	matrice_show(t_matrice show)
{
	int	y;
	int x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			printf(" %f ", show.mat[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
}

void	matrice_sub_show(t_matrice show)
{
	int	y;
	int x;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			printf(" %f ", show.sub[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
}

t_matrice   matrice_identity(void)
{
    t_matrice ret;

    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            ret.mat[i][j] = 0;
            if (j == i)
                ret.mat[i][j] = 1;
            j++;
        }
        i++;
    }
    return (ret); 
}

t_matrice   matrice_transpose(t_matrice obj)
{
    t_matrice   trans;
    int         i;
    int         j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            trans.mat[i][j] = obj.mat[j][i];
            j++;
        }
        i++;
    }
    return trans;
}
