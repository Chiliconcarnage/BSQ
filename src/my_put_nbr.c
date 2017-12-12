/*
** my_put_nbr.c for Piscine_C_J03 in /home/puilla_e/Day3
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Sep 30 18:59:46 2015 edouard puillandre
** Last update Fri Nov 20 22:56:41 2015 maxence lauque
*/

int	my_put_nbr(int nb)
{
  int	var_one;
  int	max_true;

  var_one = 0;
  max_true = check_max(nb);
  if (max_true == 0)
    {
      nb = check_neg(nb);
      var_one = count_digit(nb);
      while (var_one >= 1)
	{
	  if (nb / var_one > 0)
	    {
	      my_putchar(48 + nb / var_one);
	      nb = nb % var_one;
	    }
	  else
	    {
	      my_putchar(48);
	    }
	  var_one = var_one / 10;
	}
    }
  return (0);
}

int	check_max(int nb)
{
  int	max_true;

  max_true = 0;
  if (nb == - 2147483648)
    {
      max_true = 1;
      my_putchar(45);
      my_putchar(50);
      my_putchar(49);
      my_putchar(52);
      my_putchar(55);
      my_putchar(52);
      my_putchar(56);
      my_putchar(51);
      my_putchar(54);
      my_putchar(52);
      my_putchar(56);
    }
  return (max_true);
}

int	check_neg(int nb)
{
  if (nb < 0)
    {
      my_putchar(45);
      nb = nb * - 1;
    }
  return (nb);
}

int	count_digit(int nb)
{
  int	digit_true;
  int	var_one;

  var_one = 1;
  digit_true = 0;
  while (digit_true == 0)
    {
      if (nb / var_one < 10)
	{
	  digit_true = 1;
	}
      else
	{
	  var_one = var_one * 10;
	}
    }
  return (var_one);
}
