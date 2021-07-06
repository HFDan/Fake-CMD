file(GLOB module_SRC CONFIGURE_DEPENDS "*.cpp" "*.h")

add_library(modules ${module_SRC})