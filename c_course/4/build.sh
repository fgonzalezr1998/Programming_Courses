#! /bin/sh

# If "build" folder exists, remove it:

if [ -d "build" ]
then

    rm -rf build

fi

# If "double_linked_list" file exists, remove it:

if [ -f "double_linked_list" ]
then
    rm double_linked_list
fi

# Create empty "build" folder, move to it and compile with only one thread:

mkdir build && cd build
cmake ..
make -j1

# If everything was OK, copy the generated executable file to the root folder
# and print a succesfully trace:

if [ $? -eq 0 ]
then

    cp double_linked_list ..

    echo '\n[INFO] Job exited cleanly\n'
fi