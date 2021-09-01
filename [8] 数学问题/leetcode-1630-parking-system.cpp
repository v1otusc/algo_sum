/*
 * @Description:
 *
 *
 *
 * @输入示例：
 *
 *
 *
 * @输出实例：
 *
 *
 *
 * @输入输出说明：
 *
 *
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class ParkingSystem {
  int big_, medium_, small_;

 public:
  ParkingSystem(int big, int medium, int small)
      : big_(big), medium_(medium), small_(small) {}

  bool addCar(int carType) {
    switch (carType) {
      case 1:
        if (big_ > 0) {
          big_--;
          return true;
        }
        return false;
      case 2:
        if (medium_ > 0) {
          medium_--;
          return true;
        }
        return false;
      default:
        if (small_ > 0) {
          small_--;
          return true;
        }
        return false;
    }
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main(int argc, char const* argv[]) { return 0; }