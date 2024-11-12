cmake_minimum_required(VERSION 3.10)

# Название проекта
project(NavierStokes)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(BOOST_DI_PATH ${CMAKE_SOURCE_DIR}/di/include) # Путь к заголовочным файлам Boost.DI

# Добавляем директорию include для заголовочных файлов
include_directories(include ${BOOST_DI_PATH})

# Указываем все исходные файлы
set(SOURCES
    src/main.cpp
    src/BasicSolver.cpp
    src/ConsoleLogger.cpp
    src/SolverFactory.cpp
    src/VelocityPressureSolver.cpp
    src/VelocityPressureSolverOMP.cpp
    src/VorticityStreamFunctionSolver.cpp
    src/VorticityStreamFunctionSolverOMP.cpp
)

# Указываем заголовочные файлы (необязательно, но полезно для IDE)
set(HEADERS
    include/BasicSolver.hpp
    include/ConsoleLogger.hpp
    include/ILogger.hpp
    include/SolverFactory.hpp
    include/VelocityPressureSolver.hpp
    include/VelocityPressureSolverOMP.hpp
    include/VorticityStreamFunctionSolver.hpp
    include/VorticityStreamFunctionSolverOMP.hpp
)

# Создаем исполняемый файл, добавляя только SOURCES (HEADERS можно не добавлять)
add_executable(NavierStokes ${SOURCES})

# Проверяем наличие OpenMP
find_package(OpenMP)

if(OpenMP_CXX_FOUND)
    # Добавляем флаги компиляции и связывания для OpenMP
    target_link_libraries(NavierStokes PUBLIC OpenMP::OpenMP_CXX)
endif()

# Опционально: добавляем флаги компиляции, если нужны
target_compile_options(NavierStokes PRIVATE -Wall -Wextra -O2)