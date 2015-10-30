#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = i;
	TMatrix<int> q(m);
	EXPECT_EQ(m, q);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	m[1][2] = 3;
	TMatrix<int> m1(m);
	m1[1][2] = 5;

	EXPECT_NE(m[1][2], m1[1][2]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(m.GetSize());
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[1][2] = 3;

	EXPECT_EQ(3, m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[1][-2] = 3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[1][10] = 3);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5), test(5);
	m[2][3] = 1;
	test[2][3] = 1;

	ASSERT_NO_THROW(m = m);
	m = m;

	EXPECT_EQ(m, test);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5), m2(5), test(5);
	m[1][1] = 5;
	test[1][1] = 5;

	ASSERT_NO_THROW(m2 = m);

	EXPECT_EQ(test, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(5), m2(10);
	m1[1][1] = 5;

	ASSERT_NO_THROW(m2 = m1);

	EXPECT_EQ(5, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(5), m2(10), test(5);
	m1[1][1] = 5;
	test[1][1] = 5;

	ASSERT_NO_THROW(m2 = m1);

	EXPECT_EQ(test, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(5), m2(5);
	m1[1][1] = 5;
	m2[1][1] = 5;

	ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(5);
	m1[1][1] = 5;

	ASSERT_TRUE(m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5), m2(10);
	m1[1][1] = 5;
	m2[1][1] = 5;

	EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(5), m2(5),test(5);
	m1[1][1] = 5;
	m1[2][3] = 1;
	m2[1][1] = 5;
	m2[2][3] = 4;
	m2[3][1] = 1;

	test[1][1] = 10;
	test[2][3] = 5;
	test[3][1] = 1;

	EXPECT_EQ(test, m1 + m2);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(5), m2(10);
	m1[1][1] = 5;
	m1[2][3] = 4;

	m2[1][1] = 5;
	m2[2][3] = 4;

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(5), m2(5), test(5);
	m1[1][1] = 6;
	m1[2][3] = 10;
	m1[3][1] = 8;

	m2[1][1] = 5;
	m2[2][3] = 4;
	m2[3][1] = 1;

	test[1][1] = 1;
	test[2][3] = 6;
	test[3][1] = 7;

	EXPECT_EQ(test, m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(5), m2(10);
	m1[4][4] = 2;
	m2[4][4] = 3;
	m2[7][7] = 10;

	ASSERT_ANY_THROW(m1 - m2);
}

