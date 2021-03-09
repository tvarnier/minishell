/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_cd.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 00:13:49 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 17:01:35 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		error_cd(char *str, int num)
{
	if (num == 1)
		ft_putendl_fd("cd: too many arguments", 2);
	else if (num == 2)
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (num == 3)
		ft_putstr_fd("cd: string not in pwd: ", 2);
	else if (num == 4)
		ft_putstr_fd("cd: permission denied: ", 2);
	if (str)
	{
		ft_putendl_fd(str, 2);
		ft_strdel(&str);
	}
	return (1);
}

int		b_cd_replace(t_shell *s, char **av)
{
	char			*tmp;
	struct stat		sb;
	char			str[BUFFER];

	if (!get_env(s->env, "PWD"))
		set_env(&s->env, "PWD", getcwd(str, BUFFER));
	if (!(tmp = ft_strreplace(get_env(s->env, "PWD"), av[1], av[2])))
		return (error_cd(ft_strdup(av[1]), 3));
	if (!lstat(tmp, &sb))
	{
		if (!chdir(tmp))
		{
			set_env(&s->env, "OLDPWD", get_env(s->env, "PWD"));
			set_env(&s->env, "PWD", tmp);
			ft_strdel(&tmp);
		}
		else
			return (error_cd(tmp, 4));
	}
	else
		return (error_cd(tmp, 2));
	return (0);
}

int		b_cd_normal(t_shell *s, char **av)
{
	char			str[BUFFER];
	struct stat		sb;
	char			*path;

	path = NULL;
	if (!ft_strcmp(av[1], "-") && get_env(s->env, "OLDPWD"))
		path = ft_strdup(get_env(s->env, "OLDPWD"));
	else
		path = ft_strdup(av[1]);
	if (!lstat(path, &sb))
	{
		if (!chdir(path))
		{
			set_env(&s->env, "OLDPWD", get_env(s->env, "PWD"));
			set_env(&s->env, "PWD", getcwd(str, BUFFER));
			ft_strdel(&path);
			return (0);
		}
		else
			return (error_cd(path, 4));
	}
	else
		return (error_cd(path, 2));
}

int		b_cd_home(t_shell *s)
{
	if (get_env(s->env, "HOME") && !chdir(get_env(s->env, "HOME")))
	{
		set_env(&s->env, "OLDPWD", get_env(s->env, "PWD"));
		set_env(&s->env, "PWD", get_env(s->env, "HOME"));
	}
	else if (!chdir("/"))
	{
		set_env(&s->env, "OLDPWD", get_env(s->env, "PWD"));
		set_env(&s->env, "PWD", "/");
	}
	return (0);
}

int		b_cd(t_shell *s, char **av, int ac)
{
	if (ac > 3)
		return (error_cd(NULL, 1));
	else if (ac == 3)
		return (b_cd_replace(s, av));
	else if (ac == 2)
		return (b_cd_normal(s, av));
	else
		return (b_cd_home(s));
}
