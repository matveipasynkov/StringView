#include "string_view.h"
#include <algorithm>

StringView::StringView() {
  start_ = nullptr;
  size_ = 0;
}

StringView::StringView(const char* symbols_pointer) {
  start_ = symbols_pointer;
  while (*(start_ + size_) != 0) {
    ++size_;
  }
}

StringView::StringView(const char* pointer, size_t size) {
  start_ = pointer;
  size_ = size;
}

char StringView::operator[](size_t index) const {
  return *(start_ + index);
}

char StringView::At(size_t index) const {
  if (index < size_) {
    return *(start_ + index);
  }
  throw StringViewOutOfRange{};
}

char StringView::Front() const {
  return *start_;
}

char StringView::Back() const {
  return *(start_ + size_ - 1);
}

size_t StringView::Length() const {
  return size_;
}

size_t StringView::Size() const {
  return size_;
}

bool StringView::Empty() const {
  return size_ == 0;
}

const char* StringView::Data() const {
  return start_;
}

StringView& StringView::Swap(StringView& other) {
  const char* tmp_pointer = other.start_;
  size_t tmp_size = other.size_;
  other.start_ = start_;
  other.size_ = size_;
  start_ = tmp_pointer;
  size_ = tmp_size;
  return *this;
}

StringView& StringView::RemovePrefix(size_t prefix_size) {
  start_ += prefix_size;
  size_ -= prefix_size;
  return *this;
}

StringView& StringView::RemoveSuffix(size_t suffix_size) {
  size_ -= suffix_size;
  return *this;
}

StringView StringView::Substr(size_t pos, size_t count = -1) {
  if (pos < size_) {
    return {start_ + pos, std::min(count, size_-pos)};
  }
  throw StringViewOutOfRange{};
}
