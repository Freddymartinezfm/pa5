#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <iostream>
#include <iomanip>

enum Error_code  {found, success, fail, duplicate, full, not_present, probe_max};
enum State  {visited, unvisited, finished};
class utility {
public:
	static void m(const std::string = " ", const char * = " ", const void * = nullptr);	
	static void m(const char *, const int );
	
	

};
#endif


// TAG = static const class name 
// mTAG = const method name start
// message = mem address or special message 


