#include "PreCompiled.h"

//class header file
#include "Logger.h"


Logger* Logger::pInstance = nullptr;

Logger::Logger()
: outStream()
, fileLocation("Data/Logs/")
{
	pInstance = this;

	std::time_t time = std::time(NULL);
	char* strTime = std::asctime(std::localtime(&time));
	strTime[strlen(strTime) - 1] = '\0';
	fileLocation.append(strTime);
	fileLocation.append(".txt");
	std::replace(fileLocation.begin(), fileLocation.end(), ':', '-');

	outStream.open(fileLocation, std::ios::out);
	if (outStream.is_open())
		LOG("Began Logging");	
	else
		std::cout << "Error Opening Log File" << std::endl;
}

Logger::~Logger()
{
	if (outStream.is_open())
	{
		outStream
			<< "END OF SESSION" << "\n"
			<< "==========================================" << "\n\n\n\n";
		outStream.close();
	}
}

void Logger::Log(const std::string& message, long lineNumber, const std::string& fileName, const std::string& functionName)
{
	if (outStream.is_open())
	{
		std::time_t time = std::time(NULL);
		char* strTime = std::asctime(std::localtime(&time));
		outStream
			<< "--> " << strTime
			<< "Message : " << message << "\n"
			<< "File Name : " << fileName << "\n"
			<< "Function : " << functionName << "\n"
			<< "Line Number: " << lineNumber
			<< "\n\n" << std::endl;
	}
}

void Logger::LogWarning(const std::string& message, long lineNumber, const std::string& fileName, const std::string& functionName)
{
	if (outStream.is_open())
	{
		std::time_t time = std::time(NULL);
		char* strTime = std::asctime(std::localtime(&time));

		outStream
			<< "--> " << strTime
			<< "WARNING : " << message << "\n"
			<< "File Name : " << fileName << "\n"
			<< "Function : " << functionName << "\n"
			<< "Line Number: " << lineNumber
			<< "\n\n" << std::endl;
	}
}

void Logger::LogError(const std::string& message, long lineNumber, const std::string& fileName, const std::string& functionName)
{
	if (outStream.is_open())
	{
		std::time_t time = std::time(NULL);
		char* strTime = std::asctime(std::localtime(&time));

		outStream
			<< "--> " << strTime
			<< "ERROR : " << message << "\n"
			<< "File Name : " << fileName << "\n"
			<< "Function : " << functionName << "\n"
			<< "Line Number: " << lineNumber
			<< "\n\n" << std::endl;
	}

	exit(-1);
}