cmake_minimum_required(VERSION 3.16)
module_switch(ENABLE_GENERIC "Enable generic")
if (NOT ENABLE_GENERIC)
  return()
endif()

set(GENERIC_SOURCES
    generic-parser.h
    generic-plugin.c
    generic-parser.c
)

add_module(
  TARGET generic
  GRAMMAR generic-grammar
  SOURCES ${GENERIC_SOURCES}
)
