set( CMAKE_C_FLAGS "-Wall -g" )

file( GLOB SRCS *.cpp *.h )

add_executable( OUTFILE ${SRCS} scheduler.h sjfscheduler.h sjfscheduler.cpp priorityscheduler.h priorityscheduler.cpp ganttchart.h ganttchart.cpp srtfscheduler.h srtfscheduler.cpp)

set_target_properties( OUTFILE PROPERTIES LINKER_LANGUAGE CXX )