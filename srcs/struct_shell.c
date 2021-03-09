/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_shell.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 15:56:46 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 14:39:50 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		env_len(char **env)
{
	int		len;

	len = 0;
	while (env[len])
		len++;
	return (len);
}

void	init_shell(t_shell *s)
{
	extern char		**environ;
	int				len;
	int				i;

	len = env_len(environ);
	s->env = NULL;
	if (!(s->env = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		return ;
	s->env[len] = NULL;
	i = -1;
	while (environ[++i])
		s->env[i] = ft_strdup(environ[i]);
	s->exit = 0;
	s->res = 0;
}

void	free_shell(t_shell *s)
{
	if (s->env)
		free_env(s->env);
}
