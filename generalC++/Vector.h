#pragma once

template<typename T>
class Vector {
public:
	Vector();
	~Vector();
	void push_back(const T);
	size_t size();
	T &operator[](size_t n) {
		if (n < top) {
			return vStart[n];
		}
	};
private:
	T* vStart;
	int top;
	size_t tSize, mSize;
	void init();
	void resize(int);
	static const int defSize = 8; // tweak as required
};

// constructors and Destructor
template<typename T>
Vector<T>::Vector() {
	mSize = defSize;
	init();
}
template<typename T>
Vector<T>::~Vector() {
	free(vStart);
}

// public methods
template<typename T>
size_t Vector<T>::size() {
	return top;
}
template<typename T>
void Vector<T>::push_back(const T t) {
	if (top == mSize) {
		int inc = mSize + (log(mSize) / log(2));
		resize(inc);
		if (mSize < inc) {
			return;
		}
	}
	memcpy((vStart + top++), &t, tSize); // increments top after memcpy()
}

// private methods follow
template<typename T>
void Vector<T>::resize(int newSize) {
	void* newStart = realloc(vStart, tSize * newSize);
	if (newStart) {
		vStart = (T*)newStart;
		mSize = newSize;
	}
}
template<typename T>
void Vector<T>::init() {
	tSize = sizeof(T);
	vStart = (T*)malloc(tSize * mSize);
	if (!vStart) {
		mSize = 0;
	}
	top = 0;
}
