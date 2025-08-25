cmake_minimum_required(VERSION 3.19)

project(cosim LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Drogon CONFIG REQUIRED)          # 提供 Drogon::Drogon
find_package(nlohmann_json CONFIG REQUIRED)   # 提供 nlohmann_json::nlohmann_json
# find_package(fmilib CONFIG REQUIRED)          # 提供 fmilib::fmilib
file(GLOB SRC CONFIGURE_DEPENDS
  src/*.cpp src/*.cc
  src/controllers/*.cc
  src/filters/*.cc
  src/plugins/*.cc
  src/models/*.cc
  src/views/*.cc
)

# add_executable(cosim ${SRC})
add_executable(cosim src/main.cpp)
# Debug 用 dev 配置，其它用正式配置（按需改）

target_compile_definitions(cosim PRIVATE
  COSIM_CONFIG_FILE_DEBUG="${CMAKE_SOURCE_DIR}/config/config.json"
  COSIM_CONFIG_FILE_RELEASE="${CMAKE_SOURCE_DIR}/config/config.json"
)
target_link_libraries(cosim
  PRIVATE Drogon::Drogon nlohmann_json::nlohmann_json)
