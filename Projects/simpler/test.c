#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xmath.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
using namespace std;
int main(){
	xt::xarray<double> gamma = 0.98;
	xt::xarray<double> a = 3;
	auto res = xt::pow(a,gamma);
	std::cout << res;
}
