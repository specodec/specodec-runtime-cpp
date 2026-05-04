cmake_minimum_required(VERSION 3.28)
project(specodec-cppm VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# libc++ paths from llvmPackages_21.libcxxClang
set(LIBCXX_INCLUDE /nix/store/n6gai5nijiyrb26s02cmbynrnghldm25-libcxx-21.1.7-dev/include/c++/v1)
set(LIBCXX_MODULE /nix/store/9mr4dc49h81pzk5z56sb0gcdxjddw0sm-libcxx-21.1.7/share/libc++/v1/std.cppm)

# Precompile std module
add_custom_command(
  OUTPUT ${CMAKE_BINARY_DIR}/std.pcm
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -nostdinc++ -I${LIBCXX_INCLUDE}
          --precompile -x c++-module ${LIBCXX_MODULE} -o ${CMAKE_BINARY_DIR}/std.pcm
  COMMENT "Precompiling std module"
)

# Common compile flags
set(CXXFLAGS -std=c++23 -nostdinc++ -I${LIBCXX_INCLUDE} -fmodule-file=std=${CMAKE_BINARY_DIR}/std.pcm)

# Helper macro: compile a .cppm to .pcm then .o
function(add_module MODULE_NAME SRC)
  set(PCM ${CMAKE_BINARY_DIR}/${MODULE_NAME}.pcm)
  set(OBJ ${CMAKE_BINARY_DIR}/${MODULE_NAME}.o)

  add_custom_command(
    OUTPUT ${PCM}
    COMMAND ${CMAKE_CXX_COMPILER} ${CXXFLAGS} --precompile -x c++-module
            ${CMAKE_CURRENT_SOURCE_DIR}/${SRC} -o ${PCM}
    DEPENDS ${SRC} ${CMAKE_BINARY_DIR}/std.pcm
    IMPLICIT_DEPENDS CXX ${CMAKE_CURRENT_SOURCE_DIR}/${SRC}
    COMMENT "Precompiling ${SRC}"
  )
  add_custom_command(
    OUTPUT ${OBJ}
    COMMAND ${CMAKE_CXX_COMPILER} ${CXXFLAGS} -c ${PCM} -o ${OBJ}
    DEPENDS ${PCM}
    COMMENT "Compiling ${SRC} -> ${MODULE_NAME}.o"
  )
  set(MODULE_OBJS ${MODULE_OBJS} ${OBJ} PARENT_SCOPE)
endfunction()

# All modules
set(MODULE_OBJS "")
add_module(specodec_scodec_error   src/specodec/scodec_error.cppm)
add_module(specodec_spec_reader    src/specodec/spec_reader.cppm)
add_module(specodec_spec_writer    src/specodec/spec_writer.cppm)
add_module(specodec_tables_f32     src/specodec/ryu/tables_f32.cppm)
add_module(specodec_tables_f64     src/specodec/ryu/tables_f64.cppm)
add_module(specodec_ryu_math       src/specodec/ryu/ryu_math.cppm)
add_module(specodec_ryu_f32        src/specodec/ryu/ryu_f32.cppm)
add_module(specodec_ryu_f64        src/specodec/ryu/ryu_f64.cppm)
add_module(specodec_float_fmt      src/specodec/float_fmt.cppm)
add_module(specodec_spec_codec     src/specodec/spec_codec.cppm)
add_module(specodec_json_reader    src/specodec/json_reader.cppm)
add_module(specodec_json_writer    src/specodec/json_writer.cppm)
add_module(specodec_gron_reader    src/specodec/gron_reader.cppm)
add_module(specodec_gron_writer    src/specodec/gron_writer.cppm)
add_module(specodec_msgpack_reader src/specodec/msgpack_reader.cppm)
add_module(specodec_msgpack_writer src/specodec/msgpack_writer.cppm)
add_module(specodec_main           src/specodec/specodec.cppm)

# Static library from all module objects
add_library(specodec STATIC ${MODULE_OBJS} ${CMAKE_BINARY_DIR}/std.pcm)
add_custom_target(specodec_lib ALL DEPENDS specodec)

# Ryu test
add_executable(test_ryu tests/ryu/test_ryu.cpp)
target_compile_options(test_ryu PRIVATE ${CXXFLAGS})
target_link_libraries(test_ryu specodec)
add_dependencies(test_ryu specodec)
