gcc_flags="-g3 -Wall -Werror -Wextra -pedantic"


gcc $gcc_flags -I src/ src/math/*.c test/*.c -o bin/run.out -lm