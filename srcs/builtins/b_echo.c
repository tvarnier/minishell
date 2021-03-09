/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_echo.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 02:04:03 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 14:59:15 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		b_echo(t_shell *s, char **av, int ac)
{
	int		op_n;
	int		i;

	(void)s;
	op_n = 0;
	if (ac >= 2)
	{
		i = 0;
		if (!ft_strcmp(av[1], "-n") && (++i))
			op_n = 1;
		while (++i < ac)
		{
			ft_putstr(av[i]);
			if (i + 1 < ac)
				ft_putchar(' ');
		}
	}
	if (op_n)
		ft_putstr("\033[7m%\033[0m");
	ft_putchar('\n');
	return (0);
}
