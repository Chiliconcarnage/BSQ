/*
** bsq2.c for bsq2 in /home/oem/home/CPE_2015_BSQ
**
** Made by OEM Configuration (temporary user)
** Login   <oem@epitech.net>
**
** Started on  Sat Dec 19 17:50:48 2015 OEM Configuration (temporary user)
** Last update Tue Dec 12 18:12:40 2017 maxence.lauque
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my_struct.h"

int	display(char **tab2, t_trash *t)
{
  int	z;

  z = 0;
  while (z < t->lines)
    {
      my_putstr(tab2[z]);
      z++;
    }
}

int	free_tab(char **tab2, t_trash *t)
{
  int	a;

  a = 0;
  while (a < t->lines)
    {
      free(tab2[a]);
      a++;
    }
  free(tab2);
  free(t);
  return (0);
}

int	my_algo(char **tab2, t_trash *t)
{
  while ((t->pos_y + t->size) <= t->lines)
    {
      while (t->pos_x + t->size <= t->cols)
	{
	  while (my_square(t, tab2) == 0 &&
		(t->pos_y + t->size <= t->lines) &&
		(t->pos_x + t->size < t->cols))
	    t->size++;
	  t->pos_x++;
	  if (t->save_size < t->size)
	    {
	      t->save_size = t->size;
	      t->save_x = t->pos_x - 1;
	      t->save_y = t->pos_y;
	    }
	}
      t->pos_y++;
      t->pos_x = 0;
    }
  print(t, tab2);
  free_tab(tab2, t);
  return (0);
}

int	my_square(t_trash *t, char **tab2)
{
  int	x;
  int	y;

  t->i = 0;
  t->k = 0;
  x = t->pos_x;
  y = t->pos_y;
  while (t->k < t->size)
    {
      if (y >= t->lines)
	return (1);
      while (t->i < t->size)
	{
	  if (tab2[y][x] == 'o')
	    return (1);
	  x++;
	  t->i++;
	}
      t->i = 0;
      y++;
      t->k++;
      x = x - t->size;
    }
  return (0);
}

int	print(t_trash *t, char **tab2)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  t->save_size = t->save_size - 1;
  while (i < t->save_size)
    {
      while (k < (t->save_size))
	{
	  tab2[t->save_y][t->save_x] = 'x';
	  t->save_x++;
	  k++;
	}
      k = 0;
      t->save_x = t->save_x - t->save_size;
      t->save_y++;
      i++;
    }
  display(tab2, t);
}
