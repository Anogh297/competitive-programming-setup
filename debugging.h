#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T> std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
	if (vec.empty()) {
		out << "[]";
		return out;
	}
	out << "[";
	for (size_t i = 0; i < vec.size() - 1; i++) {
		out << vec[i] << ", ";
	}
	return out << vec.back() << "]";
}

template <typename T1, typename T2> std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
	return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T> std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq) {
	if (deq.empty()) {
		out << "[]";
		return out;
	}
	out << "[";
	for (size_t i = 0; i < deq.size() - 1; i++) {
		out << deq[i] << ", ";
	}
	return out << deq.back() << "]";
}

template <typename T1, typename T2> std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& map) {
	out << "{ ";
	for (auto it = map.begin(); it != map.end(); it++) {
		std::pair<T1, T2> element = *it;
		out << element.first << ": " << element.second;
		if (std::next(it) != map.end()) {
			out << ", ";
		}
	}
	return out << " }";
}

template <typename T1, typename T2> std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& map) {
	out << "{ " << '\n';
	for (auto it = map.begin(); it != map.end(); it++) {
		std::pair<T1, T2> element = *it;
		out << "  " << element.first << ": " << element.second;
		if (std::next(it) != map.end()) {
			out << ",\n";
		}
	}

	return out << '\n' << '}';
}

template <typename T> std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set) {
	out << "{ ";
	for (auto it = set.begin(); it != set.end(); it++) {
		T element = *it;
		out << element;
		if (std::next(it) != set.end()) {
			out << ", ";
		}
	}
	return out << " }";
}

template <typename T> std::ostream& operator<<(std::ostream& out, const std::multiset<T>& set) {
	out << "{ ";
	for (auto it = set.begin(); it != set.end(); it++) {
		T element = *it;
		out << element;
		if (std::next(it) != set.end()) {
			out << ", ";
		}
	}
	return out << " }";
}

template <typename T> std::ostream& operator<<(std::ostream& out, const std::unordered_multiset<T>& set) {
	out << "{ ";
	for (auto it = set.begin(); it != set.end(); it++) {
		T element = *it;
		out << element;
		if (std::next(it) != set.end()) {
			out << ", ";
		}
	}
	return out << " }";
}

template <typename T> std::ostream& operator<<(std::ostream& out, const std::set<T>& set) {
	out << "{ ";
	for (auto it = set.begin(); it != set.end(); it++) {
		T element = *it;
		out << element;
		if (std::next(it) != set.end()) {
			out << ", ";
		}
	}
	return out << " }";
}

template <typename Type, unsigned N, unsigned Last> struct TuplePrinter {
	static void print(std::ostream& out, const Type& value) {
		out << std::get<N>(value) << ", ";
		TuplePrinter<Type, N + 1, Last>::print(out, value);
	}
};

template <typename Type, unsigned N> struct TuplePrinter<Type, N, N> {
	static void print(std::ostream& out, const Type& value) { out << std::get<N>(value); }
};

template <typename... Types> std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value) {
	out << '(';
	TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
	return out << ')';
}

template <typename T> std::ostream& operator<<(std::ostream& out, std::stack<T> stack) {
	std::vector<T> elements;
	while (!stack.empty()) {
		elements.push_back(stack.top());
		stack.pop();
	}
	std::reverse(elements.begin(), elements.end());
	out << "[";
	for (size_t i = 0; i < elements.size(); ++i) {
		out << elements[i];
		if (i != elements.size() - 1) {
			out << ", ";
		}
	}
	return out << "]";
}

template <typename T> std::ostream& operator<<(std::ostream& out, std::queue<T> queue) {
	out << "[";
	while (!queue.empty()) {
		out << queue.front();
		queue.pop();
		if (!queue.empty()) {
			out << ", ";
		}
	}
	return out << "]";
}