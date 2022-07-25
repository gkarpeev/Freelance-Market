set(SOURCE_PROJECT
        src/LogLevel.cpp
        src/Handler.cpp
        src/Request.cpp
        src/BaseHandler.cpp
        )

add_library(HandlerLib STATIC ${SOURCE_PROJECT})
# target_link_libraries(HandlerLib PUBLIC 
#         DatabaseManagerLib
#         UsersManagerLib
#         )
