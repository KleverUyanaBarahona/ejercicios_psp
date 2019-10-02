/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio_pipes_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kleveruyana <kleveruyana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:10:45 by kleveruyana       #+#    #+#             */
/*   Updated: 2019/10/02 12:19:48 by kleveruyana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//informacion de padre a hijo
int main(void)
{
  int fd[2];
  pid_t pid;
  char *saludoPadre="Buenos dias hijo...";
  char buffer[80];

  pipe(fd);   //creo pipe
  pid=fork(); //creo proceso 

 switch(pid) {
   case -1 : //ERROR
           printf("NO SE HA PODIDO CREAR HIJO...");
           exit(-1);           
   case 0 : //HIJO RECIBE
            close(fd[1]);//cierra el descriptor de entrada
            read(fd[0], buffer, sizeof(buffer)); //lee el pipe            
            printf("\tEl HIJO recibe algo del pipe: %s\n",buffer);                 
            
            break;   
   default ://PADRE ENVIA         
            close(fd[0]);
            write(fd[1], saludoPadre, strlen(saludoPadre));//escribe en el pipe
            printf("El PADRE ENVIA MENSAJE AL HIJO...\n");    
            wait(NULL); //espero al proceso hijo
            break;
 }  
 return (0);
}