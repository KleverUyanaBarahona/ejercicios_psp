/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_2_2_Execl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:45:44 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 00:02:20 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
int main(void)
{
    printf("Listado de procesos/n");
    if (execl("/bin/ps", "ps", "-f", (char *)NULL < 0))
        printf("Error en execl %d\n",errno);
    else
        printf("Fin de la lista de procesos\n");
        return (0);
}