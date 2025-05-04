cmake_minimum_required(VERSION 3.30)
project(Algoritms_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Algoritms_C main.c
        reverse_linked_list.h
        reverse_linked_list.c
        balanced_tree.c
        balanced_tree.h
        merge_sorted_lists.c
        merge_sorted_lists.h
        remove_duplicates_sorted_list.c
        two_number_sum_target.c
        gpio_driver.h
        gpio_driver.c
        bits_to_bytes.h
        bits_to_bytes.c
        search_insert_pos.h
        binary_tree_inorder.h
        reverse_bits_uint32.h
)
