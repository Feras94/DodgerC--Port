#pragma once

#include <exception>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <algorithm>

#include <list>
#include <stack>
#include <queue>
#include <map>
#include <vector>

#include <memory>
#include <cassert>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

#include <Thor\Animation.hpp>
#include <Thor\Graphics.hpp>
#include <Thor\Input.hpp>
#include <Thor\Math.hpp>
#include <Thor\Particles.hpp>
#include <Thor\Resources.hpp>
#include <Thor\Shapes.hpp>
#include <Thor\Time.hpp>
#include <Thor\Vectors.hpp>

#include <yaml-cpp\yaml.h>


//Macro For Debug Messaging
#ifdef __MYDEBUG__
#define LOG(message) Logger::pInstance->Log(message, __LINE__, __FILE__, __FUNCTION__)
#define LOGWARNING(message) Logger::pInstance->LogWarning(message, __LINE__, __FILE__, __FUNCTION__)
#define LOGERROR(message) Logger::pInstance->LogError(message, __LINE__, __FILE__, __FUNCTION__)
#else
#define LOG(message)
#define LOGWARNING(message)
#define LOGERROR(message)
#endif