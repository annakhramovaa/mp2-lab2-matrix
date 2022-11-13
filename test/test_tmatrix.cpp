#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	m[1][2] = 2;
	TDynamicMatrix<int> n(m);
	EXPECT_EQ(m, n);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 2;
	m[0][1] = 3;
	m[1][0] = 4;
	m[1][1] = 5;
	TDynamicMatrix<int> n(m);
	m[1][1] = 8;

	EXPECT_EQ(2,n[0][0]);
	EXPECT_EQ(3, n[0][1]);
	EXPECT_EQ(4, n[1][0]);
	EXPECT_EQ(5, n[1][1]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> n(4);

	EXPECT_EQ(n.size(), 4);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(4);
	
	ASSERT_ANY_THROW(m.at(-1, 3));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(4);

	ASSERT_ANY_THROW(m.at(5, 0));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(4);

	ASSERT_NO_THROW(m=m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(4);
	m[0][1] = 3;
	TDynamicMatrix<int> n(4);
	n[0][1] = 4;
	n = m;

	EXPECT_EQ(m,n);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> n(5);
	m = n;
	EXPECT_EQ(m.size(), n.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> n(5);
	m = n;

	EXPECT_EQ(m.size(), n.size());
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> n(m);

	EXPECT_EQ(m == n, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(4);

	EXPECT_EQ(m == m, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> n(5);

	EXPECT_EQ(m == n, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(4);
	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 4; j++)
			m[i][j] = 2;
	TDynamicMatrix<int> n(m);
	TDynamicMatrix<int> res(4);

	res = m + n;
	EXPECT_EQ(res, m+n);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> n(5);

	ASSERT_ANY_THROW(m + n);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(4);
	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 4; j++)
			m[i][j] = 2;
	TDynamicMatrix<int> n(m);
	TDynamicMatrix<int> res(4);

	res = m - n;
	EXPECT_EQ(res, m - n);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> n(5);

	ASSERT_ANY_THROW(m - n);
}

