#ifndef _DL_LOGGING_H
#define _DL_LOGGING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void internal_log(unsigned int line, const char* file,
				  const char* message, const char* logLevel);
void internal_assert(unsigned int line, const char* file,
					 const char* message, const char* logLevel, bool condition);
void internal_equal(unsigned int line, const char* file,
					const char* message, const char* logLevel, bool condition);

#define LOG_VERBOSE(message) internal_log_verbose(__LINE__,__FILE__,message,"[VERBOSE]: ");
#define LOG_WARN(message) internal_log_warn(__LINE__,__FILE__,message,"[WARNING]: ");
#define LOG_ERROR(message) internal_log_error(__LINE__,__FILE__,message,"[ERROR]: ");

#define ASSERT_VERBOSE(message,condition) internal_assert_verbose(__LINE__,__FILE__,message,"[VERBOSE]: ",condition);
#define ASSERT_WARN(message,condition) internal_assert_warn(__LINE__,__FILE__,message,"[WARNING]: ",condition);
#define ASSERT_ERROR(message,condition) internal_assert_error(__LINE__,__FILE__,message,"[ERROR]: ",condition);

#define EQUAL_VERBOSE(message,condition) internal_equal_verbose(__LINE__,__FILE__,message,"[VERBOSE]: ",condition);
#define EQUAL_WARN(message,condition) internal_equal_warn(__LINE__,__FILE__,message,"[WARNING]: ",condition);
#define EQUAL_ERROR(message,condition) internal_equal_error(__LINE__,__FILE__,message,"[ERROR]: ",condition);

#endif
