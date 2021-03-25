/*************************************************************************
Copyright 2019 James Durban

The file 'lalgebra_errors.c' is apart of the 'linear-algebra_library' library, 
and contains debugging function definitions for use internally, when 
outputting information.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

The GitHub repository for this library can be found here:
https://github.com/James-Durban/linear-algebra_library
*************************************************************************/



#include "lalgebra_errors.h"

#include <stdio.h>
#include <stdlib.h>

void assert(int expr, const char* message, unsigned int line, const char* file)
{
    if(expr == 1)
    {
        fprintf(stderr,"[ERROR]: %s || [LINE: %d] [FILE: %s]\n",message,line,file);
        exit(EXIT_FAILURE);
    }
}
