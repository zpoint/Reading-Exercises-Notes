#include <iostream>
#include "PracticalSocket.hpp"

using namespace std;

int main(int argc, char *argv[])
{
		try
		{
				// Make a socket to listen for Survey Client connections.
				TCPServerSocket servSock(9431);

				for (;;)
				{
						// Repeatedly accept connections
						TCPSocket *sock = servSock.accept(); // Get nect client connection

						uint32_t val;
						if (sock->recvFully(&val, sizeof(val)) == sizeof(val))
						{
								val = ntohl(val); // Convert to local byte order
								val++;
								val = htonl(val); // Convert to network byte order
								sock->send(&val, sizeof(val)); // Send value back to client
						}

						delete sock; // Close and delete TCPSocket
				}
		} catch (SocketException &e)
		{
				cerr << e.what() << endl; // Report errors to the console
		}
		return 0;
}
