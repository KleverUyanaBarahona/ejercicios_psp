/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:52:08 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 01:17:58 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
    unsigned int var = 6;
     pid_t pidC;
    pidC = fork();
    if(pidC > 0)
    {
        printf("Valor inicial de la variable: %i\n", var);
        var -= 5;
        printf("Variable en Proceso Hijo %i\n", var);
    }
    else if (pidC == 0)
    {
        var += 5;
        printf("Variable en Proceso Padre %i\n", var);
    }
    else
    {
         printf("Error al crear el hijo");
    }
    
    
    return(0);
}