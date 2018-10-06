cmake_minimum_required(VERSION 3.12)
project(utn_tp2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(utn_tp2
        functionsForProjects.c
        functionsForProjects.h
        main.c
        tp2Utn.cbp
        tp2Utn.depend
        tp2Utn.layout)
