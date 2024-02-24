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
        int serverSocket=0;
        struct sockaddr_in serverAddress;
        char input[1000];
        char buffer[1024];
        char buffer1[1024];
        char *rock = "ROCK";
        char *paper = "PAPER";
        char *scissor = "SCISSOR";

        serverSocket = socket(PF_INET, SOCK_STREAM, 0);
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(PORTNUM);
        serverAddress.sin_addr.s_addr = INADDR_ANY;

    int bin=inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    while (1) {

            int connectionSocket= connect(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

            printf("Enter your choice (ROCK, PAPER or SCISSOR): ");
            scanf("%s", input);

            // check for valid input
            if (strcmp(input, rock) != 0 && strcmp(input, paper) != 0 && strcmp(input, scissor) != 0) {
                printf("Invalid input. Please try again.\n");
                continue;
            }

            send(serverSocket, input, strlen(input), 0);  // sent the input to server

            memset(buffer, 0, sizeof(buffer));
            recv(serverSocket, buffer, sizeof(buffer),0);
            printf("Server choice: %s\n", buffer);       // show server output
            printf("Do you want to try again? (y/n): ");
            scanf(" %c", &input[0]);
            if (input[0] == 'n' || input[0] == 'N') {
                break;
            }
    }
    return 0;
}
