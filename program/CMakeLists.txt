cmake_minimum_required(VERSION 3.4)

project(Program)

#ustaw we wĹasnej zmiennej SOURCE_FILES zbiĂłr plikĂłw ĹşrĂłdĹowych projektu
set(SOURCE_FILES
        src/main.cpp
        )
#wĹÄcz powyĹźszy zbiĂłr plikĂłw do zbudowania programu wykonywalnego Program
add_executable(Program ${SOURCE_FILES})

#OkreĹlenie zaleĹźnoĹci pomiÄdzy projektami Program i Biblioteka
target_link_libraries(Program Library)

enable_testing()