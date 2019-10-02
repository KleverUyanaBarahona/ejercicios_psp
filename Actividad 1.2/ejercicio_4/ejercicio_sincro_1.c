/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_sincro_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:06:47 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 13:16:54 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
/*-------------------------------------------*/
/* gestion de señales en proceso padre       */
void manejador( int segnal )
{
 printf("Hijo recibe señal..%d\n", segnal);
}
/*-------------------------------------------*/
int main(void)
{
  int pid_hijo;  
  pid_hijo = fork(); //creamos hijo   
  
  switch(pid_hijo)
  {
     case -1:
          printf( "Error al crear el proceso hijo...\n");
          exit( -1 );        
     case 0:   //HIJO     	         
          signal( SIGUSR1, manejador); //MANEJADOR DE SE—AL EN HIJO
          while(1) {
          };       
     break;    
     default: //PADRE envia 2 seÒales
          sleep(1);
          kill(pid_hijo, SIGUSR1);//ENVIA SE—AL AL HIJO 
          sleep(1);
          kill(pid_hijo, SIGUSR1);//ENVIA SE—AL AL HIJO 
          sleep(1);
     break;
  } 
  return (0);
}