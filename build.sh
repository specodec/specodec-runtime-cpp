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

BUILD_ORDER=(
    "ryu/ryu_math.cppm"
    "ryu/tables_f32.cppm"
    "ryu/tables_f64.cppm"
    "ryu/ryu_f32.cppm"
    "ryu/ryu_f64.cppm"
    "scodec_error.cppm"
    "spec_reader.cppm"
    "spec_writer.cppm"
    "float_fmt.cppm"
    "json_reader.cppm"
    "json_writer.cppm"
    "msgpack_reader.cppm"
    "msgpack_writer.cppm"
    "gron_reader.cppm"
    "gron_writer.cppm"
    "spec_codec.cppm"
    "spec_undefined.cppm"
    "specodec.cppm"
)

pcm_of() {
    local mod="$1"
    case "$mod" in
        std) echo "$BUILD/std.pcm" ;;
        specodec.ryu.math) echo "$BUILD/ryu_ryu_math.cppm.pcm" ;;
        specodec.ryu.tables_f32) echo "$BUILD/ryu_tables_f32.cppm.pcm" ;;
        specodec.ryu.tables_f64) echo "$BUILD/ryu_tables_f64.cppm.pcm" ;;
        specodec.ryu.f32) echo "$BUILD/ryu_ryu_f32.cppm.pcm" ;;
        specodec.ryu.f64) echo "$BUILD/ryu_ryu_f64.cppm.pcm" ;;
        specodec.scodec_error) echo "$BUILD/scodec_error.cppm.pcm" ;;
        specodec.spec_reader) echo "$BUILD/spec_reader.cppm.pcm" ;;
        specodec.spec_writer) echo "$BUILD/spec_writer.cppm.pcm" ;;
        specodec.float_fmt) echo "$BUILD/float_fmt.cppm.pcm" ;;
        specodec.json_reader) echo "$BUILD/json_reader.cppm.pcm" ;;
        specodec.json_writer) echo "$BUILD/json_writer.cppm.pcm" ;;
        specodec.msgpack_reader) echo "$BUILD/msgpack_reader.cppm.pcm" ;;
        specodec.msgpack_writer) echo "$BUILD/msgpack_writer.cppm.pcm" ;;
        specodec.gron_reader) echo "$BUILD/gron_reader.cppm.pcm" ;;
        specodec.gron_writer) echo "$BUILD/gron_writer.cppm.pcm" ;;
        specodec.spec_codec) echo "$BUILD/spec_codec.cppm.pcm" ;;
        specodec.spec_undefined) echo "$BUILD/spec_undefined.cppm.pcm" ;;
        specodec.specodec) echo "$BUILD/specodec.cppm.pcm" ;;
    esac
}

module_flags_for() {
    local mod
    for mod in "$@"; do
        printf -- "-fmodule-file=%s=%s " "$mod" "$(pcm_of "$mod")"
    done
}

ALL_RYU="specodec.ryu.math specodec.ryu.tables_f32 specodec.ryu.tables_f64 specodec.ryu.f32 specodec.ryu.f64"
ALL_READERS_WRITERS="specodec.json_reader specodec.json_writer specodec.msgpack_reader specodec.msgpack_writer specodec.gron_reader specodec.gron_writer"

echo "=== Building $SRC ==="
echo "  libc++ include: $LIBCXX_INCLUDE"
echo "  libc++ lib:     $LIBCXX_LIB"
OBJECTS=""

for rel in "${BUILD_ORDER[@]}"; do
    src="$SRC/$rel"
    obj="$BUILD/${rel//\//_}.o"
    pcm="$BUILD/${rel//\//_}.pcm"
    echo "  $rel"
    MF=""
    case "$rel" in
        ryu/ryu_math.cppm) ;;
        ryu/tables_f32.cppm) ;;
        ryu/tables_f64.cppm) ;;
        ryu/ryu_f32.cppm) MF="$(module_flags_for specodec.ryu.math specodec.ryu.tables_f32)" ;;
        ryu/ryu_f64.cppm) MF="$(module_flags_for specodec.ryu.math specodec.ryu.tables_f64)" ;;
        scodec_error.cppm) ;;
        spec_reader.cppm) ;;
        spec_writer.cppm) ;;
        float_fmt.cppm) MF="$(module_flags_for $ALL_RYU)" ;;
        json_reader.cppm) MF="$(module_flags_for specodec.scodec_error specodec.spec_reader)" ;;
        json_writer.cppm) MF="$(module_flags_for specodec.spec_writer specodec.float_fmt $ALL_RYU)" ;;
        msgpack_reader.cppm) MF="$(module_flags_for specodec.scodec_error specodec.spec_reader)" ;;
        msgpack_writer.cppm) MF="$(module_flags_for specodec.spec_writer)" ;;
        gron_reader.cppm) MF="$(module_flags_for specodec.scodec_error specodec.spec_reader)" ;;
        gron_writer.cppm) MF="$(module_flags_for specodec.spec_writer specodec.float_fmt $ALL_RYU)" ;;
        spec_codec.cppm) MF="$(module_flags_for specodec.spec_reader specodec.spec_writer $ALL_READERS_WRITERS specodec.scodec_error specodec.float_fmt $ALL_RYU)" ;;
        spec_undefined.cppm) ;;
        specodec.cppm) MF="$(module_flags_for specodec.spec_codec specodec.spec_undefined specodec.spec_reader specodec.spec_writer $ALL_READERS_WRITERS specodec.scodec_error specodec.float_fmt $ALL_RYU)" ;;
    esac
    $CXX $CXXFLAGS $STD_FLAG $MF --precompile "$src" -o "$pcm"
    $CXX $CXXFLAGS $STD_FLAG $MF -c "$src" -o "$obj"
    OBJECTS="$OBJECTS $obj"
done

echo "=== Archive: $BUILD/libspecodec.a ==="
ar rcs $BUILD/libspecodec.a $OBJECTS
echo "=== Done ==="
