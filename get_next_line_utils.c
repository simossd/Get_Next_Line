/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:51:26 by mjabri            #+#    #+#             */
/*   Updated: 2025/11/25 13:55:17 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *str1, char *str2)
{
	int		i;
	int		i2;
	int		i3;
	char	*temp;

	if (!str1 || !str2)
		return (NULL);
	temp = malloc(ft_strnlen(str1) + ft_strnlen(str2) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	i2 = 0;
	i3 = 0;
	while (str1[i2])
		temp[i++] = str1[i2++];
	while (str2[i3])
		temp[i++] = str2[i3++];
	temp[i] = '\0';
	return (temp);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	dup = malloc(ft_strnlen(str) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i++] = '\0';
	return (dup);
}

char	*n_line_check(char *str, char *to_next, ssize_t index)
{
	int		checker;
	char	*line;
	int		big_line;
	int next_return;
	
	big_line = ft_strnlen(str);
	line = malloc(big_line - index + 2);
	checker = 0;
	next_return = 0;
	while (str[checker] && str[checker] != '\n')
	{
		line[checker] = str[checker];
		checker++;
	}
	line[checker++] = '\n';
	line[checker] = '\0';
	while (checker < big_line)
		to_next[next_return++] = str[checker++];
	to_next[next_return] = '\0';
	free(str);
	return (line); 
}
