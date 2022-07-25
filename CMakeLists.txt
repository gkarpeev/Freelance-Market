# set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
cmake_minimum_required(VERSION 3.0)

project(Project)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 14)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)

include_directories(
        database_manager/include     
        database_manager/include/database   
        freelance_market/include     
        freelance_market/include/states
        freelance_market/include/states/EntranceMenuHandlers
        freelance_market/include/states/MainMenuHandlers
        handler/include
        orders_manager/include
        rating_manager/include
        state/include
        users_manager/include
)

include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

add_subdirectory(handler)
add_subdirectory(freelance_market)
add_subdirectory(orders_manager)
add_subdirectory(rating_manager)
add_subdirectory(state)
add_subdirectory(users_manager)
add_subdirectory(database_manager)

set(SOURCE_PROJECT
        main.cpp
        )

add_executable(FreelanceMarket ${SOURCE_PROJECT})

target_link_libraries(FreelanceMarket PUBLIC
        FrilanceMarketLib
        HandlerLib
        OrdersManagerLib
        RatingManagerLib
        UsersManagerLib
        StateLib
        DatabaseManagerLib
        )