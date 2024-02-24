#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORTNUM 8080
#define BACKLOG 10

int main(void) {

        struct sockaddr_in serverAddress;
        char *rock = "ROCK";
        char *paper = "PAPER";
        char *scissor = "SCISSOR";

        int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(PORTNUM);
        serverAddress.sin_addr.s_addr = INADDR_ANY;

        bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

        listen(serverSocket, BACKLOG);

        struct sockaddr_in clientAddress;
        socklen_t clientAddrSize = sizeof(clientAddress);
        int connectionSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddrSize);  // make connection

        while (1) {

            char input[800];
            memset(input, '\0', sizeof(input));
            char output[1000];
            memset(output, '\0', sizeof(output));
            char f_result[1024];
            memset(f_result, '\0', sizeof(f_result));
            read(connectionSocket, input, sizeof(input));   // store client request in "input"
            printf("client choice :%s\n",input);
            // input is n close connection
            if (strcmp(input, "n") == 0) {
                printf("closing connection\n");
                close(connectionSocket);
                close(serverSocket);
                break;
            }

            // lets assign him a radom choice for output
            int choice= rand() % 3;
            if (choice==0){
               strcpy(output, rock);
            }else if(choice==1){
               strcpy(output, paper);
            }else{
               strcpy(output, scissor);
            }
            printf("server choice: %s\n",output);

            // lets decide who won it. For each choice if we got draw resut is zero. If server won result is -1 else 1 for client winning it.
            int result;
            if (strcmp(input, rock) == 0) {
                if (strcmp(output, paper) == 0) {
                         result = -1;
                } else if (strcmp(output, scissor) == 0) {
                         result = 1;
                } else {
                         result = 0;
                }

            } else if (strcmp(input, paper) == 0) {
                if (strcmp(output, scissor) == 0) {
                        result = -1;
                } else if (strcmp(output, rock) == 0) {
                         result = 1;
                } else {
                         result = 0;
                  }

            } else if (strcmp(input, scissor) == 0) {
                if (strcmp(output, rock) == 0) {
                         result = -1;
                } else if (strcmp(output, paper) == 0) {
                         result = 1;
                } else {
                         result = 0;
                }
            } else {

                    result = -2;

            }


            // Lets send the final result

            if (result == -2) {
            } else if (result == -1) {
                strcpy(f_result, "\nYou lose");
            } else if (result == 0) {
                 strcpy(f_result, "\nTie");
                } else {
                 strcpy(f_result, "\nYou win");
            }

            printf("result: %s\n",f_result);
            strcat(output,f_result);
            write(connectionSocket, output, sizeof(output));
      }
        return 0;
}
