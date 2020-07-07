#include "OLS.hpp"
#include <iostream>

using namespace std;

  /*OLS::OLS(int col, int row) {
      int max_elem = row;
      int max_col = col;
  }*/

  void OLS::init_time(double **ti, const int max_elem) {
    int j = 0;
    for (int i = 0.0; i < max_elem; i++) {
      t[i] = ti[i][j];
    }
  }

  void OLS::init_x(double **xi, const int max_elem, const int max_col) {
    for (int i = 0.0; i < max_elem; i++) {
      for (int j = 1.0; j < max_col; j++) {
        x[i] = xi[i][j];
      }
    }
  }

  double OLS::get_sum_time(int k, int n) {
    for (int i = n; i < max_elem - k + n; i++) {
      sum_time_a += pow(t[i], a);
      sum_time_b += pow(t[i], b);
      sum_time_e += pow(t[i], e);
    }
  }

  double OLS::get_sum_xi(int k, int n) {
    for (int i = n; i < max_elem - k + n; i++) {
      sum_x += x[i];
    }
    return sum_x;
  }

  double OLS::get_sum_time_xi(int k, int n) {
    for (int i = n; i < max_elem - k + n; i++) {
      sum_time_x += pow(t[i], delta) * x[i];
      sum_time_c_x += pow(t[i], c) * x[i];
    }
    return sum_time_x;
  }

  void OLS::show_sum() {
    cout << "Summ time_a: " << sum_time_a << "\n";
    cout << "Summ time_b: " << sum_time_b << "\n";
    cout << "Summ time_e: " << sum_time_e << "\n";
    cout << "Summ xi: "<< sum_x << "\n";
    cout << "Summ xi*ti: "<< sum_time_x << "\n";
    cout << "Summ xi*ti_c: "<< sum_time_c_x << "\n";
  }

  void OLS::get_coeff_a_b() {
    coefficient_b = ((sum_time_x * sum_time_a) - (sum_time_b * sum_time_c_x))
    / ((sum_time_a * sum_time_a) - (sum_time_e * sum_time_b));

    coefficient_a = (sum_time_c_x - coefficient_b * sum_time_e) / sum_time_a;
  }

  void OLS::show_coeff() {
    cout << "Coefficient A: " << coefficient_a << "\n";
    cout << "Coefficient B: " << coefficient_b << "\n";
  }

  double OLS::take_coeff_b() {
    return coefficient_b;
  }

  double OLS::take_coeff_a() {
    return coefficient_a;
  }

  void OLS::clear_all_summ() {
    sum_time_a = 0.0;
    sum_time_b = 0.0;
    sum_time_e = 0.0;
    sum_x = 0.0;
    sum_time_c_x = 0.0;
    sum_time_x = 0.0;
    coefficient_b = 0.0;
    coefficient_a = 0.0;
  }

  void OLS::take_interval(double **buff, const int max_elem, const int max_col) {
    for (int i = 0.0; i < max_elem; i++ ) {
      for (int j = 0.0; j < max_col; j++) {
        class_buff[i][j] = buff[i][j];
      }
    }
  }
