/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:55:58 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/08/22 15:43:45 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*free_and_reset(char **bu, char **temp);
char	*return_res(int i, char **res, char **bu);
size_t	get_strlen(const char *s);
char	*get_strjoin(char *s1, char *s2);
char	*get_strdup(char *s);
char	*get_substr(char const *s, unsigned int start, size_t len);
char	*eqal_substr(char *s, unsigned int start, size_t len);
int		f_ent(char *a);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
