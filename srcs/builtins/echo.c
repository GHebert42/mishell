/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:53:52 by loadjou           #+#    #+#             */
/*   Updated: 2022/11/17 18:55:09 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    echo(char **cmd)
{
    printf("%s", cmd[2]);
    if(ft_strcmp(cmd[1], "-n") != 0)
        printf("\n");
}