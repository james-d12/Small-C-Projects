#ifndef _TEST_VECTOR_H
#define _TEST_VECTOR_H

#include "../src/vector.h"

/* TEST SECTION 1: Creation, Copy, Assign and destroy functions */

int test_vector_new();
int test_vector_new_null();
int test_vector_new_array();
int test_vector_copy();
int test_vector_assign();

int test_vector_get_at_index();
int test_vector_set_at_index();

/* TEST SECTION 2: Comparison functions */

int test_vector_equal();
int test_vector_not_equal();
int test_vector_less();
int test_vector_greater();
int test_vector_less_equal();
int test_vector_greater_equal();

int test_vector_is_collinear();
int test_vector_is_orthogonal();
int test_vector_is_coplanar();

/* TEST SECTION 3: Mathematical functions */

int test_vector_add();
int test_vector_sub();
int test_vector_mult();
int test_vector_mult_scale();
int test_vector_div();

int test_vector_magnitude();
int test_vector_normalise();

int test_vector_dot();
int test_vector_dot_angle();
int test_vector_cross();
int test_vector_cross_angle();
int test_vector_scalar_triplet_product();

int test_vector_dir_cos_a();
int test_vector_dir_cos_b();
int test_vector_angle_between_vector();

int test_vector_projection();

void test_vector_run();

#endif