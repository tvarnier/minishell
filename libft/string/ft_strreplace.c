/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strreplace.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 22:36:51 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 04:09:02 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		count_rep(char *str, char *rep)
{
	if (!str || !(*str) || !ft_strstr(str, rep))
		return (0);
	return (count_rep(ft_strstr(str, rep) + (int)ft_strlen(rep), rep) + 1);
}

char	*replace(char *str, char *rep, char *with, int len)
{
	char	*new;
	int		i;
	char	*tmp;

	new = NULL;
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = 0;
	tmp = ft_strstr(str, rep);
	while (*str)
		if (tmp && str == tmp)
		{
			i = ft_strins(new, with, i);
			str += (int)ft_strlen(rep);
			tmp = ft_strstr(str, rep);
		}
		else
		{
			new[i++] = *str;
			str++;
		}
	return (new);
}

char	*ft_strreplace(char *str, char *rep, char *with)
{
	int		len;

	len = count_rep(str, rep);
	if (!len)
		return (NULL);
	len = (int)ft_strlen(str) - len * (int)ft_strlen(rep)
		+ len * (int)ft_strlen(with);
	return (replace(str, rep, with, len));
}
