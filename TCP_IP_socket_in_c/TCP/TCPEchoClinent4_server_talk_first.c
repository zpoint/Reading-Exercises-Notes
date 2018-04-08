#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Practical.h"

# define HELLO "HELLO!"

void recv_bytes(int sock, const size_t recvLength)
{
		size_t totalBytesRcvd = 0;
		while (totalBytesRcvd < recvLength)
		{
				char buffer[BUFSIZ];
				ssize_t numBytes = recv(sock, buffer, BUFSIZ - 1, 0);
				if (numBytes < 0)
						DieWithSystemMessage("recv() failed");
				else if (numBytes == 0)
						DieWithUserMessage("recv()", "connection closed permaturely");
				totalBytesRcvd += numBytes;
				buffer[numBytes] = '\0';
				fputs(buffer, stdout);
		}
		fputc('\n', stdout);
}

void pr_sock_name(int sock, const char *funName, int (*fun)(int, struct sockaddr *, socklen_t *))
{
		struct sockaddr_in targetAddr;
		socklen_t targetAddrLen = sizeof(targetAddr);
		int r = fun(sock, (struct sockaddr *)&targetAddr, &targetAddrLen);
		if (r < 0)
				DieWithUserMessage(funName, "failed");
		char targetName[INET_ADDRSTRLEN];
		if (inet_ntop(AF_INET, &targetAddr.sin_addr.s_addr, targetName, sizeof(targetName)) != NULL)
				printf("%s: %s/%d\n", funName, targetName, ntohs(targetAddr.sin_port));
		else
				printf("Unable to get %s address", funName);
}

int main(int argc, char *argv[])
{
		if (argc < 3 || argc > 4)
				DieWithUserMessage("Parameter(s)",
								"<Server Address> <Echo Word> [<Server Port>]");

		char *servIP = argv[1]; // server IP address
		char *echoString = argv[2];

		// Third arg (optional): server port (numeric). 7 is well-known echo port
		in_port_t servPort = (argc == 4) ? atoi(argv[3]) : 7;

		// create a reliable, stream socket using TCP
		int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sock < 0)
				DieWithSystemMessage("socket() failed");

		// Construct the server address structure
		struct sockaddr_in servAddr; // Server address
		memset(&servAddr, 0, sizeof(servAddr)); // Zero out structure
		servAddr.sin_family = AF_INET; // IPv4 address family

		// Convert address
		int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
		if (rtnVal == 0)
				DieWithUserMessage("inet_pton() failed", "invalid address string");
		else if (rtnVal < 0)
				DieWithSystemMessage("inet_pton() failed");
		servAddr.sin_port = htons(servPort); // Server port

		// Establish the connection to the echo server
		if (connect(sock, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0)
				DieWithSystemMessage("connect() failed");

		pr_sock_name(sock, "getpeername", getpeername);
		pr_sock_name(sock, "getsockname", getsockname);
		size_t echoStringLen = strlen(echoString); // Determine input length

		// recv hello from server
		recv_bytes(sock, strlen(HELLO));
		// Send the string to the server
		ssize_t numBytes = send(sock, echoString, echoStringLen, 0);
		if (numBytes < 0)
				DieWithSystemMessage("send() failed");
		else if (numBytes != echoStringLen)
				DieWithUserMessage("send()", "sent unexpected number of bytes");
		recv_bytes(sock, echoStringLen);
		close(sock);
		exit(0);
}
