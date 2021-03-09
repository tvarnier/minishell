/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_exit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 21:44:11 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 16:53:46 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		error_av(void)
{
	ft_putendl_fd("exit: too many arguments", 2);
	return (1);
}

int		b_exit(t_shell *s, char **av, int ac)
{
	if (ac > 2)
		return (error_av());
	s->exit = 1;
	if (ac == 2 && ft_stris(av[1], &ft_isdigit))
		return (ft_atoi(av[1]));
	return (0);
}
