gcc_flags="-g3 -Wall -Werror -Wextra -pedantic"
include_flags="-Isrc/"
compile_flags=" src/internal/*.c src/*.c test/test.c"

binDir="bin"
sharedDir="bin/shared"
staticDir="bin/static"

echo "Compiling files...."

rm -rf bin/*
mkdir bin/obj
gcc $gcc_flags -c $include_flags $compile_flags
mv *.o bin/obj
gcc -o bin/run.out bin/obj/*.o 

echo "Complete."