#!/usr/bin/env sh

CXX="g++"
COMP_MODE="debug"

DEBUG_FLAGS="-ggdb -g3"

OPTIMIZATION_LEVEL="-O3"
RELEASE_FLAGS="$OPTIMIZATION_LEVEL -s"

WARNINGS_FLAGS="-pedantic -Wall -Wextra -Werror -Wno-unused -Wformat=2 -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wcast-qual -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wswitch-enum -Wswitch-default -Wno-missing-braces -Wundef -Wctor-dtor-privacy"

CXX_STD="-std=c++20"
CXXFLAGS="$WARNINGS_FLAGS $CXX_STD"

if [ "$COMP_MODE" == "release" ]
then
    CXXFLAGS="$CXXFLAGS $RELEASE_FLAGS"
else
    CXXFLAGS="$CXXFLAGS $DEBUG_FLAGS"
fi

function test_solution() {
    cd "$1"
    $CXX $CXXFLAGS -o bin sol.cpp

    for input in testing/input*.txt; do
        diff -u <(./bin < "$input") "${input/input/expected}"
    done

    if [[ $? != 0 ]]
    then
        >&2 printf '\x1b[31mFAILURE:\x1b[0m '
        >&2 echo "$1"
    else
        >&2 printf '\x1b[32mSUCCESS:\x1b[0m '
        echo "$(basename "$1")"
    fi

    cd - > /dev/null
}

if [ $# -eq 0 ]
then
    for sol in solutions/*; do
        if [ -d "$sol" ]
        then
            test_solution "$sol"
        fi
    done
else
    test_solution "$1"
fi
