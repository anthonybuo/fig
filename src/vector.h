#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <memory>
#include <algorithm>
#include <stdexcept>

namespace fig {

template <typename T, typename Allocator = std::allocator<T>>
class vector {
 public:
	class iterator{
   public:
		iterator(vector<T>& vector, std::size_t position)
			: vector_{vector}, position_{position}
		{}

		T& operator*() const {
			return vector_[position_];
		}

		void operator++() {
			position_++;
		}

		void operator--() {
			position_--;
		}

	 private:
		vector<T>& vector_;
		std::size_t position_;	
	};

	vector() {}

	vector(std::size_t size) : total_count_{size}, current_count_{size} {
		data_ = new T[total_count_];	
	}

	~vector() {
		if (data_) {
			delete[] data_;
		}
	}

	void print() const {
		for (int i = 0; i < current_count_; i++) {
			std::cout << data_[i] << " ";
		}
		std::cout << std::endl;
	}

	/* Element access */
	T& at(std::size_t i) const {
		if (i > current_count_) {
			throw std::out_of_range("index out of range for fig::vector");
		}
		return data_[i];
	}

	T& operator[](std::size_t i) const {
		return data_[i];
	}

	T& front() const {
		return data_[0];
	}

	T& back() const {
		return data_[current_count_];
	}

	T* data() const {
		return data_;
	}

	/* Iterators */
	iterator begin() {
		return iterator(*this, 0);
	}

	iterator end() {
		return iterator(*this, current_count_);
	}

	/* Capacity */
	bool empty() const {
		return current_count_ == 0;
	}

	std::size_t size() const {
		return current_count_;
	}

	std::size_t max_size() const {
		return 100000;
	}

	void reserve(std::size_t);

	std::size_t capacity() const {
		return total_count_;
	}

	void shrink_to_fit();

	/* Modifiers */
	void clear();

	void insert(iterator pos, const T& value);

	void push_back(const T& data) {
		if (total_count_ == current_count_) {
			if (total_count_ == 0) {
				total_count_ = kInitialCount;
				data_ = new T[total_count_];
			} else {
				T* tmp = new T[total_count_ * kExpansionFactor];
				std::copy(data_, data_ + total_count_, tmp);
				delete[] data_;
				data_ = tmp;
				total_count_ *= kExpansionFactor;
			}
		}
		data_[current_count_++] = data;		
	}

	void pop_back() {
		current_count_--;
	}

 private:
	T* data_ = nullptr;
	std::size_t total_count_ = 0;
	std::size_t current_count_ = 0;
	const static int kExpansionFactor = 2;
	const static int kInitialCount = 1;
};

}  // namespace fig

#endif  // _VECTOR_H_

