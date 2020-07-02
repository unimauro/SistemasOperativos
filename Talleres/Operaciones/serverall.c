#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
 
int main(int argc , char *argv[])
{
    int socket_desc , new_socket , c;
    struct sockaddr_in server , client;
    char *message;
     
    //Creacion de Socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("No se pudo crear el  socket");
    }
     
    //Preparar el sockaddr_in
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind fallo");
        return 1;
    }
    puts("bind bien");
     
    //Escuchar
    listen(socket_desc , 3);
     
    //Aceptacion y Comunicacion
    puts("Esperando por Conecciones...");
    c = sizeof(struct sockaddr_in);
    while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Coneccion aceptada");
         
        //Respuesta al Cliente
        message = "Hola \n";
        write(new_socket , message , strlen(message));
    }
     
    if (new_socket<0)
    {
        perror("aceptacion fallada");
        return 1;
    }
     
    return 0;
}
