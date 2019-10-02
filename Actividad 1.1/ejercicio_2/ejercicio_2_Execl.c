/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_2_Execl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:46:19 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 00:02:19 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int main(void)
{
       printf("Ejemplo de uso de exec():");      
       printf("Los archivos en el directorio son:\n");
       execl("/bin/ls", "ls", "-la",(char *)NULL);
       printf("¡¡¡ Esto no se ejecuta !!!\n");
}
