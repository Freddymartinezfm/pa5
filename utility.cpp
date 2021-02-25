#include "utility.h"
#include <string>
#include <iomanip>

void utility::m(const std::string TAG, const char * mTAG, const void * message){
	std::cout << std::left << std::setw(15) <<  TAG 
	<< ": " << std::setw(20)  << mTAG 
	<<  std::setw(15)  << std::right <<  message  << std::endl;
}

void utility::m(const char * what, const int key = -1){
	std::cout << std::left << std::setw(15) <<  " " 
	<< ": " << std::setw(20)  << key
	<<  std::setw(15)  << std::right <<  key  << std::endl;

}

static void m(const std::string& message){
	std::cout << std::left << std::setw(15) <<  " " 
	<< ": " << std::setw(20)  << message
	<<  std::setw(15)  << std::right << " "   << std::endl;

}






