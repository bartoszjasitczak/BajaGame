#Minimalna wersja cmake konieczna do zbudowania tego projektu
cmake_minimum_required(VERSION 3.4)


#Parametry konfiguracyjne platformy programistycznej i flagi kompilatora
set(CMAKE_CXX_COMPILER g++)#g++ jako kompilator C++
set(CMAKE_C_COMPILER gcc)#gcc jako kompilator C
set(CMAKE_CXX_STANDARD 11)#Standard C++ 11, bez tego parametru g++ uĹźyje wartoĹci domyĹlnej. Dla g++ od wersji 6 jest to C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)#OkreĹlony wyĹźej standard C++ jest wymagany
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra")

#Profil debug i maksymalny poziom debug info g3 oraz format debug info na dwarf-4 (musi byÄ gdb w wersji 7). BUILD_TYPE moĹźe byÄ ustawiony na:
#empty,
#Debug,
#Release,
#RelWithDebInfo
#MinSizeRel
#Ustawiono dodatkowo flagi debug generujÄce informacjÄ dla debuggera
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4")

project(GameBaja)
enable_language(CXX)

#W specjalnym pliku compile_commands.json moĹźna podejrzeÄ wszystkie operacje kompilatora wraz z parametrami,
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#uwzglÄdnij podprojek znajdujÄcy siÄ w podkatalogu library. Musi byÄ w nim pliki CMakeLists.txt
add_subdirectory(library)
add_subdirectory(program)

#WĹÄczenie testĂłw powoduje pojawienie siÄ celu test w makefiles
enable_testing()