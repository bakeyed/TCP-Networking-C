#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main () {

	// Defining the variables
	int sock;
	struct sockaddr_in addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;

	char *ip="127.0.0.1";
	int port = 5566;

	// Creating socket
	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == -1) {
		perror("[-] Failed to create a socket");
		exit(1);
	} 
	printf("[+] Client socket created successfully\n");
	

	// Configuring the server address 
	memset(&addr, '\0', sizeof(addr));
	addr.sin_family = AF_INET;
    addr.sin_port = port;
	addr.sin_addr.s_addr = inet_addr(ip);

    connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    printf("Connected to server \n");

    return 0;
}