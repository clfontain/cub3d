#!/bin/bash
g++ ./test_cub3d.cpp
printf "***************************************\n"
printf "LE SYMPATHIQUE TESTEUR CUB3D DE CFONFON\n"
printf "***************************************\n"
valgrind ./cub3d  &> VALGRIND_LOG
./cub3d  &> LOG
./a.out
valgrind ./cub3d ./map/2_elements.cub  &> VALGRIND_LOG
./cub3d ./map/2_elements.cub  &> LOG
./a.out
valgrind ./cub3d ./map/EA_miss.cub  &> VALGRIND_LOG
./cub3d ./map/EA_miss.cub  &> LOG
./a.out
valgrind ./cub3d ./map/empty_map.cub   &> VALGRIND_LOG
./cub3d ./map/empty_map.cub   &> LOG
./a.out
valgrind ./cub3d ./map/empty.cub  &> VALGRIND_LOG
./cub3d ./map/empty.cub  &> LOG
./a.out
valgrind ./cub3d ./map/end.cub  &> VALGRIND_LOG
./cub3d ./map/end.cub  &> LOG
./a.out
valgrind ./cub3d ./map/invalid_char.cub  &> VALGRIND_LOG
./cub3d ./map/invalid_char.cub  &> LOG
./a.out
valgrind ./cub3d ./map/invalid_wall.cub  &> VALGRIND_LOG
./cub3d ./map/invalid_wall.cub  &> LOG
./a.out
valgrind ./cub3d ./map/invalid_wall2.cub  &> VALGRIND_LOG
./cub3d ./map/invalid_wall2.cub  &> LOG
./a.out
valgrind ./cub3d ./map/map_wrong_color.cub  &> VALGRIND_LOG
./cub3d ./map/map_wrong_color.cub  &> LOG
./a.out
valgrind ./cub3d ./map/path_image.cub  &> VALGRIND_LOG
./cub3d ./map/path_image.cub  &> LOG
./a.out
valgrind ./cub3d ./map/str_map_no_empty.cub  &> VALGRIND_LOG
./cub3d ./map/str_map_no_empty.cub  &> LOG
./a.out
valgrind ./cub3d ./map/str_no_empty.cub  &> VALGRIND_LOG
./cub3d ./map/str_no_empty.cub  &> LOG
./a.out


