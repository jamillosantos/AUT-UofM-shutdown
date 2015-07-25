#include <iostream>
#include <sys/stat.h>

#include <unistd.h>
#include <time.h>
#include <fstream>

#define SHUTDOWNFILE "/tmp/shutdown-file"

double getFileTime()
{
	struct tm *clock;
	struct stat attrib;
	int ret = stat(SHUTDOWNFILE, &attrib);
	if (ret == 0)
	{
		return attrib.st_mtim.tv_sec + (attrib.st_mtim.tv_nsec / 1000000000.0);
	}
	else
	{
		return 0;
	}
}

double nowTime()
{
	timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	return time.tv_sec + (time.tv_nsec / 1000000000.0);
}

int main()
{
	double
		fileTime = getFileTime(),
		now = nowTime(),
		diff = (now - fileTime);
	if ((diff < 1.0) && (diff >= 0))
	{
		std::cout << "Starting shutting down..." << std::endl;
		int ret = system("shutdown -h -P now \"Power button double pressed.\"");
		std::cout << "SYSTEM Result: " << ret << std::endl;
	}
	else
	{
		std::ofstream file;
		file.open(SHUTDOWNFILE, std::ofstream::trunc);
		if (file.is_open())
		{
			file.write("", 1);
			file.close();
			std::cout << "Shutdown file touched." << std::endl;
		}
		else
		{
			std::cerr << "Error creating the file." << std::endl;
		}
	}
	return 0;
}
