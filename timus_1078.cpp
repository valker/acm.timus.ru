#include <iostream>
#include <vector>
#include <algorithm>
//ac
using namespace std;

struct otr {
	int left_;
	int right_;
	int weight_;
	int index_;
	int parent_;
	int length() const { return right_ - left_; }
	otr(int left, int right) : left_(left), right_(right), weight_(1), parent_(-1) {}
};

bool cmp_by_length(const otr& left, const otr& right)
{
	return left.length() < right.length();
}

bool cmp_by_index(const otr& left, const otr& right)
{
	return left.index_ < right.index_;
}

bool cmp_by_weight(const otr& left, const otr& right)
{
	return left.weight_ < right.weight_;
}

struct Cmp {
	const otr& o_;
	explicit Cmp(const otr& o) : o_(o) {}
	void operator()(otr& obj) const {
		if(obj.left_ > o_.left_ && obj.right_ < o_.right_) {
			if(obj.weight_ < (o_.weight_ + 1)) {
				obj.parent_ = o_.index_;
				obj.weight_ = o_.weight_ + 1;
			}
		}
	}
};

int main()
{
	int n;
	cin >> n;
	vector<otr> otrs;
	otrs.reserve(n);
	for(int i = 0; i < n; ++i) {
		int left, right;
		cin >> left >> right;
		otrs.push_back(otr(left,right));
		otrs.back().index_ = i + 1;
	}

	vector<otr> bins; bins.reserve(n);

	// biggest last
	sort(otrs.begin(), otrs.end(), cmp_by_length);
	int max = 0;

	while(!otrs.empty()) {
		// take biggest item
		const otr& o = otrs.back();
		// find all items that includes this item
		for_each(otrs.begin(), otrs.end() - 1, Cmp(o));

		if(o.weight_ > max) {
			max = o.weight_;
		}

		bins.push_back(o);

		otrs.pop_back();
	}

	sort(bins.begin(), bins.end(), cmp_by_index);
	// find max weight
	vector<otr>::iterator it = max_element(bins.begin(), bins.end(), cmp_by_weight);
	if(it != bins.end()) {
		cout << it->weight_ << endl;
		bool ok = true;
		bool first = true;
		do {
			if(!first) cout << ' ';
			else first = false;
			cout << it->index_;
			int parent = it->parent_;
			if(parent != -1) {
				it = bins.begin();
	 			advance(it, parent - 1);
			} else {
				ok = false;
			}
		} while(ok);
		cout << endl;
	} else {
		cout << "ERROR!\n";
	}
	return 0;
}

