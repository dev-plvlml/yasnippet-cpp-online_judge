cmake_minimum_required(VERSION 2.8)
project(yasnippet-cpp-online_judge-test)

enable_testing()

set(SOURCES
    binomial_coefficient_floating_point_test.cc
    binomial_coefficient_integer_test.cc
    disjoint_set_union_by_size_test.cc
    disjoint_set_union_randomized_test.cc
    fenwick_tree_2d_test.cc
    fenwick_tree_3d_test.cc
    fenwick_tree_test.cc
    golden_section_search_test.cc
    greatest_common_divisor_by_modulo_recursive_test.cc
    greatest_common_divisor_by_modulo_test.cc
    greatest_common_divisor_euclidean_test.cc
    knuth_morris_pratt_test.cc
    least_common_multiplier_test.cc
    modular_arithmetics_test.cc
    segment_tree_test.cc
    ternary_search_test.cc
    )

set(HEADERS
    ../binomial_coefficient_floating_point.h
    ../binomial_coefficient_integer.h
    ../disjoint_set_union_by_size.h
    ../disjoint_set_union_randomized.h
    ../fenwick_tree.h
    ../fenwick_tree_2d.h
    ../fenwick_tree_3d.h
    ../golden_section_search.h
    ../greatest_common_divisor_by_modulo.h
    ../greatest_common_divisor_by_modulo_recursive.h
    ../greatest_common_divisor_euclidean.h
    ../knuth_morris_pratt.h
    ../least_common_multiplier.h
    ../modular_arithmetics.h
    ../segment_tree.h
    ../ternary_search.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

find_package(GTest REQUIRED)
if (GTEST_FOUND)
  target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
endif (GTEST_FOUND)

add_test(AllTests ${PROJECT_NAME})
