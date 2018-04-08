#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "../TCP/Practical.h"

#define MAXSTRINGLENGTH BUFSIZ

int main(int argc, char *argv[])
{
		if (argc != 2)  // Test for correct number of arguments
				DieWithUserMessage("Parameter(s)", "<Server Port/Service>");

		char *service = argv[1]; // First arg: local port/service

		// Construct the server address structure
		struct addrinfo addrCriteria; // Criteria for address
		memset(&addrCriteria, 0, sizeof(addrCriteria)); // Zero out structure
		addrCriteria.ai_family = AF_UNSPEC; // Any address family
		addrCriteria.ai_flags = AI_PASSIVE; // Accept on any address/port
		addrCriteria.ai_socktype = SOCK_DGRAM; // Only datagram socket
		addrCriteria.ai_protocol = IPPROTO_UDP; // Only UDP socket

		struct addrinfo *servAddr; // List of server addresses
		int rtnVal = getaddrinfo(NULL, service, &addrCriteria, &servAddr);
		if (rtnVal != 0)
				DieWithUserMessage("getaddrinfo() failed", gai_strerror(rtnVal));

		// Create socket for incoming connections
		int sock = socket(servAddr->ai_family, servAddr->ai_socktype, servAddr->ai_protocol);
		if (sock < 0)
				DieWithSystemMessage("socket() failed");

		// Bind to the local address
		if (bind(sock, servAddr->ai_addr, servAddr->ai_addrlen) < 0)
				DieWithSystemMessage("bind() failed");

		// Free address list allocated by getaddrinfo()
		freeaddrinfo(servAddr);

		for (;;)
		{
				// Run forever
				struct sockaddr_storage clntAddr; // Client address
				// Set Length of client address structure (in-out parameter)
				socklen_t clntAddrLen = sizeof(clntAddr);

				// Block until receive message from a client
				char buffer[MAXSTRINGLENGTH]; // I/O buffer
				// Size of received message
				printf("Before recvfrom: sizeof(clntAddr): %ld\n", sizeof(clntAddr));
				ssize_t numBytesRecvd = recvfrom(sock, buffer, MAXSTRINGLENGTH, 0, (struct sockaddr *)&clntAddr, &clntAddrLen);
				printf("After recvfrom: sizeof(clntAddr): %ld\n", sizeof(clntAddr));
				if (numBytesRecvd < 0)
						DieWithSystemMessage("recvfrom() failed");

				fputs("Handling client ", stdout);
				PrintSocketAddress((struct sockaddr *)&clntAddr, stdout);
				fputc('\n', stdout);

				// Send received datagram back to the client
				printf("Before sendto: sizeof(clntAddr): %ld\n", sizeof(clntAddr));
				ssize_t numBytesSent = sendto(sock, buffer, numBytesRecvd, 0, (struct sockaddr *)&clntAddr, clntAddrLen);
				printf("After sendto: sizeof(clntAddr): %ld\n", sizeof(clntAddr));
				if (numBytesSent < 0)
						DieWithSystemMessage("sendto() failed");
				else if (numBytesSent != numBytesRecvd)
						DieWithUserMessage("sendto()", "sent unexpected number of bytes");
		}

		// NOT REACHED
}
