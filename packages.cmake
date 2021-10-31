CPMAddPackage(
  NAME yaml-cpp
  GITHUB_REPOSITORY jbeder/yaml-cpp
  # 0.6.2 uses deprecated CMake syntax
  GIT_TAG yaml-cpp-0.7.0
  # 0.6.3 is not released yet, so use a recent commit
  OPTIONS
    "YAML_CPP_BUILD_TESTS Off"
    "YAML_CPP_BUILD_CONTRIB Off"
    "YAML_CPP_BUILD_TOOLS Off"
)
