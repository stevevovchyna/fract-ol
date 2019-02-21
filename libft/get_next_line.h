/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:58:36 by svovchyn          #+#    #+#             */
/*   Updated: 2018/11/20 15:58:16 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1

# define INI() static char *data; char *t; char b[BUFF_SIZE + 1]; int r, n; PRE()
# define PRE() if (BUFF_SIZE < 1 || fd < 0 || !line) R(-1); RUN();

# define RUN() while ((r = read(fd, b, BUFF_SIZE)) > 0) GETDATA();
# define GETDATA() { MLLCDATA(); JOINSTR(); BREAK(); } RETURN();
# define MLLCDATA() if (!data && !(data = ft_strnew(0))) R(-1)
# define JOINSTR() b[r] = '\0'; t = ft_strjoin(data, b); REFER();
# define REFER() FREE(data); data = t;
# define FREE(str) ft_strdel(&str);
# define BREAK() if (ft_strchr(b, '\n')) break ;

# define RETURN() ERRCHECK(); EOFCHECK(); EOLCHECK();
# define ERRCHECK() if (r < 0) R(-1);
# define EOFCHECK() if (r == 0 && (!data || !data[0])) R(0);
# define EOLCHECK() GETNL(); CASE1() CASE0(); R(1);
# define GETNL() n = -1; while (data[++n] && data[n] != '\n') ;
# define CASE1() if (data[n] == '\n') { SUBLINE(); TEMPREST(); }
# define SUBLINE() *line = ft_strsub(data, 0, n);
# define TEMPREST() t = ft_strdup(data + (n + 1)); REFER();
# define CASE0() else if (data[n] == '\0') { DUPLINE(); }
# define DUPLINE() *line = ft_strdup(data); FREE(data);

# define R(n) return (n);

#endif
