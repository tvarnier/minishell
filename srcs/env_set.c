/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_set.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 22:01:50 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 13:36:36 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		error_env_name(void)
{
	ft_putendl_fd("setenv: Variable name must contain alphanumeric characters."
			, 2);
	return (1);
}

int		ft_ispath(int c)
{
	return (((ft_isalpha(c)) || (ft_isdigit(c)) || (c == '_')) ? 1 : 0);
}

char	**realloc_env(char **env, char *str, int ind)
{
	char	**new;
	int		len;
	int		i;
	int		y;

	new = NULL;
	ind = (str) ? -1 : ind;
	len = (!str) ? env_len(env) - 1 : env_len(env) + 1;
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		return (NULL);
	new[len] = NULL;
	i = -1;
	y = 0;
	while (env[++i])
	{
		if (i == ind)
			ft_strdel(&(env[i]));
		else
			new[y++] = env[i];
	}
	if (str)
		new[y] = str;
	ft_memdel((void**)&env);
	return (new);
}

int		set_env(char ***env, char *var, char *value)
{
	int		ind;
	char	*str;

	if (!ft_stris(var, &ft_ispath))
		return (error_env_name());
	str = NULL;
	if (value)
		str = ft_strrjoin(var, value, '=');
	else
		str = ft_strrjoin(var, "", '=');
	if ((ind = get_env_index(*env, var)) >= 0)
	{
		ft_strdel(&((*env)[ind]));
		(*env)[ind] = str;
	}
	else
		*env = realloc_env(*env, str, -1);
	return (0);
}

int		unset_env(char ***env, char *var)
{
	int		ind;
	char	**new;

	if (!ft_strcmp(var, "*"))
	{
		free_env(*env);
		new = NULL;
		if (!(new = (char**)ft_memalloc(sizeof(char*) * 1)))
			return (1);
		new[0] = NULL;
		*env = new;
	}
	else if ((ind = get_env_index(*env, var)) >= 0)
		*env = realloc_env(*env, NULL, ind);
	return (0);
}
