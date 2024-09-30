cmake_minimum_required(VERSION 3.29)
project(OtherCmakeProjectVCPKG)

set(CMAKE_CXX_STANDARD 14)

# Find sqlite_orm
find_package(SqliteOrm CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

add_executable(OtherCmakeProjectVCPKG main.cpp
)

target_link_libraries(OtherCmakeProjectVCPKG PRIVATE sqlite_orm::sqlite_orm)
target_link_libraries(OtherCmakeProjectVCPKG PRIVATE unofficial::sqlite3::sqlite3)

# Link sqlite_orm to your target
