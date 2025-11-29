/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:57:35 by mjabri            #+#    #+#             */
/*   Updated: 2025/11/29 10:12:10 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *gnl(char *src)
{
    int i;
    char *str;

    i = 0;
    while (src[i] && src[i] != '\n')
        i++;
    str = ft_calloc(i + 2);
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

char *ft_rread(char *str, int fd)
{
    char *buffer;
    int i;

    if (!str)
        str = ft_calloc(1);
    buffer = ft_calloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    i = 1;
    while (i > 0)
    {
        i = read(fd, buffer, BUFFER_SIZE);
        if (i == -1)
            return (NULL);
		buffer[i] = '\0';
        str = ft_strnjoin(str, buffer);
        if (!str)
            return (NULL);
        if (new_line_search(buffer) == 1)
            break;
    }
    free(buffer);
	if (str[0] == '\0')
		return (NULL);
    return (str);
}

char *get_next_line(int fd)
{
    static char *folder;
    char *str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    folder = ft_rread(folder, fd);
    if (!folder)
        return (NULL);
    str = gnl(folder);
    folder = ft_line(folder);
    return (str);

}


#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
