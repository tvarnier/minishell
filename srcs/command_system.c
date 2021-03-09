/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command_system.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 22:08:05 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/07 19:11:54 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		exec_command(t_shell *s, char **args, char *path)
{
	pid_t		father;
	int			waitstatus;

	father = fork();
	if (father > 0)
	{
		wait(&waitstatus);
		s->res = WEXITSTATUS(waitstatus);
	}
	if (father == 0)
		execve(path, args, s->env);
	return (1);
}

int		command_system(t_shell *s, char **args)
{
	int				i;
	char			*path;
	struct stat		sb;
	int				res;
	char			**paths;

	res = 0;
	if ((paths = get_paths(s->env)))
	{
		i = -1;
		while (res == 0 && paths[++i])
		{
			path = ft_strrjoin(paths[i], args[0], '/');
			if (lstat(path, &(sb)) > -1 && !access(path, X_OK))
				res = exec_command(s, args, path);
			ft_strdel(&path);
		}
		free_args(&paths);
	}
	if (res == 0)
	{
		if (lstat(args[0], &sb) > -1 && !access(args[0], X_OK))
			res = exec_command(s, args, args[0]);
	}
	return (res);
}
