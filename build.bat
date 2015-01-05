set CC=g++
set CC_FLAGS=-std=c++0x -Wall -O0 -Iphs/win32

set SOURCE_FILES=phs/*.cc phs/win32/*.cc

set TARGET=bin/phs-cxx

%CC% %CC_FLAGS% %SOURCE_FILES% -o %TARGET%
