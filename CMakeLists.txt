cmake_minimum_required(VERSION 2.8.3)
add_compile_options(-std=c++11)

set(PYTHON_ROOT /data/home/rexyuan/miniconda3/envs/py27)

set(PYTHON_LIBRARY ${PYTHON_ROOT}/lib/python2.7)
set(PYTHON_INCLUDE_DIR ${PYTHON_ROOT}/include/python2.7)

FIND_PACKAGE(PythonInterp 2.7.10 REQUIRED)
FIND_PACKAGE(PythonLibs 2.7.10 REQUIRED)

set(BOOST_ROOT /data/home/rexyuan/ocrenv/boost166)

include_directories(${BOOST_ROOT}/include)
include_directories(${PYTHON_INCLUDE_DIR})
link_directories(${BOOST_ROOT}/lib)
# libboost_python.a
PYTHON_ADD_MODULE(demo demo.cpp)
# static lib .a link
target_link_libraries(demo libboost_python.a)
# dynamic lib .so link
# target_link_libraries(demo -lboost_python)
FILE(COPY demo.py DESTINATION .)