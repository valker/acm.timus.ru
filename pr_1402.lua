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
