#include <vector>
#include <string>
#include <iostream>
// in progress

using namespace std;

struct Test {
};

enum CardName {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX
	SEVEN
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

enum CardSuit {
	SPEAR,
	CLUBS,
	DIAMONDS,
	HEARTS
};

struct Card {
	CardName name_;
	CardSuit suit_;
};

struct Cards {
	vector<Card> cards_;
};

Cards read_cards(int n)
{
	Cards cards;
	string s;
	getline(cin,s);
	if(s.empty()) throw std::exception;
	size_t start = 0;
	for(int i = 0; i < n; ++i) {
		size_t separator = s.find(' ',start);
		size_t len = separator == string::npos ? separator : separator - start;
		string x = s.substr(start, len);
		cards.add(make_card(x));
		if(separator == string::npos) {
			break;
		}
		start = separator + 1
	}
	return cards;
}

Test read_test()
{
	Cards sasha = read_cards(3);
	Cards dima = read_cards(3);
	Cards hidden = read_cards(2);
}

bool make_test()
{
	try {
		Test test = read_test();
		cout << check_winner(test) << endl;
		return true;
	} catch(...) {
		return false;
	}
}

int main()
{
	while(make_test()) {
	}

	return 0;
}