/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:18:42 by hakaraka          #+#    #+#             */
/*   Updated: 2023/02/14 10:46:50 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);

#endif