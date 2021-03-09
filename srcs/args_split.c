/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   args_split.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 05:46:15 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/07 19:06:33 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	check_quote(char *line, int i, char quote)
{
	if (quote == 0 && line[i] == '"' && (i == 0 || line[i - 1] != '\\'))
		quote = '"';
	else if (quote == '"' && line[i] == '"' && (i == 0 || line[i - 1] != '\\'))
		quote = 0;
	else if (quote == 0 && line[i] == '\'')
		quote = '\'';
	else if (quote == '\'' && line[i] == '\'')
		quote = 0;
	return (quote);
}

int		count_args(char *line)
{
	int		i;
	int		nbr;
	char	quote;

	nbr = 0;
	i = -1;
	quote = 0;
	while (line[++i])
	{
		if (quote == 0 && line[i] != ' ' && (i == 0 || line[i - 1] == ' '))
			nbr++;
		quote = check_quote(line, i, quote);
	}
	if (quote != 0)
		return (print_quote(quote));
	return (nbr);
}

char	**split_args(t_shell *s, char *line)
{
	char	**args;
	char	*tmp;
	int		nbr_args;

	tmp = NULL;
	if ((nbr_args = count_args(line)) == -1)
	{
		if ((tmp = get_command(s)))
		{
			line = ft_strrep(line, ft_strjoin(line, tmp));
			ft_strdel(&tmp);
			return (split_args(s, line));
		}
	}
	if (!nbr_args)
		return (NULL);
	args = NULL;
	if (!(args = (char**)ft_memalloc(sizeof(char*) * (nbr_args + 1))))
		return (NULL);
	args[nbr_args] = NULL;
	alloc_args(s, args, line);
	ft_strdel(&line);
	return (args);
}
