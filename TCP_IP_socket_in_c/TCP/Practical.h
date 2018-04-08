#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "AddressUtility.c"

void DieWithUserMessage(const char *msg, const char *detail)
{
		fputs(msg, stderr);
		fputs(": ", stderr);
		fputs(detail, stderr);
		fputs("\n", stderr);
		exit(1);
}

void DieWithSystemMessage(const char *msg)
{
		perror(msg);
		exit(1);
}

#include "TCPClientUtility.c"
#include "TCPServerUtility.c"
