#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "OLS.hpp"

using namespace std;

int main() {
  ifstream file_data;

  file_data.open("data.txt");
  if (file_data.is_open()) {
    cout << "file is open\n";
  }

  OLS obj;

  double **buf = new double* [max_elem];
  for (int i = 0.0; i < max_elem; i++) {
    buf[i] = new double[max_col];
  }

  for (int i = 0.0; i < max_elem; i++) {
    for (int j = 0.0; j < max_col; j++) {
      file_data >> buf[i][j];
      cout << buf[i][j] << " ";
    }
    cout << "\n";
  }

  file_data.close();

  cout << "-------------------\n";

  obj.init_x(buf, max_elem, max_col);
  obj.init_time(buf, max_elem);
  obj.take_interval(buf, max_elem, max_col);

  for (int i = 0.0; i < max_elem; i++) {
    delete [] buf[i];
  }
  delete [] buf;

  int n = 0;
for (n = 0; n < max_elem; n++) {
  int k = max_elem - 2;
  for (int i = n + 1; i < max_elem; i++) {
	  obj.get_sum_time(k, n);
	  obj.get_sum_xi(k, n);
	  obj.get_sum_time_xi(k, n);
	  obj.show_sum();

	  cout << "=============\n";

	  obj.get_coeff_a_b();
	  obj.show_coeff();
	  obj.clear_all_summ();
	  cout << "=============\n";
	  k--;
	}
  cout << "$$$$$$$$$$$$$\n";
}
  return 0;
}
