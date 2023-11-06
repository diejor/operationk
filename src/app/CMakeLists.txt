add_executable(app main.cpp)

# include directories here
target_link_libraries(app PRIVATE
    utils
)

install(TARGETS app)
