# PCGGram Demo/Example Program



# Dependencies
# -



# Sources and Building

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
)

file(GLOB DemoSOURCEFILES
    "${PROJECT_SOURCE_DIR}/source_demo/*.cpp"
)

add_executable(PCGGram_Demo ${DemoSOURCEFILES})
target_link_libraries(PCGGram_Demo PCGGram)



# Installation
install(TARGETS PCGGram_Demo DESTINATION bin)

