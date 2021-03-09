/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command_builtins.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 22:34:26 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 06:22:26 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		(*get_fct(char *name))(t_shell*, char**, int)
{
	if (!ft_strcmp(name, "cd"))
		return (&b_cd);
	else if (!ft_strcmp(name, "echo"))
		return (&b_echo);
	else if (!ft_strcmp(name, "env"))
		return (&b_env);
	else if (!ft_strcmp(name, "exit"))
		return (&b_exit);
	else if (!ft_strcmp(name, "setenv"))
		return (&b_setenv);
	else if (!ft_strcmp(name, "unsetenv"))
		return (&b_unsetenv);
	return (NULL);
}

int		command_builtins(t_shell *s, char **args)
{
	int		(*fct)(t_shell*, char**, int);

	if (!(fct = get_fct(args[0])))
		return (0);
	s->res = fct(s, args, args_len(args));
	return (1);
}
