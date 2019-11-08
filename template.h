#ifndef TEMPLATES_H
#define TEMPLATES_H 1

#include <type_traits>
#include <tuple>
#include "point.h"
#include "rhombus.h"
#include "trapezoid.h"
#include "rectangle.h"



template <class T>
struct is_point : std::false_type {};

template <class T>
struct is_point<TPoint <T>> : std::true_type {};

template <class T>
struct is_figure_like_tuple : std::false_type {};

template <class Head, class ... Tail>
struct is_figure_like_tuple <std::tuple<Head, Tail ... >> : 
	std::conjunction <is_point<Head>, std::is_same<Head, Tail> ...> {};

template <class Type, size_t size>
struct is_figure_like_tuple <std::array<Type, size>> : is_point<Type> {};

template <class T>
inline constexpr bool is_figure_like_tuple_v = is_figure_like_tuple<T>::value;

template <class T, class = void >
struct has_print_method : std::false_type {};

template<class T>
struct has_print_method<T, std::void_t<decltype(std::declval<const T>().Print())>> :
    std::true_type {};

template<class T>
inline constexpr bool has_print_method_v = has_print_method<T>::value;

template<class T>
std::enable_if_t<has_print_method_v<T>, void>
    print(const T& figure) {
        figure.Print();
}



template<size_t ID, class T>
void single_print(const T& t) {
    std::cout << std::get<ID>(t);
    return ;
}

template<size_t ID, class T>
void recursive_print(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        single_print<ID>(t);
        recursive_print<ID+1>(t);
        return ;
    }
    return ;
}

template <class T>
std::enable_if_t <is_figure_like_tuple_v<T>, void>
	print(const T& fake) {
		return recursive_print<0>(fake);
	}


template<class T, class = void>
struct has_center_method : std::false_type {};

template<class T>
struct has_center_method<T,
        std::void_t<decltype(std::declval<const T>().Center())>> :
        std::true_type {};

template<class T>
inline constexpr bool has_center_method_v =
        has_center_method<T>::value;


template<class T>
std::enable_if_t<has_center_method_v<T>, TPoint<double>>
center(const T& figure) {
    return figure.Center();
}

template<class T>
inline constexpr const int tuple_size_v = std::tuple_size<T>::value;


template<size_t ID, class T>
TPoint<double> single_center(const T& t) {
    TPoint<double> p;
    p = std::get<ID>(t);
    p /= tuple_size_v<T>;
    return p;
}


template<size_t ID, class T>
TPoint<double> recursive_center(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        return single_center<ID>(t) + recursive_center<ID+1>(t);
    }else{
        TPoint<double> p(0, 0);
        
        return p;
    }
}

template<class T>
std::enable_if_t<is_figure_like_tuple_v<T>, TPoint<double>>
center(const T& fake) {
    return recursive_center<0>(fake);
}


template <class T, class = void>
struct has_square_method : std::false_type {};

template <class T>
struct has_square_method <T, std::void_t <decltype(std::declval<const T> ().Square())>> : std::true_type{};

template <class T>
inline constexpr bool has_square_method_v = has_square_method<T>::value;

template <class T>
std::enable_if_t<has_center_method_v<T>, double>
Square(const T& figure) {
    return figure.Square();
}

template <size_t ID, class T>
double single_square(const T& t) {
	const auto& a = std::get<0> (t);
	const auto& b = std::get<ID - 1>(t);
	const auto& c = std::get<ID>(t);
	const double dx1 = b.x - a.x;
	const double dy1 = b.y - a.y;
	const double dx2 = c.x - a.x;
	const double dy2 = c.y - a.y;
	return std::abs(dx1 * dy2 - dy1 * dx2) * 0.5;
}

template <size_t ID, class T>
double recursive_square(const T& t) {
	if constexpr (ID < std::tuple_size_v<T>) {
		return single_square<ID>(t) + recursive_square<ID + 1>(t);
	} else {
		return 0;
	}
}

template <class T>
std::enable_if_t <is_figure_like_tuple_v<T>, double>
Square(const T& fake) {
	return recursive_square<2>(fake);
}




#endif