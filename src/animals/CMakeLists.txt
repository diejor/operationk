add_library(animals
    animal.cpp
    cat.cpp
    dog.cpp
)

target_link_libraries(animals
    PRIVATE 
        utils
)

target_include_directories(animals
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
