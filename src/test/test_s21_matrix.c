#include "tests.h"

// Пример квадратной матрицы 1x1
void create_square_matrix_1x1(matrix_t *A) {
  s21_create_matrix(1, 1, A);
  A->matrix[0][0] = 3.678;
}
// Пример квадратной матрицы 2х2
void create_square_matrix_2x2(matrix_t *A) {
  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 12.345678;
  A->matrix[0][1] = 4.34;
  A->matrix[1][0] = 4.6;
  A->matrix[1][1] = 7.24;
}
// Пример квадратной матрицы 3x3
void create_square_matrix_3x3(matrix_t *A) {
  s21_create_matrix(3, 3, A);
  A->matrix[0][0] = 1.123456;
  A->matrix[0][1] = 2.654321;
  A->matrix[0][2] = 3.999999;
  A->matrix[1][0] = 4.123456;
  A->matrix[1][1] = 5.654321;
  A->matrix[1][2] = 6.999999;
  A->matrix[2][0] = 7.123456;
  A->matrix[2][1] = 8.654321;
  A->matrix[2][2] = 9.999999;
}

void create_square_matrix_3x3_1(matrix_t *A) {
  s21_create_matrix(3, 3, A);
  A->matrix[0][0] = 9.876543;
  A->matrix[0][1] = 8.123456;
  A->matrix[0][2] = 7.543210;
  A->matrix[1][0] = 6.987654;
  A->matrix[1][1] = 5.321098;
  A->matrix[1][2] = 4.210987;
  A->matrix[2][0] = 3.654321;
  A->matrix[2][1] = 2.123456;
  A->matrix[2][2] = 1.543210;
}

// единичная матрица
void create_square_matrix_4x4_identity(matrix_t *A) {
  s21_create_matrix(4, 4, A);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) {
        A->matrix[i][j] = 1.0;
      } else {
        A->matrix[i][j] = 0.0;
      }
    }
  }
}
// прямоугольная матрица
void create_matrix_3x2(matrix_t *A) {
  s21_create_matrix(3, 2, A);
  A->matrix[0][0] = 1.123456;
  A->matrix[0][1] = 2.234567;
  A->matrix[1][0] = 3.345678;
  A->matrix[1][1] = 4.456789;
  A->matrix[2][0] = 5.567890;
  A->matrix[2][1] = 6.678901;
}

void create_square_matrix_4x4_singular(matrix_t *A) {  // вырожденная матрица
  s21_create_matrix(4, 4, A);
  A->matrix[0][0] = 1.0;
  A->matrix[0][1] = 2.0;
  A->matrix[0][2] = 3.0;
  A->matrix[0][3] = 4.0;
  A->matrix[1][0] = 2.0;
  A->matrix[1][1] = 4.0;
  A->matrix[1][2] = 6.0;
  A->matrix[1][3] = 8.0;
  A->matrix[2][0] = 3.0;
  A->matrix[2][1] = 6.0;
  A->matrix[2][2] = 9.0;
  A->matrix[2][3] = 12.0;
  A->matrix[3][0] = 4.0;
  A->matrix[3][1] = 8.0;
  A->matrix[3][2] = 12.0;
  A->matrix[3][3] = 16.0;
}

void create_square_matrix_5x5_random(matrix_t *A) {
  s21_create_matrix(5, 5, A);

  A->matrix[0][0] = 12.345678;
  A->matrix[0][1] = 3.876543;
  A->matrix[0][2] = 45.678912;
  A->matrix[0][3] = 78.123456;
  A->matrix[0][4] = 9.876543;

  A->matrix[1][0] = 65.432109;
  A->matrix[1][1] = 87.654321;
  A->matrix[1][2] = 21.345678;
  A->matrix[1][3] = 9.012345;
  A->matrix[1][4] = 54.321098;

  A->matrix[2][0] = 76.543210;
  A->matrix[2][1] = 32.109876;
  A->matrix[2][2] = 98.765432;
  A->matrix[2][3] = 10.123456;
  A->matrix[2][4] = 43.210987;

  A->matrix[3][0] = 88.765432;
  A->matrix[3][1] = 65.987654;
  A->matrix[3][2] = 32.543210;
  A->matrix[3][3] = 11.234567;
  A->matrix[3][4] = 21.098765;

  A->matrix[4][0] = 44.321098;
  A->matrix[4][1] = 78.654321;
  A->matrix[4][2] = 54.098765;
  A->matrix[4][3] = 12.345678;
  A->matrix[4][4] = 3.987654;
}

