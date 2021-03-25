#include "dl_logging.h"

void internal_log(unsigned int line, const char* file, const char* message, const char* logLevel)
{
    printf("%s %s | FILE: %s | LINE %d\n",logLevel,message,file,line);
}
void internal_assert(unsigned int line, const char* file, const char* message, const char* logLevel, bool condition)
{
    if(condition) 
    { 
        internal_log(line,file,message,logLevel); 
        exit(EXIT_FAILURE);
    }
}

void internal_equal(unsigned int line, const char* file, const char* message, const char* logLevel, bool condition)
{
    if(condition) { internal_log(line,file,message,logLevel); }
}

