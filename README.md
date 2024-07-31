# StringView

Implementation of StringView class with methods:
1) Default constructor (nullptr string).
2) Constructor from const char* (with length calculation).
3) Constructor from const char* and size_t (length is passed as second parameter).
4) Operation [].
5) At method (if you go out of bounds, it throws StringViewOutOfRange exception, which is written for you).
6) Front() and Back() methods, which return the first and last character of the string, respectively.
7) The Size() and Length() methods, which return the length of the string.
8) Empty() method that checks the string for emptiness.
9) The Data() method returns a pointer to the beginning of the string.
10) Swap(StringView&) method.
11) RemovePrefix(size_t prefix_size) method, which shifts the beginning of the string by prefix_size.
12) The RemoveSuffix(size_t suffix_size) method, which shifts the end of the string by suffix_size.
13) Substr(size_t pos, size_t count = -1) method, which forms a StringView object from the calling StringView object into a substring with start pos and length min(count, Size() - pos) (if pos goes out of bounds, it throws StringViewOutOfRange).
