/*************************************************************************
Copyright 2019 James Durban

The file 'order.h' is apart of the 'clib-linear-algebra' library, 
and contains an enum 'MatrixOrder' used by other matrix files, in
determining the ordering of a matrix (row/column).

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

#ifndef _ORDER_H
#define _ORDER_H

typedef enum MatrixOrder { ROW_MAJOR, COLUMN_MAJOR } MatrixOrder;

#endif