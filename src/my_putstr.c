/*
** my_putstr.c for my_putstr in /home/oem/home/CPE_2015_BSQ
**
** Made by OEM Configuration (temporary user)
** Login   <oem@epitech.net>
**
** Started on  Wed Dec 16 01:10:42 2015 OEM Configuration (temporary user)
** Last update Wed Dec 16 01:15:52 2015 OEM Configuration (temporary user)
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
