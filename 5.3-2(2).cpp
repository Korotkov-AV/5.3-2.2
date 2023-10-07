// 5.3-2(2).cpp : 


#include <iostream>

using namespace std;

class smart_array {
private:
	int* a;
	int null;
	int size;
public:
	smart_array(int s) {
		a = new int[s];
		null = 0;
		size = s;
	}

	void add_element(int num) {
		if (null >= size) throw runtime_error("array is full");
		else {
			a[null] = num;
			null++;
		}
	}

	int get_element(int i) {
		if (i >= null) throw runtime_error("this element doesn't exist");

		return a[i];
	}

	void swap(smart_array& other) noexcept {
		std::swap(a, other.a);
		std::swap(null, other.null);
		std::swap(size, other.size);
	}

	smart_array& operator=(const smart_array& z) {
		smart_array copy(z.size);
		copy.null = z.null;
		for (int i = 0; i < z.size; i++)
		{
			copy.a[i] = z.a[i];
		}
		swap(copy);
		return *this;
	}

	~smart_array() {
		delete[] a;
	}

	smart_array(const smart_array& z) {
		null = z.null;
		size = z.size;
		a = new int[size];
		for (int i = 0; i < z.size; i++)
		{
			a[i] = z.a[i];
		}
	}
};

int main() {
	try {
		smart_array arr(3);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
		smart_array new_copy(arr);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}