/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:20:38 by mjabri            #+#    #+#             */
/*   Updated: 2025/11/30 13:47:02 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *gnl_bns(char *src)
{
    int i;
    char *str;

    i = 0;
    while (src[i] && src[i] != '\n')
        i++;
    str = ft_calloc_bns(i + 2);
    if (!str)
        return (NULL);
    i = 0;
    while (src[i] && src[i] != '\n')
    {
        str[i] = src[i];
        i++;
    }
    if (src[i] == '\n')
    {
        str[i++] = '\n';
    }
    str[i] = '\0';
    return (str);
}

char *ft_rread_bns(char *str, int fd)
{
    char *buffer;
    int i;

    if (!str)
        str = ft_calloc_bns(1);
    buffer = ft_calloc_bns(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    i = 1;
    while (i > 0)
    {
        i = read(fd, buffer, BUFFER_SIZE);
        if (i == -1)
            return (NULL);
		buffer[i] = '\0';
        str = ft_strnjoin_bns(str, buffer);
        if (!str)
            return (NULL);
        if (new_line_search_bns(buffer) == 1)
            break;
    }
    free(buffer);
	if (str[0] == '\0')
		return (NULL);
    return (str);
}

char *get_next_line_bonus(int fd)
{
    static char *folder[1024];
    char *str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    folder[fd] = ft_rread_bns(folder[fd], fd);
    if (!folder[fd])
        return (NULL);
    str = gnl_bns(folder[fd]);
    folder[fd] = ft_line_bns(folder[fd]);
    return (str);
}

// #include <stdio.h>

// int main(void)
// {
// 	int fd1 = open("file1.txt",O_RDONLY);
// 	int fd2 = open("file2.txt",O_RDONLY);
// 	int fd3 = open("file3.txt",O_RDONLY);
	
// 	char *str1 = get_next_line_bonus(fd1);
// 	char *str2 = get_next_line_bonus(fd2);
// 	char *str3 = get_next_line_bonus(fd3);
	
// 	printf("file1 : %s",str1);
// 	printf("file2 : %s",str2);
// 	printf("file3 : %s",str3);
	
// }
