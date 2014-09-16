#pragma once

class Logger
{
public:
	static Logger* pInstance;

public:

	Logger();
	~Logger();

public:

	// logs the provided message to the log
	void Log(const std::string& message, long lineNumber, const std::string& fileName, const std::string& functionName);
	// logs a warning to the log
	void LogWarning(const std::string& message, long lineNumber, const std::string& fileName, const std::string& functionName);
	// logs an error to the log
	void LogError(const std::string& message, long lineNumber, const std::string& fileName, const std::string& functionName);

private:

	std::ofstream outStream;
	std::string fileLocation;
};