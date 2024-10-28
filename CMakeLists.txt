cmake_minimum_required(VERSION 3.10)

# Название проекта
project(NavierStokes)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем директорию include для заголовочных файлов
include_directories(include)

# Указываем все исходные файлы
set(SOURCES
    src/main.cpp
    src/BasicSolver.cpp
    src/ConsoleLogger.cpp
    src/SolverFactory.cpp
    src/VelocityPressureSolver.cpp
    src/VorticityStreamFunctionSolver.cpp
)

# Указываем заголовочные файлы (необязательно, но полезно для IDE)
set(HEADERS
    include/BasicSolver.hpp
    include/ConsoleLogger.hpp
    include/ILogger.hpp
    include/SolverFactory.hpp
    include/VelocityPressureSolver.hpp
    include/VorticityStreamFunctionSolver.hpp
)

# Создаем исполняемый файл, добавляя только SOURCES (HEADERS можно не добавлять)
add_executable(NavierStokes ${SOURCES})

# Опционально: добавляем флаги компиляции, если нужны
# target_compile_options(NavierStokes PRIVATE -Wall -Wextra -O2)