#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../TCP/Practical.h"

void InterruptSignalHandler(int signalType); // Interrupt signal handling function
void InterruptSignalHandlerSleep(int);

int main(int argc, char *argv[])
{
		struct sigaction handler; // Signal handler specification structure
		// Set InterruptSignalHandler() as handler function
		handler.sa_handler = InterruptSignalHandlerSleep;
		// Create mask that block all signals
		if (sigfillset(&handler.sa_mask) < 0)
				DieWithSystemMessage("sigfillset() failed");
		handler.sa_flags = 0; // No flags

		// Set signal handling for interrupt signal
		if (sigaction(SIGINT, &handler, 0) < 0)
				DieWithSystemMessage("sigaction failed for SIGINT");

		for (;;)
		{
				printf("begin infinity loop\n");
				pause(); // Suspend program until signal received
				printf("After pause\n");
		}
		
		exit(0);
}

void InterruptSignalHandler(int signalType)
{
		printf("signalType: %d\n", signalType);
		puts("Interrupt Received. Exiting program.");
		exit(1);
}

void InterruptSignalHandlerSleep(int signalType)
{
		printf("signalType: %d\n", signalType);
		puts("Interrupt Received. Going to sleep for 3 seconds\n");
		sleep(3);
		printf("Exiting InterruptSignalHandlerSleep function body\n");
}
