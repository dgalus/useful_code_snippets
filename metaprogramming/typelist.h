#ifndef TYPELIST_H_
#define TYPELIST_H_

struct EmptyType {};
class NullType {};

template <class T, class U>
struct Typelist
{
    typedef T Head;
    typedef U Tail;
};

#define TYPELIST_1(T1) Typelist<T1, NullType>
#define TYPELIST_2(T1, T2) Typelist<T1, TYPELIST_1(T2)>
#define TYPELIST_3(T1, T2, T3) Typelist<T1, TYPELIST_2(T2, T3)>
#define TYPELIST_4(T1, T2, T3, T4) Typelist<T1, TYPELIST_3(T2, T3, T4)>

template <class TList> struct Length;
template <> struct Length<NullType>
{
    enum { value = 0 };
};
template <class T, class U>
struct Length<Typelist<T, U>>
{
    enum { value = 1 + Length<U>::value };
};

template <class Head, class Tail>
struct TypeAt<Typelist<Head, Tail>, 0>
{
    typedef Head Result;
};
template <class Head, class Tail, unsigned int i>
struct TypeAt<Typelist<Head, Tail>, i>
{
    typedef typename TypeAt<Tail, i-1>::Result Result;
};

template <class TList, class T> struct IndexOf;
template <class T>
struct IndexOf<NullType, T>
{
    enum { value = -1 };
};
template <class T, class Tail>
struct IndexOf<Typelist<T, Tail>, T>
{
    enum { value = 0 };
};
template <class Head, class Tail, class T>
struct IndexOf<Typelist<Head, Tail>, T>
{
private:
    enum { temp = IndexOf<Tail, T>::value };
public:
    enum { value = temp == -1 ? -1 : 1 + temp };
};

template <class TList, class T> struct Append;
template <> struct Append<NullType, NullType>
{
    typedef NullType Result;
};
template <class T> struct Append<NullType, T>
{
    typedef TYPELIST_1(T) Result;
};
template <class Head, class Tail>
struct Append<NullType, Typelist<Head, Tail>>
{
    typedef Typelist<Head, Tail> Result;
};
template <class Head, class Tail, class T>
struct Append<Typelist<Head, Tail>, T>
{
    typedef Typelist<Head, typename Append<Tail, T>::Result> Result;
};

/** Usage:
* typedef TypeList<char, Typelist<signed char, Typelist<unsigned char, NullType>>> CharList;
* 
* 
* typedef TYPELIST_4(signed char, short int, int, long int) SignedIntegrals;
* 
*/

#endif
