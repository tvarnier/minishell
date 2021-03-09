/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command_launch.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 22:12:08 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 01:14:26 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char ***args)
{
	int		i;

	if (*args)
	{
		i = -1;
		while ((*args)[++i])
			ft_strdel(&((*args)[i]));
		ft_memdel((void**)&(*args));
	}
}

int		args_len(char **args)
{
	int		i;

	i = 0;
	if (args)
	{
		while (args[i])
			i++;
	}
	return (i);
}

char	**args_ins(char ***args, char *ins, int ind)
{
	int		i;
	int		len;
	char	**new;

	len = args_len(*args);
	if (ind < 0 || ind > len)
		return (*args);
	new = NULL;
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (len + 2))))
		return (*args);
	new[len + 1] = NULL;
	i = -1;
	while (++i < ind)
		new[i] = (*args)[i];
	new[i] = ins;
	while (++i <= len)
		new[i] = (*args)[i - 1];
	ft_memdel((void**)&(*args));
	return (new);
}

char	**init_args(char **split, int *i)
{
	int		y;
	char	**args;

	y = 0;
	while (split[*i + y] && ft_strcmp(split[*i + y], ";"))
		y++;
	args = NULL;
	if (!(args = (char**)ft_memalloc(sizeof(char*) * (y + 1))))
		return (NULL);
	y = 0;
	while (split[*i + y] && ft_strcmp(split[*i + y], ";"))
	{
		args[y] = split[*i + y];
		y++;
	}
	args[y] = NULL;
	*i += (!split[*i + y]) ? y : y + 1;
	return (args);
}

void	launch_command(t_shell *s, char *line)
{
	char	**split;
	int		i;

	if (!(split = split_args(s, line)))
	{
		ft_strdel(&line);
		return ;
	}
	i = 0;
	if (args_len(split) > 0)
	{
		if (!ft_strcmp(split[0], "ls"))
			split = args_ins(&split, ft_strdup("-G"), 1);
		s->res = 1;
		if (!command_builtins(s, split))
		{
			if (!command_system(s, split))
				error_cmd_not_found(split[0]);
		}
	}
	free_args(&split);
}
