set( CMAKE_C_FLAGS "-Wall -g" )

file( GLOB SRCS *.cpp *.h )

add_executable( OUTFILE ${SRCS} scheduler.h shortestjobfirst.h shortestjobfirst.cpp)

set_target_properties( OUTFILE PROPERTIES LINKER_LANGUAGE CXX )