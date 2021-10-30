file(GLOB module_SRC CONFIGURE_DEPENDS "*.cpp" "*.h")

add_library(libmodules STATIC ${module_SRC})