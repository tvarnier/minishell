/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_setenv.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 22:44:56 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 13:38:05 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		error_args(void)
{
	ft_putendl_fd("setenv: Too many arguments.", 2);
	return (1);
}

int		b_setenv(t_shell *s, char **av, int ac)
{
	if (ac == 2)
		return (set_env(&s->env, av[1], NULL));
	else if (ac == 3)
		return (set_env(&s->env, av[1], av[2]));
	else if (ac >= 3)
		return (error_args());
	else
		print_env(s->env);
	return (0);
}