// Тест 1: Успешное создание матрицы с корректными размерами
START_TEST(test_s21_create_matrix_success) {
  matrix_t result;
  int rows = 3;
  int columns = 3;
  int status = s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, columns);
  ck_assert_ptr_nonnull(result.matrix);
  s21_remove_matrix(&result);
}
END_TEST

// Тест 2: Некорректные размеры матрицы (ноль строк или столбцов)
START_TEST(test_s21_create_matrix_invalid_size) {
  matrix_t result;
  int status = s21_create_matrix(0, 3, &result);
  ck_assert_int_eq(status, 1);
  status = s21_create_matrix(3, -5, &result);
  ck_assert_int_eq(status, 1);
  status = s21_create_matrix(-3, 3, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

// Тест 3: Некорректный указатель на результат (NULL)
START_TEST(test_s21_create_matrix_null_pointer) {
  int rows = 3;
  int columns = 3;
  int status = s21_create_matrix(rows, columns, NULL);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_remove_matrix_success) {
  matrix_t result;
  int rows = 3;
  int columns = 3;
  int status = s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&result);
  ck_assert_ptr_null(result.matrix);
  ck_assert_int_eq(result.rows, 0);
  ck_assert_int_eq(result.columns, 0);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal) {
  matrix_t A, B;
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  s21_fill_matrix_with_value(&A, 1.1234567);
  s21_fill_matrix_with_value(&B, 1.1234567);
  // bИЗМЕНИТЬ
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  B.matrix[1][1] += 1e-8;

  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  B.matrix[1][1] += 1e-7;

  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

END_TEST

START_TEST(test_s21_eq_matrix_different_sizes) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_different_values) {
  matrix_t A, B;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_fill_matrix_with_value(&A, 1.0);
  s21_fill_matrix_with_value(&B, 2.0);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_null_matrices) {
  matrix_t A;
  int result = s21_eq_matrix(NULL, NULL);
  ck_assert_int_eq(result, FAILURE);
  s21_create_matrix(3, 3, &A);
  result = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(result, FAILURE);
  result = s21_eq_matrix(NULL, &A);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_sum_matrix_success) {
  matrix_t A, B, result;

  create_square_matrix_3x3(&A);
  create_square_matrix_3x3(&B);

  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 2.246912, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 5.308642, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], 7.999998, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 8.246912, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 11.308642, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], 13.999998, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][0], 14.246912, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], 17.308642, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], 19.999998, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_size_mismatch) {
  matrix_t A, B, result;
  int rowsA = 2;
  int columnsA = 2;
  int rowsB = 3;
  int columnsB = 3;

  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);

  s21_fill_matrix_with_value(&A, 1.0);
  s21_fill_matrix_with_value(&B, 2.0);

  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, FAIL_2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_null_pointer) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  int status = s21_sum_matrix(NULL, &B, NULL);
  ck_assert_int_eq(status, FAIL_1);

  status = s21_sum_matrix(&A, NULL, NULL);
  ck_assert_int_eq(status, FAIL_1);

  status = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(status, FAIL_1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_null_pointer) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  int status = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(status, FAIL_1);

  status = s21_sub_matrix(NULL, &B, &B);
  ck_assert_int_eq(status, FAIL_1);

  status = s21_sub_matrix(&A, NULL, &B);
  ck_assert_int_eq(status, FAIL_1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_size_mismatch) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, FAIL_2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_success) {
  matrix_t A, B, result;
  create_square_matrix_3x3(&A);
  create_square_matrix_3x3_1(&B);
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], -8.753087, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], -5.469135, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], -3.543211, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], -2.864198, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 0.333223, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], 2.789012, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][0], 3.469135, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], 6.530865, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], 8.456789, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_null_pointer) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int status = s21_mult_number(&A, 5.0, NULL);
  ck_assert_int_eq(status, FAIL_1);
  status = s21_mult_number(NULL, 5.0, &A);
  ck_assert_int_eq(status, FAIL_1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_number_success) {
  matrix_t A, result;
  int rows = 2;
  int columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_fill_matrix_with_value(&A, 2.0);
  double number = 3.0;
  int status = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(status, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], 6.0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_zero) {
  matrix_t A, result;
  int rows = 2;
  int columns = 2;

  s21_create_matrix(rows, columns, &A);
  s21_fill_matrix_with_value(&A, 4.0);

  double number = 0.0;

  int status = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(status, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], 0.0);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_negative) {
  matrix_t A, result;
  create_square_matrix_3x3(&A);
  double number = -2.2;
  int status = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -2.4716032, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], -5.8395062, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], -8.7999978, 1e-6);

  ck_assert_double_eq_tol(result.matrix[1][0], -9.0716032, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], -12.4395062, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], -15.3999978, 1e-6);

  ck_assert_double_eq_tol(result.matrix[2][0], -15.6716032, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], -19.0395062, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], -21.9999978, 1e-6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_success) {
  matrix_t A, B, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[1][0] = 9;
  B.matrix[1][1] = 10;
  B.matrix[2][0] = 11;
  B.matrix[2][1] = 12;

  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, OK);

  ck_assert_double_eq(result.matrix[0][0], 58);
  ck_assert_double_eq(result.matrix[0][1], 64);
  ck_assert_double_eq(result.matrix[1][0], 139);
  ck_assert_double_eq(result.matrix[1][1], 154);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  create_square_matrix_3x3(&A);
  create_square_matrix_3x3(&B);
  status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 40.700946113, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 52.60767117, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], 63.074053222, 1e-6);

  ck_assert_double_eq_tol(result.matrix[1][0], 77.812050113, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 103.49656017, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], 126.074044222, 1e-6);

  ck_assert_double_eq_tol(result.matrix[2][0], 114.923154113, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], 154.38544917, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], 189.074035222, 1e-6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_size_mismatch) {
  matrix_t A, B, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(4, 2, &B);

  int status = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status, FAIL_2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_null_pointer) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  int status = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(status, FAIL_1);

  status = s21_mult_matrix(NULL, &B, &result);
  ck_assert_int_eq(status, FAIL_1);

  status = s21_mult_matrix(&A, NULL, &result);
  ck_assert_int_eq(status, FAIL_1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_transpose_regular_matrix) {
  matrix_t A, result;
  // прямоугольная матрица
  create_matrix_3x2(&A);
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 1.123456, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 3.345678, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], 5.567890, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 2.234567, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 4.456789, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], 6.678901, 1e-6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  // единичная
  create_square_matrix_1x1(&A);
  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 3.678, 1e-6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  // квадратная 3х3
  create_square_matrix_3x3_1(&A);
  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 9.876543, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 6.987654, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], 3.654321, 1e-6);

  ck_assert_double_eq_tol(result.matrix[1][0], 8.123456, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 5.321098, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], 2.123456, 1e-6);

  ck_assert_double_eq_tol(result.matrix[2][0], 7.543210, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], 4.210987, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], 1.543210, 1e-6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_null_pointer) {
  matrix_t A, result;

  s21_create_matrix(2, 2, &A);

  int status = s21_transpose(&A, NULL);
  ck_assert_int_eq(status, FAIL_1);
  status = s21_transpose(NULL, &result);
  ck_assert_int_eq(status, FAIL_1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_regular_matrix) {
  matrix_t A, result;
  create_square_matrix_3x3_1(&A);
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -0.730273, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.604881, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], -4.607024, 1e-6);

  ck_assert_double_eq_tol(result.matrix[1][0], 3.481476, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], -12.323731, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], 8.713311, 1e-6);

  ck_assert_double_eq_tol(result.matrix[2][0], -5.930392, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], 11.119347, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], -4.209847, 1e-6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  create_square_matrix_5x5_random(&A);
  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -1062782.246069, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], -1713903.813708, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], -1173056.473802, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][3], 19462293.903043, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][4], 1277771.252671, 1e-6);

  ck_assert_double_eq_tol(result.matrix[1][0], -11273141.845822, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 9238244.402757, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], -6633220.176592, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][3], 1677833.155165, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][4], 27872331.812391, 1e-6);

  ck_assert_double_eq_tol(result.matrix[2][0], 195853.974113, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], -8855164.883991, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], 14044499.341250, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][3], -9072603.153888, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][4], 10039458.254847, 1e-6);

  ck_assert_double_eq_tol(result.matrix[3][0], 31792177.838998, 1e-6);
  ck_assert_double_eq_tol(result.matrix[3][1], -8447340.501648, 1e-6);
  ck_assert_double_eq_tol(result.matrix[3][2], -13620683.551006, 1e-6);
  ck_assert_double_eq_tol(result.matrix[3][3], 5924869.487017, 1e-6);
  ck_assert_double_eq_tol(result.matrix[3][4], -20294832.634977, 1e-6);

  ck_assert_double_eq_tol(result.matrix[4][0], -14136802.005580, 1e-6);
  ck_assert_double_eq_tol(result.matrix[4][1], 19049980.757630, 1e-6);
  ck_assert_double_eq_tol(result.matrix[4][2], 13143685.209138, 1e-6);
  ck_assert_double_eq_tol(result.matrix[4][3], -4095945.607323, 1e-6);
  ck_assert_double_eq_tol(result.matrix[4][4], -18196597.497454, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_null_pointer) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  int status = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(status, FAIL_1);
  status = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(status, FAIL_1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_non_square_matrix) {
  matrix_t A, result;
  create_matrix_3x2(&A);
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, FAIL_2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_regular_matrix) {
  matrix_t A;
  double result = 0.0;

  // единичная матрица
  create_square_matrix_1x1(&A);
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 3.678, 1e-6);
  s21_remove_matrix(&A);

  // матрица 2х2
  create_square_matrix_2x2(&A);
  status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 69.41870872, 1e-6);
  s21_remove_matrix(&A);

  // матрица 3х3
  create_square_matrix_3x3_1(&A);
  status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, -4.55678868, 1e-6);
  s21_remove_matrix(&A);

  // матрица 3х3
  create_square_matrix_3x3(&A);
  status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 0, 1e-6);
  s21_remove_matrix(&A);

  // матрица единичная
  create_square_matrix_4x4_identity(&A);
  status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 1, 1e-6);
  s21_remove_matrix(&A);

  // матрица вырожденная
  create_square_matrix_4x4_singular(&A);
  status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 0, 1e-6);
  s21_remove_matrix(&A);

  // матрица 5х5
  create_square_matrix_5x5_random(&A);
  status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 1459732891.450991808, 1e-6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_null_pointer) {
  double result = 0.0;
  int status = s21_determinant(NULL, &result);
  ck_assert_int_eq(status, FAIL_1);
}
END_TEST

