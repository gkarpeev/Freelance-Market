set(SOURCE_PROJECT
        src/User.cpp
        src/UserInteraction.cpp
        src/UserManager.cpp
        )

add_library(UsersManagerLib STATIC ${SOURCE_PROJECT})
