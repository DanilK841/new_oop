cmake_minimum_required(VERSION 3.30.4)        # требуемая версия cmake
project(    
    OOP_project                                # название проекта                        
    VERSION 1                          # номер версии проекта
    DESCRIPTION "First project"             # описание           
    LANGUAGES CXX                           # язык программирования
)   
set(CMAKE_CXX_STANDARD 17)                  # устанавливаем требуемый стандарт языка (это значит, что в проекте буду использоваться фичи этоо стандарта)
set(CMAKE_CXX_STANDARD_REQUIRED ON)         # при сборке платформа будет проверять поддержку стандарта C++17 компилятором

set(CMAKE_BUILD_TYPE Debug)                 # конфигурация сборки - Debug

add_executable(OOP_project)                     # эта команда сообщает платформе сборке, что код будет компилироваться в исполняемый файл с названием lesson3.exe
# add_library(lesson3)                        # эта команда сообщает платформе сборке, что код будет компилироваться в статическую библиотеку с названием lesson3.lib
# add_library(lesson3 SHARED)                 # эта команда сообщает платформе сборке, что код будет компилироваться в динамическую библиотеку с названием lesson3.dll


set(sources                                 # создаем cmake-переменную sources, которая содержит список файлов исходного когда (в данном случае main.cpp)
    source/main.cpp
)

target_sources(OOP_project PRIVATE ${sources})  # команда указывает компилятору, что исполняемый файл будет компилироваться из исходников, перечисленных в sources