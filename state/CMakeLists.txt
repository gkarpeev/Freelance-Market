set(SOURCE_PROJECT
        src/State.cpp
        )

add_library(StateLib STATIC ${SOURCE_PROJECT})
# target_link_libraries(StateLib PUBLIC
#         HandlerLib
#         )
