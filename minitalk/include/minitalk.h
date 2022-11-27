/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:38:31 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/27 05:41:44 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_server_stat {
	char	*str;
	size_t	len;
	size_t	bits;
}	t_server_stat;

typedef struct s_client_stat {
	pid_t	ppid;
	char	*str;
	size_t	bits;
}	t_client_stat;

#endif
