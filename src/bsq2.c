/*
** bsq2.c for bsq2 in /home/oem/home/CPE_2015_BSQ
**
** Made by OEM Configuration (temporary user)
** Login   <oem@epitech.net>
**
** Started on  Sun Dec 20 21:37:26 2015 OEM Configuration (temporary user)
** Last update Tue Dec 12 18:12:30 2017 maxence.lauque
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my_struct.h"

int	my_tab(char **tab2, char **av, t_trash *t)
{
  int	x;
  int	y;
  char	c;
  int	i;
  int	a;
  int	folder;

  folder = open(av[1], O_RDONLY, S_IRUSR);
  x = 0;
  y = 0;
  while (a  = read(folder, &c, 1) > 0)
    {
      if (y > 0)
	{
	  tab2[y-1][x] = c;
	  x++;
	}
      if (c == '\n')
	{
	  y++;
	  x = 0;
	}
    }
  my_algo(tab2, t);
  close(folder);
}

int	create_tab(char **av, t_trash *t)
{
  char	**tab2;
  int	i;
  int	x;
  int	a;
  int	b;

  i = 0;
  x = 0;
  a = nb_lines(av);
  b = nb_cols(av);
  tab2 = malloc(sizeof(char *) * (a + 1));
    while (i < a)
      {
	tab2[i] = malloc(sizeof(char) * (b + 1));
	tab2[i][b] = '\0';
	i++;
      }
    my_tab(tab2, av, t);
    return (0);
}

int	nb_lines(char **av)
{
  char	c;
  int	y;
  int	res;
  char	*dest;
  int	folder;

  folder = open(av[1], O_RDONLY, S_IRUSR);
  dest = malloc(sizeof(char*));
  y = 0;
  c = 0;
  while (c != '\n')
    {
      read(folder, &c, 1);
      dest[y] = c;
      y++;
    }
  dest[y] = '\0';
  res = my_getnbr(dest);
  close(folder);
  free(dest);
  return (res);
}

int	nb_cols(char **av)
{
  char	c;
  int	j;
  int	i;
  int	folder;

  i = 0;
  j = 0;
  folder = open(av[1], O_RDONLY, S_IRUSR);
  while (i < 2)
    {
      read(folder, &c, 1);
      if (c == '\n')
	i++;
      if (i > 0)
	j++;
    }
  j = j - 1;
  return (j);
  close(folder);
}

int	main(int ac, char **av)
{
  t_trash	*t;
  int		folder;

  if (ac != 2)
    {
      my_putstr("Invalid number of argument\n");
      return (0);
    }
  folder = open(av[1], O_RDONLY, S_IRUSR);
  if (folder == -1)
    {
      my_putstr("Folder content invalid\n");
      return (0);
    }
  t = malloc(sizeof(*t));
  t->save_size = 0;
  t->pos_x = 0;
  t->pos_y = 0;
  t->cols = nb_cols(av);
  t->lines = nb_lines(av);
  t->size = 0;
  create_tab(av, t);
}
