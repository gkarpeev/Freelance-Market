set(SOURCE_PROJECT
        src/DatabaseManager.cpp
        src/database/Data.cpp
        src/database/Table.cpp
        src/database/DataType.cpp
        src/database/Filter.cpp
        src/database/Database.cpp
        )

add_library(DatabaseManagerLib STATIC ${SOURCE_PROJECT})
target_link_libraries(DatabaseManagerLib PUBLIC         
        ${LIBMONGOCXX_LIBRARIES}
        ${LIBBSONCXX_LIBRARIES}
        )