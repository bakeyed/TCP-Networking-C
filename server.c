//TCP client server 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main () {

	// Defining the variables
	int server_socket, client_socket;
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_addr_size;
	char buffer[1024];
	int n;

	char *ip="127.0.0.1";
	int port = 5566;

	// Creating socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	//AF_INET is for IPv4, AF_INET6 is for IPv6
	//AF_LOCAL is for local address
	//SOCK_STREAM is for TCP

	if (server_socket == -1) {
		perror("[-] Failed to create a socket");
		exit(1);
	} 
	printf("[+] Server socket created successfully\n");
	

	// Configuring the server address 
	memset(&server_addr, '\0', sizeof(server_addr));
	server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
	server_addr.sin_addr.s_addr = inet_addr(ip);

	//Binding the socket to IP/Port
	n = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (n < 0) {
		perror("[-] Failed to bind socket");
        exit(1);
	}
	printf("[+] Bind to port number %d\n", port);
	
	//Listening for incoming connections
	if (listen(server_socket, 5) < 0) {
		perror("[-] Failed to listen");
        exit(1);
	}

	printf("[+] Server is listening...\n");

	// Accepting incoming connections
	client_addr_size = sizeof(client_addr);
	client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);

	if (client_socket < 0) {
    printf("Connection failed\n");
    exit(1);
	}
	printf("[+] Client connected\n");

	return 0;
}
