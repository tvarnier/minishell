/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 22:54:45 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 06:22:40 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
}

void	free_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_strdel(&(env[i]));
	ft_memdel((void**)&(env));
}

char	*get_env(char **env, char *search)
{
	int		i;
	int		len;
	char	*str;

	str = ft_strjoin(search, "=");
	len = (int)ft_strlen(str);
	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], str, len))
		{
			ft_strdel(&str);
			return (env[i] + len);
		}
	ft_strdel(&str);
	return (NULL);
}

int		get_env_index(char **env, char *search)
{
	int		i;
	int		len;
	char	*str;

	str = ft_strjoin(search, "=");
	len = (int)ft_strlen(str);
	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], str, len))
		{
			ft_strdel(&str);
			return (i);
		}
	ft_strdel(&str);
	return (-1);
}

char	**get_paths(char **env)
{
	return (ft_strsplit(get_env(env, "PATH"), ':'));
}
