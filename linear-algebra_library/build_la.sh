#!/usr/bin/bash

gcc_flags="-g3 -Wall -Werror -Wextra -pedantic"
include_flags="-Isrc/"
compile_flags="src/internal/*.c test/*.c"

curDir=$(pwd)

linux_include_dir="/usr/include/clib/math/"
source_files="${curDir}/src/internal/*.c"

#colours

black="\e[0m"
red="\e[1;31m"
green="\e[1;32m"
yellow="\e[1;33m"

enable_verbose=0


print_trace()
{
    if [ "$enable_verbose" -eq 1 ]; then
      echo "$green[TRACE]:$black $1"
    fi
}

print_info()
{
    echo "$yellow[INFO]: $black $1"
}

print_error()
{
    echo "$red[ERROR]:$black $1"
}

check_dependencies()
{
  if [ ! -d "$curDir/src" ]; then
    print_error "Source folder not found!"
    exit 1
  fi

  if [ -d "test/" ]; then

    test_files="${curDir}/test/*.c"
  fi

  command -v gcc >/dev/null 2>&1 ||
  { 
    print_error "The GCC Compiler is required."
    print_info "It can be installed with 'sudo apt-get install gcc'."
    exit 1; 
  }
}

check_bin_directories()
{
    if [ ! -d "$curDir/bin" ] && [ ! -L "$curDir/bin" ] ; then
      print_trace "Creating directory $curDir/bin"
      mkdir bin
    fi
    if [ ! -d "$curDir/bin/obj" ]; then
      print_trace "Creating directory $curDir/bin/obj"
      mkdir bin/obj
    fi
    if [ ! -d "$curDir/bin/shared" ]; then 
      print_trace "Creating directory $curDir/bin/shared"
      mkdir bin/shared
    fi
    if [ ! -d "$curDir/bin/static" ]; then 
      print_trace "Creating directory $curDir/bin/static"
      mkdir bin/static
    fi
}

check_link_directories()
{ 
    if [ ! -d $linux_include_dir ]; then 
      print_trace "Creating directory /usr/include/clib"
      sudo mkdir /usr/include/clib
      if [ ! -d "$linux_include_dir/math" ]; then
        print_trace "Creating directory /usr/include/clib/math"
        sudo mkdir /usr/include/clib/math/
        print_trace "Creating directory /usr/include/clib/math/internal"
        sudo mkdir /usr/include/clib/math/internal/
      fi
    fi
}

compile_files()
{
    for f in $1
    do
        print_trace "Compiling source file $f"
        gcc -c $2 $gcc_flags $include_flags $f
    done
}

copy_files()
{
    for f in $1
    do
        print_trace "Copying source file from $f to $2"
        sudo cp $f $2
    done
}

check_dependencies

print_info "Script has started. $date"
for var in "$@"
do 
  case "$var" in
      "-verbose")
        enable_verbose=1
        ;;
     "-c")
        rm -rf bin
        check_bin_directories 
        compile_files "$source_files"
        compile_files "$test_files"
        mv *.o bin/obj
        print_info "Completed compiling source code."
        ;;
      "-l")
        print_info "Linking object files."
        gcc -o bin/run.out bin/obj/*.o -lm
        print_trace "Creating static library file in $curDir/bin/static"
        ar rcs bin/static/libclalgebra.a bin/obj/*.o

        rm -rf bin/obj/*
        compile_files "$source_files" "-fPIC"
        compile_files "$test_files" "-fPIC"
        mv *.o bin/obj

        print_trace "Creating shared library file in $curDir/bin/shared"
        gcc -fPIC -shared bin/obj/*.o -o bin/shared/libclalgebra.so 
        ;;
      "-i")
        check_link_directories
        print_info "Placing files in include folder."
        copy_files "src/internal/*" "/usr/include/clib/math/internal/"
        copy_files "src/*.h" "/usr/include/clib/math/"
        copy_files "bin/shared/*" "/usr/lib/"
        ;;
      "-purge")
        print_trace "Removing file /usr/lib/libcalgebra.so"
        sudo rm -rf /usr/lib/libcalgebra.so 
        print_trace "Removing folder /usr/include/clib"
        sudo rm -rf /usr/include/clib
        print_trace "Removing folder $curDir/bin"
        sudo rm -rf $curDir/bin
        print_info "Removal complete."
        ;;
      "-help")
        echo "-c        | Compile source code."
        echo "-l        | Link source code to executable."
        echo "-i        | Copy files to system include folders - library becomes accessible system wide."
        echo "-verbose  | Enables verbose logging for the script." 
        echo "-purge    | Removes all traces of this library from the system - apart from src folder + script. "
        echo "-help     | Display a list of commands available for this script."
        ;;
      *)
      ;;
  esac
done
print_info "Script has finished."