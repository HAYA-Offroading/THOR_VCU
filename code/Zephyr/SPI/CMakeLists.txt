cmake_minimum_required(VERSION 3.20.0)
set(BOARD blackpill_f401cc)

find_package(Zephyr)
project(SPI_test)

target_sources(app PRIVATE src/main.c)