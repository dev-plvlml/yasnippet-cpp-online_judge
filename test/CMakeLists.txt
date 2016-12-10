cmake_minimum_required(VERSION 2.8)
project(yasnippet-cpp-online_judge-test)

enable_testing()

set(SOURCES
    binomial_coefficient_floating_point_test.cc
    binomial_coefficient_integer_test.cc
    convex_hull_chans_algorithm_test.cc
    convex_hull_grahams_scan_test.cc
    convex_hull_jarvis_march_test.cc
    disjoint_set_union_by_size_test.cc
    disjoint_set_union_randomized_test.cc
    fenwick_tree_test.cc
    fenwick_tree_2d_test.cc
    fenwick_tree_3d_test.cc
    geometry/geometry_test.cc
    golden_section_search_test.cc
    greatest_common_divisor_by_division_test.cc
    greatest_common_divisor_by_division_recursive_test.cc
    greatest_common_divisor_by_subtraction_test.cc
    least_common_multiplier_test.cc
    modular_arithmetics_test.cc
    prime_number_linear_sieve_test.cc
    prime_number_sieve_of_eratosthenes_test.cc
    segment_tree_test.cc
    string_search_knuth_morris_pratt_test.cc
    ternary_search_test.cc
    treap_with_implicit_key_test.cc
    )

set(HEADERS
    segment_tree_minmax.h
    treap_with_implicit_key_sum.h
    treap_with_implicit_key_minmax.h
    ../binomial_coefficient_floating_point.h
    ../binomial_coefficient_integer.h
    ../convex_hull_chans_algorithm_test.h
    ../convex_hull_grahams_scan.h
    ../convex_hull_jarvis_march_test.h
    ../disjoint_set_union_by_size.h
    ../disjoint_set_union_randomized.h
    ../fenwick_tree.h
    ../fenwick_tree_2d.h
    ../fenwick_tree_3d.h
    ../geometry/0_types.h
    ../geometry/1_vector.h
    ../geometry/2_point.h
    ../geometry/3_line.h
    ../geometry/4_segment.h
    ../geometry/5_polygon.h
    ../geometry/6_convex_polygon.h
    ../golden_section_search.h
    ../greatest_common_divisor_by_division.h
    ../greatest_common_divisor_by_division_recursive.h
    ../greatest_common_divisor_by_subtraction.h
    ../least_common_multiplier.h
    ../modular_arithmetics.h
    ../pi_function.h
    ../prime_number_linear_sieve.h
    ../prime_number_sieve_of_eratosthenes.h
    ../segment_tree.h
    ../string_search_knuth_morris_pratt.h
    ../ternary_search.h
    ../treap_with_implicit_key.h
    ../z_function.h
    )

include_directories(../)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

find_package(GTest REQUIRED)
if (GTEST_FOUND)
  target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
endif (GTEST_FOUND)

add_test(AllTests ${PROJECT_NAME})
