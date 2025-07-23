cmake_minimum_required(VERSION 3.5) #Versão mínima necessária do CMake
project(HelloWorldC) # Nomeia o projeto

set(CMAKE_C_STANDARD 11) # Define o padrão C do projeto

# FORÇA O CAMINHO PARA OS HEADERS DO SDL3_ttf
set(SDL3_TTF_INCLUDE_DIR "C:/msys64/mingw64/include/SDL3_ttf")
# FORÇA O CAMINHO PARA A BIBLIOTECA SDL3_ttf
set(SDL3_TTF_LIBRARY "C:/msys64/mingw64/lib/libSDL3_ttf.dll.a")

list(APPEND CMAKE_PREFIX_PATH "C:/msys64/mingw64") # Busca o caminho onde bibliotecas externas estão instaladas

find_package(SDL3 REQUIRED) # Busca a biblioteca (REQUIRED indica obrigatoriedade)
if (NOT SDL3_FOUND)
    message(FATAL_ERROR "Erro: SDL3 não foi encontrado. Verifique sua instalação do MSYS2/MinGW e se o CMAKE_PREFIX_PATH está correto.")
endif()

find_package(SDL3_ttf REQUIRED)
if (NOT SDL3_ttf_FOUND)
    message(FATAL_ERROR "Erro: SDL3_ttf não encontrado! Verifique sua instalação do MSYS2/MinGW.")
endif()


add_executable(HelloWorld source/main.c) # Cria o executável

set_target_properties(HelloWorld PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
) # Define onde será criado o executável

target_link_libraries(HelloWorld PUBLIC
    ${SDL3_LIBRARIES}
    ${SDL3_TTF_LIBRARIES}
) # Busca as bibliotecas desejadas
message(STATUS "SDL3_ttf encontrado: ${SDL3_TTF_LIBRARIES}")

target_include_directories(HelloWorld PUBLIC
    ${SDL3_INCLUDE_DIRS}
    ${SDL3_TTF_INCLUDE_DIRS}
) # Define os arquivos para incluir

add_custom_command(TARGET HelloWorld POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            C:/msys64/mingw64/bin/SDL3.dll
            $<TARGET_FILE_DIR:HelloWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            C:/msys64/mingw64/bin/SDL3_ttf.dll
            $<TARGET_FILE_DIR:HelloWorld>
) # Copia a dll dos arquivos desejados