START_TEST(test_s21_determinant_non_square_matrix) {
  matrix_t A;
  double result = 0.0;
  create_matrix_3x2(&A);
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, FAIL_2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_regular_matrix) {
  matrix_t A, result;
  create_square_matrix_5x5_random(&A);

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], -0.00072807, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], -0.00772274, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][2], 0.00013417, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][3], 0.02177945, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][4], -0.00968451, 1e-6);

  ck_assert_double_eq_tol(result.matrix[1][0], -0.00117412, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 0.00632872, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][2], -0.00606629, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][3], -0.00578691, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][4], 0.01305032, 1e-6);

  ck_assert_double_eq_tol(result.matrix[2][0], -0.00080361, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], -0.00454413, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][2], 0.00962128, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][3], -0.00933094, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][4], 0.00900417, 1e-6);

  ck_assert_double_eq_tol(result.matrix[3][0], 0.01333278, 1e-6);
  ck_assert_double_eq_tol(result.matrix[3][1], 0.00114941, 1e-6);
  ck_assert_double_eq_tol(result.matrix[3][2], -0.00621525, 1e-6);
  ck_assert_double_eq_tol(result.matrix[3][3], 0.00405887, 1e-6);
  ck_assert_double_eq_tol(result.matrix[3][4], -0.00280596, 1e-6);

  ck_assert_double_eq_tol(result.matrix[4][0], 0.00087535, 1e-6);
  ck_assert_double_eq_tol(result.matrix[4][1], 0.01909413, 1e-6);
  ck_assert_double_eq_tol(result.matrix[4][2], 0.00687760, 1e-6);
  ck_assert_double_eq_tol(result.matrix[4][3], -0.01390311, 1e-6);
  ck_assert_double_eq_tol(result.matrix[4][4], -0.01246570, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_non_square) {
  matrix_t A, result;
  create_matrix_3x2(&A);
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, FAIL_2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_singular_matrix) {
  matrix_t A, result;
  create_square_matrix_4x4_singular(&A);
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, FAIL_2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_null_pointer) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  int status = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(status, FAIL_1);
  status = s21_inverse_matrix(NULL, &A);
  ck_assert_int_eq(status, FAIL_1);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_matrix_oop_test(void) {
  Suite *s = suite_create("s21_matrix_oop_test");
  TCase *tc = tcase_create("s21_matrix_oop_test");

  // тесты для s21_create_matrix
  tcase_add_test(tc, test_s21_create_matrix_success);
  tcase_add_test(tc, test_s21_create_matrix_invalid_size);
  tcase_add_test(tc, test_s21_create_matrix_null_pointer);

  // тест для s21_remove_matrix
  tcase_add_test(tc, test_s21_remove_matrix_success);

  // тест для s21_eq_matrix
  tcase_add_test(tc, test_s21_eq_matrix_equal);
  tcase_add_test(tc, test_s21_eq_matrix_different_sizes);
  tcase_add_test(tc, test_s21_eq_matrix_different_values);
  tcase_add_test(tc, test_s21_eq_matrix_null_matrices);

  // тест для s21_sum_matrix
  tcase_add_test(tc, test_s21_sum_matrix_success);
  tcase_add_test(tc, test_s21_sum_matrix_size_mismatch);
  tcase_add_test(tc, test_s21_sum_matrix_null_pointer);
  suite_add_tcase(s, tc);

  // Тесты для s21_sub_matrix
  tcase_add_test(tc, test_s21_sub_matrix_null_pointer);
  tcase_add_test(tc, test_s21_sub_matrix_size_mismatch);
  tcase_add_test(tc, test_s21_sub_matrix_success);

  // Тесты для s21_mult_number
  tcase_add_test(tc, test_s21_mult_number_null_pointer);
  tcase_add_test(tc, test_s21_mult_number_success);
  tcase_add_test(tc, test_s21_mult_number_zero);
  tcase_add_test(tc, test_s21_mult_number_negative);

  // тесты для s21_mult_matrix
  tcase_add_test(tc, test_s21_mult_matrix_success);
  tcase_add_test(tc, test_s21_mult_matrix_size_mismatch);
  tcase_add_test(tc, test_s21_mult_matrix_null_pointer);

  // тесты для s21_transpose
  tcase_add_test(tc, test_s21_transpose_regular_matrix);
  tcase_add_test(tc, test_s21_transpose_null_pointer);

  // Добавляем тесты для функции s21_calc_complements
  tcase_add_test(tc, test_s21_calc_complements_regular_matrix);
  tcase_add_test(tc, test_s21_calc_complements_null_pointer);
  tcase_add_test(tc, test_s21_calc_complements_non_square_matrix);

  // Добавляем тесты для s21_determinant
  tcase_add_test(tc, test_s21_determinant_regular_matrix);
  tcase_add_test(tc, test_s21_determinant_null_pointer);
  tcase_add_test(tc, test_s21_determinant_non_square_matrix);

  // Добавляем тесты для s21_inverse_matrix
  tcase_add_test(tc, test_s21_inverse_matrix_regular_matrix);
  tcase_add_test(tc, test_s21_inverse_matrix_non_square);
  tcase_add_test(tc, test_s21_inverse_matrix_singular_matrix);
  tcase_add_test(tc, test_s21_inverse_matrix_null_pointer);
  return s;
}
