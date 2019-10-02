/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_sincronizar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:15:42 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 13:19:41 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
/*-------------------------------------------*/
/* gestión de señales en proceso padre       */
void gestion_padre( int segnal )
{
 printf("Padre recibe señal..%d\n", segnal);
}
/* gestión de señales en proceso hijo        */
void gestion_hijo( int segnal )
{
 printf("Hijo recibe señal..%d\n", segnal);
}
/*-------------------------------------------*/
int main(void)
{
  int pid_padre, pid_hijo;
  
  pid_padre = getpid();
  pid_hijo = fork(); //creamos hijo
    
  switch(pid_hijo)
  {
    case -1:
	  printf( "Error al crear el proceso hijo...\n");
      exit( -1 );        
    case 0:   //HIJO     	 
      //tratamiento de la señal en proceso hijo
	  signal( SIGUSR1, gestion_hijo );
      while(1) { //bucle infinito             
       sleep(1);
	   kill(pid_padre, SIGUSR1);//ENVIA SEÑAL AL PADRE
	   pause();//hijo espera hasta que llegue una señal de respuesta
	  }
    break;    
    default: //PADRE 
	  //tratamiento de la señal en proceso padre
      signal( SIGUSR1, gestion_padre );
      while(1)  {
        pause();//padre espera hasta recibir una señal del hijo
	    sleep(1);
	    kill(pid_hijo, SIGUSR1);//ENVIA SEÑAL AL HIJO
      }       
    break;
  } 
  return (0);
}
