#include <iostream>
#include <vector>
#include <algorithm>
//in progress

/*
1353. Миллиардная Функция Васи
Ограничение времени: 1.0 секунды
Ограничение памяти: 16 МБ
Вася — начинающий математик — решил сделать вклад в развитие этой науки и прославиться на весь мир. Но как это сделать, когда самые интересные факты, типа теоремы Пифагора, давно уже доказаны? Правильно! Придумать что-то свое, оригинальное. Вот юный математик и придумал Теорию Функций Васи, посвященную изучению поведения этих самых функций. Функции Васи (ФВ) устроены довольно просто: значением N-й ФВ в точке S будет количество чисел от 1 до N, имеющих сумму цифр S. Вам, как крутым программистам, Вася поручил найти значения миллиардной ФВ (то есть ФВ с N = 109), так как сам он с такой задачей не справится. А Вам слабо?
Исходные данные
Целое число S (1 ≤ S ≤ 81).
Результат
Значение миллиардной Функции Васи в точке S.
Пример
исходные данные	результат
1
10
*/ 

using namespace std;

typedef int cnt_t;

int get_offset(int s, int l)
{
	return (l - 1) * 80 + s - 1;
}
cnt_t f(vector<cnt_t>& map, int s, int l)
{
	if(l == 1) {
		return 1;
	} else {
		const int offset = get_offset(s,l);
		cnt_t sum = map[offset];
		if(sum < 0) {
			const int mx_i = std::min(9, s);
			sum = 0;
			for(int i = 0; i <= mx_i; ++i) {
				sum += f(map, s - i, l - 1);
			}
			map[offset] = sum;
		}
		return sum;
	}
}

cnt_t g(vector<int>& digits, int s) {

	int mxi = std::min(s, 9);
	for(int i = 0; i <= mxi; ++i) {
		digits.push_back(i);

	}

}

int main()
{
	vector<cnt_t> map(8*80, -1);
	int s;
	//cin >> s;

	s = 1;

	cnt_t fs = 0;
	vector<int> digits;
	digits.reserve(10);
	for(int l = 1; l < 10; ++l) {
		fs += f(map, s, l, digits);
	}

	if(s == 1) ++fs;

	cout << fs << endl;
	return 0;
}
