#ifndef CHARMAP_H_
#define CHARMAP_H_

#include <array>
#include <cstddef>
#include <memory>
#include <utility>

template <typename T, size_t m = 26>
class charmap {
 public:
  using value_type = std::pair<const char, T&>;
  using iterator = std::unique_ptr<value_type>;
 
  T& operator[](char c) {
    if (!count_[ord(c)]) {
      count_[ord(c)] = true;
      ++size_;
    }
    return map_[ord(c)];
  }
  
  bool erase(char c) {
    if (count_[ord(c)]) {
      count_[ord(c)] = false;
      --size_;
      return true;
    } else {      
      return false; 
    }
  }
  
  iterator find(char c) const {
    if (count_[ord(c)]) {
      return new value_type{c, map_[ord(c)]};
    } else {
      return end();
    }
  }

  const iterator end() const { return nullptr; }
  
  bool count(char c) const { return count_[ord(c)]; }
  size_t size() const { return size_; }
  
 private:
  static size_t ord(char c) { return c - 'a'; }
  static char chr(size_t i) { return 'a' + i; }

 private:
  std::array<T, m> map_;
  std::array<bool, m> count_;
  size_t size_ = 0;
};

#endif  // CHARMAP_H_
