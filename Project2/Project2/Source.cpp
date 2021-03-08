//
//class X {
//public:
//	int f=0;
//};
//
//class Y : public X {
//	Y() {
//		f = 4;
//	}
//	//X::f = 8;
//};
//
//void main() {
//}
////void main(){}
////
////
////
////
////
//class X {
//public:
//	int xxx;
//};
//
//class Y :  X {
//	int yy;
//public: 
//	Y() {
//		xxx = 4;
//	}
//};
//
//void main() {
//	Y y;
//	X x;	
//	x.xxx = 4;
//	//y.xxx = 5;
//
//}
//
//
////class X {
////public:
////	X() {}
////	X(int t) {}
////	//void f(int v) {}
////
////};
////
////void main() {
////	X x;
////	x = 5;
////}
//
////class X {
////public:
////	int x;
////	int *p;
////
////	X() : x(1), p(&x) {}
////	void g() const {
////	//	p = &x;
////		*p = 1;
////	}
////};
////
////void main() {
////	int b=3;
////	int & const a = b;
////}
//
//#include <iostream>
//template<int N>
//class X {
//public:
//	X() { ++d; }
//	static int d;
//};
//template<int N>
//int X<N>::d = 0;
//void main() {
//	X<3> a, b;
//	X<1> c;
//	std::cout << a.d << b.d << c.d;
//}

//class A { public: int x; };
//class B : public virtual A {};
//class C : public virtual A {};
//class D : public A {};
//class E : public B, public C, public D {};
//
//void main() {
//	E e;
//}
//template<typename T>
//class X {};
//void main() {
//	// X x;
//	// X x(int);
//	// X x<int>;
//	X<int>;
//	X<int> x;
//	//X<int> (x);
//}

//#include <iostream>
//class A {
//public:
//	A() {}
//	virtual void f() { std::cout << "A"; }
//};
//class B : public A {
//public:
//	void f() { std::cout << "B"; }
//};
//void g(A &a) { a.f(); }
//int main() {
//	B b;
//	g(b);
//}

//class A {};
//class B : public A {};
//void main() {
//	A a, *p;
//	B b, *q;
//	p = &b;
//	q = &a;
//	a = b;
//	//b = a;
//}

#include <iostream>
class A {
public:
	A(int) { std::cout << " A int "; }
	A() { std::cout << "A empty "; }
	virtual ~A() { std::cout << " destroy A"; }
};
class B : public A {
public:
	B(int) :A() { std::cout << "B int "; }
	B() { std::cout << "B empty "; }
	virtual ~B() { std::cout << " destroy B"; }
};
B b(3);
void main() {
	A a(3);
}