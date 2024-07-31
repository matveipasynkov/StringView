#ifndef H_MYSTRINGVIEW
#define H_MYSTRINGVIEW
#include <stdexcept>

class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
 private:
  const char* start_ = nullptr;
  size_t size_ = 0;
 public:
  StringView();
  StringView(const char*); // NOLINT
  StringView(const char*, size_t);
  char operator[](size_t index) const;
  char At(size_t index) const;
  char Front() const;
  char Back() const;
  size_t Size() const;
  size_t Length() const;
  bool Empty() const;
  const char* Data() const;
  StringView& Swap(StringView&);
  StringView& RemovePrefix(size_t);
  StringView& RemoveSuffix(size_t);
  StringView Substr(size_t, size_t);
};

#endif
