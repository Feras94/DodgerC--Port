#include "PreCompiled.h"

#include "Application.h"
#include "Logger.h"

int main()
{
	Logger logger = Logger();

	Application app = Application();
	int exitCode = app.Run();

	LOG("Exiting with exit code " + std::to_string(exitCode));
	return (exitCode);
}