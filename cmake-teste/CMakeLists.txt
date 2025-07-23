cmake_minimum_required(VERSION 3.5) #Versão mínima necessária do CMake
project(HelloWorldC) # Nomeia o projeto

set(CMAKE_C_STANDARD 11) # Define o padrão C do projeto

list(APPEND CMAKE_PREFIX_PATH "C:/msys64/mingw64") # Busca o caminho onde bibliotecas externas estão instaladas

find_package(SDL3 REQUIRED) # Busca a biblioteca (REQUIRED indica obrigatoriedade)
if (NOT SDL3_FOUND)
    message(FATAL_ERROR "Erro: SDL3 não foi encontrado. Verifique sua instalação do MSYS2/MinGW e se o CMAKE_PREFIX_PATH está correto.")
endif()

find_package(SDL3_ttf)
if (SDL3_TTF_FOUND)
    # Se encontrou, imprime o status e as variáveis que o find_package preencheu
    message(STATUS "SDL3_ttf encontrado com sucesso!")
    message(STATUS "  Headers (INCLUDE_DIRS): ${SDL3_TTF_INCLUDE_DIRS}")
    message(STATUS "  Libraries (LIBRARIES): ${SDL3_TTF_LIBRARIES}")
    message(STATUS "  Version: ${SDL3_TTF_VERSION}")
else()
    # Se não encontrou, imprime uma mensagem de erro
    message(STATUS "SDL3_ttf NÃO ENCONTRADO.")
    message(STATUS "  Verifique se está instalado via pacman: pacman -S mingw-w64-x86_64-sdl3-ttf")
    message(STATUS "  Verifique se CMAKE_PREFIX_PATH está correto e se você está no terminal MSYS2 MinGW 64-bit.")
endif()

add_executable(HelloWorld source/main.c) # Cria o executável

set_target_properties(HelloWorld PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
) # Define onde será criado o executável 

target_link_libraries(HelloWorld PUBLIC
    ${SDL3_LIBRARIES}
) # Busca as bibliotecas desejadas

target_include_directories(HelloWorld PUBLIC
    ${SDL3_INCLUDE_DIRS}
) # Define os arquivos para incluir


target_link_libraries(HelloWorld PRIVATE SDL3_ttf::SDL3_ttf)

add_custom_command(TARGET HelloWorld POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            C:/msys64/mingw64/bin/SDL3.dll
            $<TARGET_FILE_DIR:HelloWorld>
) # Copia a dll dos arquivos desejados