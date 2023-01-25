cmake_minimum_required(VERSION 3.14)

# задаем используемый стандарт С++
set(CMAKE_CXX_STANDARD 17)

# TODO: переименовать проект
project(Prisoner-sDilemma)

# задаем имя исполняемого файла основной программы
set(exe_name ${PROJECT_NAME})


# Включаем отслеживание всех предупреждений (warnings) и запрещаем компиляцию при наличии предупреждений.
# Считается хорошим тоном, когда программа собирается без предупрреждений.
# Но вы можете убрать /WX и -Werror (разрешив компиляцию с предупреждениями), если сможете разумно объяснить своё решение.
if (MSVC)
    # warning level 4 and all warnings as errors
	 # /WX
    add_compile_options(/W4)
else()
    # lots of warnings and all warnings as errors
	#-Werror
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# описываем основную библиотеку, т.е. библиотеку, содержащую все cpp-файлы, кроме main.cpp
# TODO: отредактировать список cpp-файлов
add_library(corelib OBJECT CheckMatrix.cpp Factory.cpp Game.cpp RoundResult.cpp Score.cpp Simulator.cpp Strategies.cpp)

# описываем исполняемый файл основной программы: это main.cpp + основная библиотека
add_executable(${exe_name} PrisonersDilemma.cpp)
target_link_libraries(${exe_name} corelib)
