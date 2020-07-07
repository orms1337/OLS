#ifndef OLS_H
#define OLS_H

constexpr int max_elem = 5;
constexpr int max_col = 2;

constexpr double delta = 1.0;
constexpr double omega = 1.0;
constexpr double z = 1.0;
constexpr double a = 2 * delta - (omega / z);
constexpr double b = 2 * delta;
constexpr double c = delta - (omega / z);
constexpr double e = 2 * (delta - (omega / z));

class OLS {
  public:
    ///OLS(int col, int row);
    void init_time(double **ti, const int max_elem);
    void init_x(double **xi, const int max_elem, const int max_col);
    void take_interval(double **buff, const int max_elem, const int max_col);
    double get_sum_time(int k, int n);
    double get_sum_xi(int k, int n);
    double get_sum_time_xi(int k, int n);
    void get_coeff_a_b();
    void show_sum();
    void show_coeff();
    double take_coeff_b();
    double take_coeff_a();
    void clear_all_summ();
  private:
    double t[max_elem], x[max_elem], class_buff[max_elem][max_col];;
    double sum_time_a = 0.0, sum_time_b = 0.0, sum_time_e = 0.0;
    double sum_x = 0.0;
    double sum_time_c_x = 0.0, sum_time_x = 0.0;
    double coefficient_b, coefficient_a;
  };

#include "impl_OLS.cpp"

/* OLS_H */

#endif
