/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_1_System.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:46:37 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 00:02:31 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  printf("Ejemplo de uso de system():");
  printf("\n\tListado del directorio actual y envio a un fichero:");
  printf("%d",system("ls > ficsalida"));
  printf("\n\tAbrimos con el gedit el fichero...");
  printf("%d",system("gedit ficsalida"));
  printf("\n\tEste comando es erroneo: %d",system("ged"));
  printf("\nFin de programa....\n");
}
