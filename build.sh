#!/bin/bash
set -e
eval "$(/root/.local/bin/mise activate bash)"

CXX="clang --driver-mode=g++"
LIBCXX_INCLUDE="$(ls -d /root/.local/share/mise/installs/conda-libcxx-devel/*/include/c++/v1 | sort -V | tail -1)"
LIBCXX_LIB="$(ls -d /root/.local/share/mise/installs/conda-libcxx/*/lib | sort -V | tail -1)"
STD_CPPM="$(ls /root/.local/share/mise/installs/conda-libcxx-devel/*/share/libc++/v1/std.cppm | sort -V | tail -1)"
CXXFLAGS="-std=c++23 -stdlib=libc++ -nostdinc++ -I${LIBCXX_INCLUDE} -L${LIBCXX_LIB}"
SRC=src/specodec
BUILD=build

mkdir -p $BUILD

echo "=== Precompile std module ==="
$CXX $CXXFLAGS --precompile -x c++-module "$STD_CPPM" -o $BUILD/std.pcm
STD_FLAG="-fmodule-file=std=$BUILD/std.pcm"

echo "=== Building $SRC ==="
echo "  libc++ include: $LIBCXX_INCLUDE"
echo "  libc++ lib:     $LIBCXX_LIB"
ALL_SRC=$(find $SRC -name '*.cpp' -o -name '*.cppm' | sort)
OBJECTS=""

for src in $ALL_SRC; do
  rel=${src#$SRC/}
  obj="$BUILD/${rel//\//_}.o"
  echo "  $rel"
  $CXX $CXXFLAGS $STD_FLAG -c "$src" -o "$obj"
  OBJECTS="$OBJECTS $obj"
done

echo "=== Archive: $BUILD/libspecodec.a ==="
ar rcs $BUILD/libspecodec.a $OBJECTS
echo "=== Done ==="
