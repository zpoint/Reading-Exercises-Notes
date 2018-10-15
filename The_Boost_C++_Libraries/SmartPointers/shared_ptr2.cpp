#include <boost/shared_ptr.hpp>
#include <Windows.h>

/* shared_ptr with a user-defined deleter */

int main()
{
		boost::shared_ptr<void> handle(OpenProcess(PROCESS_SET_INFORMATION, FALSE, GetCurrentProcessId()), CloseHandle);
		return 0;
}
