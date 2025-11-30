/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:20:42 by mjabri            #+#    #+#             */
/*   Updated: 2025/11/30 13:32:48 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void *ft_calloc_bns(size_t nmemb)
{
    size_t i;
    char *str;

    str = malloc(nmemb);
    if (!str)
        return (NULL);
    i = 0;
    while (i < nmemb)
        str[i++] = 0;
    return (str);
}

int ft_strnlen_bns(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int new_line_search_bns(char *str)
{
    int i;

    i = 0;
    while (str[i])
	{
		if (str[i] =='\n')
			return 1;
		i++;
	}
	return 0;
}

char *ft_strnjoin_bns(char *src1, char *src2)
{
    char *str;
    int s1;
    int s2;
    int i;

    if (!src1 || !src2)
        return (NULL);
    str = ft_calloc_bns(ft_strnlen_bns(src1) + ft_strnlen_bns(src2) + 1);
    if (!str)
        return (NULL);
    i = 0;
    s1 = 0;
    s2 = 0;
    while (src1[s1])
        str[i++] = src1[s1++];
    while (src2[s2])
        str[i++] = src2[s2++];
    str[i] = '\0';
    return (str);
}

char *ft_line_bns(char *str)
{
    int i;
    char *line;
    int index;

    i = 0;
    index = 0;
    while (str[i] && str[i] != '\n')
        i++;
    line = ft_calloc_bns(ft_strnlen_bns(str) - i + 1);
    if (!line || (str[i] == '\0'))
        return (NULL);
    i++;
    while (str[i])
        line[index++] = str[i++];
    line[index] = '\0';
    free(str);
    return (line);
}
