/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 05:50:04 by mjabri            #+#    #+#             */
/*   Updated: 2025/11/25 13:59:48 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL
# define GNL

# include <fcntl.h>
# include <stdio.h> // test
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100000

int		ft_strnlen(char *str);
char	*ft_strnjoin(char *str1, char *str2);
char	*ft_strdup(char *str);
char	*n_line_check(char *str, char *to_next, ssize_t index);

#endif
