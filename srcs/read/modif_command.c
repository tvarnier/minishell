/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modif_command.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 05:28:50 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 05:28:53 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	delete_char(t_read *r, char *line)
{
	int		i;

	i = 0;
	while (line[r->cursor] != 0)
	{
		line[r->cursor] = line[r->cursor + 1];
		if (!line[r->cursor])
			ft_putchar(' ');
		else
			ft_putchar(line[r->cursor]);
		r->cursor++;
		i++;
	}
	r->cursor_max--;
	r->cursor -= (i);
	ft_putstr("\033[");
	ft_putnbr(i);
	ft_putchar('D');
}

void	insert_char(t_read *r, char *line, char c)
{
	char	tmp;
	int		i;
	int		verif;

	i = 0;
	verif = (r->cursor < r->cursor_max);
	while (c != 0)
	{
		tmp = line[r->cursor];
		ft_putchar(c);
		line[r->cursor++] = c;
		c = tmp;
		i++;
	}
	r->cursor_max++;
	if (verif)
	{
		r->cursor -= (i - 1);
		ft_putstr("\033[");
		ft_putnbr(i - 1);
		ft_putchar('D');
	}
}
