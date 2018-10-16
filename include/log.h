#ifndef LOG_H_CONRAD
#define LOG_H_CONRAD

#include <algorithm>
#include <iostream>

extern int conrad__indent_level;

inline void log_popIndentLevel() {
  if (conrad__indent_level > 0) conrad__indent_level--;
}

template <typename T>
inline void log_heading(const T& t) {
  std::cout << std::endl << t << std::endl << std::endl;
}

template <typename T>
inline void log(const T& t) {
  for (auto i = 0; i < conrad__indent_level; i++) std::cout << "\t";
  std::cout << t << std::endl;
}

template <typename T>
inline void log_indentNext(const T& t) {
  log(t);
  conrad__indent_level++;
}

#endif