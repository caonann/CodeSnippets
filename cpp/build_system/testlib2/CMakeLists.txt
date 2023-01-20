add_library(testlib2 STATIC)
target_sources(testlib2 PRIVATE testlib2.cpp)
target_include_directories(testlib2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
if (WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "")
endif ()
FetchContent_MakeAvailable(googletest)
target_link_libraries(testlib2 PRIVATE GTest::gtest)


FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2)
FetchContent_MakeAvailable(json)

target_link_libraries(testlib2 PRIVATE nlohmann_json::nlohmann_json)

include(ExternalProject)

set(ROOT          ${CMAKE_BINARY_DIR}/thirdparty/ffmpeg)
set(LIB_DIR       ${ROOT}/lib)
set(INCLUDE_DIR   ${ROOT}/include)

set(URL           https://github.com/FFmpeg/FFmpeg/archive/refs/heads/release/4.4.zip)
set(CONFIGURE     cd ${ROOT}/src/ffmpeg-4.4 && ./configure  --enable-pic --disable-debug  --disable-decoders --disable-encoders --disable-parsers --disable-demuxers --disable-muxers --disable-filters --disable-htmlpages --disable-manpages --disable-podpages --disable-txtpages --disable-programs  --enable-doc --disable-bzlib --disable-error-resilience --disable-iconv --disable-lzo --disable-network --disable-schannel --disable-sdl2 --disable-symver --disable-xlib --disable-zlib --disable-securetransport --disable-faan --disable-alsa --disable-autodetect --enable-demuxer=flv --enable-demuxer=h264 --enable-demuxer=aac --enable-muxer=flv --enable-muxer=h264 --enable-muxer=opus --enable-parser=aac --enable-parser=opus  --enable-parser=h264 --enable-parser=vp8 --enable-decoder=h264 --enable-decoder=aac --enable-encoder=opus --enable-decoder=opus --prefix=${ROOT})
set(MAKE          cd ${ROOT}/src/ffmpeg-4.4 && make -j16)
set(INSTALL       cd ${ROOT}/src/ffmpeg-4.4 && make install)

add_dependencies(testlib2 ffmpeg-4.4)
ExternalProject_Add(ffmpeg-4.4
        URL                   ${URL}
        DOWNLOAD_NAME         4.4.zip
        PREFIX                ${ROOT}
        CONFIGURE_COMMAND     ${CONFIGURE}
        BUILD_COMMAND         ${MAKE}
        INSTALL_COMMAND       ${INSTALL}
        )

target_include_directories(testlib2 PUBLIC ${INCLUDE_DIR})
target_link_directories(testlib2 PUBLIC ${LIB_DIR})
target_link_libraries(testlib2 PUBLIC avdevice avfilter avformat avcodec avutil swresample pthread dl)