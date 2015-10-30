#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	for (int i = 0; i < 10; i++)
		v[i] = i;
	TVector<int> b(v);
	EXPECT_EQ(b, v);

}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(15);
	v1[7] = 1;
	TVector<int> v2(v1);
	v2[7] = 2;

	EXPECT_NE(v1, v2);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-1] = 10);

}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[5] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	const int size = 10;
	TVector<int> v(size);
	TVector<int> test(size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	for (int i = 0; i < size; i++)
		test[i] = i;
	v = v;
	EXPECT_EQ(v, test);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int size = 10;
	TVector<int> v(size);
	TVector<int> b(size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	b = v;
	EXPECT_EQ(b, v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(10), v2(5);
	v1[1] = 1;
	v2[2] = 2;
	v1 = v2;

	EXPECT_EQ(v1.GetSize(), v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	const int size = 10;
	TVector<int> v(size);
	TVector<int> b(size+10);
	TVector<int> test(size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	for (int i = 0; i < size; i++)
		test[i] = i;
	b=v;
	EXPECT_EQ(b, test);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	const int size = 10;
	TVector<int> v(size + 10);
	TVector<int> b(size);
	for (int i = 0; i < size + 10; i++)
		v[i] = i;
	b = v;
	EXPECT_EQ(true, b==v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	const int size = 10;
	TVector<int> v(size + 10);
	for (int i = 0; i < size + 10; i++)
		v[i] = i;
	EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	const int size = 10;
	TVector<int> v(size + 10);
	TVector<int> b(size);
	for (int i = 0; i < size + 10; i++)
		v[i] = i;
	EXPECT_EQ(true, b != v);
}

TEST(TVector, can_add_scalar_to_vector)
{
	const int size = 10;
	TVector<int> v(size);
	v=v + 5;
	ASSERT_NO_THROW(v);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	const int size = 10;
	TVector<int> v(size);
	for (int i = 0; i < size; i++)
		v[i] = i+10;
	v = v - 5;
	ASSERT_NO_THROW(v);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	const int size = 10;
	TVector<int> v(size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	v = v*5;
	ASSERT_NO_THROW(v);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	const int size = 10;
	TVector<int> v(size);
	TVector<int> b(size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	b=v+v;
	EXPECT_EQ(v+v, b);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	const int size = 10;
	TVector<int> v(size);
	TVector<int> b(size + size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	for (int i = 0; i < size + size; i++)
		b[i] = i + size;
	ASSERT_ANY_THROW(b+v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	const int size = 10;
	TVector<int> v(size);
	TVector<int> c(size);
	TVector<int> b(size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	for (int i = 0; i < size; i++)
		b[i] = i + size;
	c = b;
	b = b - v;
	EXPECT_EQ(c - v, b);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	const int size = 10;
	TVector<int> v(size);
	TVector<int> b(size + size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	for (int i = 0; i < size + size; i++)
		b[i] = i + 10;
	ASSERT_ANY_THROW(b - v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	const int size = 10;
	int s = 0;
	TVector<int> v(size);
	TVector<int> c(size);
	TVector<int> b(size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	for (int i = 0; i < size; i++)
		b[i] = i + size;
	s = v*b;
	EXPECT_EQ(s, v*b);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	const int size = 10;
	TVector<int> v(size);
	TVector<int> b(size + size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	for (int i = 0; i < size + size; i++)
		b[i] = i + size;
	ASSERT_ANY_THROW(b + v);
}

