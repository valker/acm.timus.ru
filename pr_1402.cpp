#include <iostream>
//ac
using namespace std;

/**
// Precalculated using Lua
require "BigNum"

local function fact(x)
	if x == 0 or x == 1 then return 1 end
	local p = BigNum.new(1)
	while x > BigNum.new(1) do
		p = p * x
		x = x - 1
	end
	return p
end

for i = 0,21 do
	local s = BigNum.new()
	local b_n = BigNum.new(i)
	local f_c = fact(b_n)

	for k = 2,i do
		local b_k = BigNum.new(k)
		local n_k = b_n - b_k
		local fact_n_k = fact(n_k)
		local divv = f_c / fact_n_k
		s = s + divv
	end
	print('"' .. tostring(s) .. '",')
end
**/

int main()
{
	static const char* msg[] = {
		"0",
		"0",
		"2",
		"12",
		"60",
		"320",
		"1950",
		"13692",
		"109592",
		"986400",
		"9864090",
		"108505100",
		"1302061332",
		"16926797472",
		"236975164790",
		"3554627472060",
		"56874039553200",
		"966858672404672",
		"17403456103284402",
		"330665665962403980",
		"6613313319248079980",
		"138879579704209680000"
	};

	int n;
	cin >> n;

	cout << msg[n] << endl;

	return 0;
}
