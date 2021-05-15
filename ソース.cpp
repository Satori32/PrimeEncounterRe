#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

//how count the writing like this code. by me. XD

template<class T>
class PrimeEncounterRe {
public:

	PrimeEncounterRe() {
		Initialize();
	}

	bool Initialize() {
		B.clear();
		B.push_back(2);
		C = 3;
		return true;
	}

	bool Search(const T& In) {
		for (C; C <= In; C++) {
			bool f = false;
			for (std::size_t i = 0; i < B.size(); i++) {
				if (C % B[i] == 0) { f = true; break; }
			}
			if (!f) {
				B.push_back(C);
			}
		}
		return true;
	}
	bool IsFind(const T& In)const {
		auto It = std::find(B.begin(), B.end(), In);
		return It != B.end();
	}

	bool IsFind(const T& In) {
		Search(In);
		auto It = std::find(B.begin(), B.end(), In);
		return It != B.end();
	}
	const T& Count() const{
		return C;
	}
	std::size_t Size() const {
		return B.size();
	}
	const T& operator[](std::size_t In) const {
		return B[In];
	}
	typename std::vector<T>::const_iterator begin() const{
		return B.cbegin();
	}
	typename std::vector<T>::const_iterator end()const {
		return B.cend();
	}
protected:
	std::vector<T> B;
	T C=3;
};

int main() {
	PrimeEncounterRe<std::size_t> PER;

	PER.Search(23);

	const PrimeEncounterRe<std::size_t>* P = &PER;

	P->IsFind(32);
	for (auto& o : PER) {
		std::cout << o << ',';
	}
	std::cout << std::endl;

	PER.Search(32);
	for (auto& o : PER) {
		std::cout << o << ',';
	}
	std::cout << std::endl;

	PER.Search(0xbeef);

	for (auto& o : PER) {
		std::cout << o << ',';
	}
	std::cout << std::endl;
	
	return 0;

	

}