// On windows this disables warnings about using fopen_s instead of fopen
// It must be defined before including the headers.
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

// TODO C: Consider using *_s versions of standard lib functions

// -----------------------------------------------------------------------------
// C++ Compatibility
// -----------------------------------------------------------------------------
// This section defines things that make C++ behave more like C so we can make
// the transition to C.
#ifdef __cplusplus

// Use `_Bool` as the native bool type
#define _Bool bool

// This type is used to emulate C style void pointers in C++. That is, they
// implictly convert to/from other pointer types.
class void_ptr
{
private:
    void *_Nullable ptr;
public:
    template<class T>
    void_ptr(T *_Nullable value) : ptr((void *_Nullable)value) {}
    template<class T>
    operator T *_Nullable() const { return (T *)ptr; }

    _Bool operator==(void_ptr rhs) const { return ptr == rhs.ptr; }
    template<class T>
    _Bool operator==(T *_Nullable rhs) const { return ptr == rhs; }

    _Bool operator!=(void_ptr rhs) const { return ptr != rhs.ptr; }
    template<class T>
    _Bool operator!=(T *_Nullable rhs) const { return ptr != rhs; }
};

#else

#define void_ptr void*_Nullable

#endif

// -----------------------------------------------------------------------------
// Library Utils
// -----------------------------------------------------------------------------

#define lib_assert(condition) lib_assert1(condition, #condition)
void lib_assert1(const _Bool condition, char const *_Nonnull code);
#define lib_assert_msg(condition, message) lib_assert2(condition, #condition, message)
void lib_assert2(const _Bool condition, char const *_Nonnull code, char const *_Nonnull message);

inline void_ptr allocate(size_t bytes)
{
    return malloc(bytes);
}

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

typedef struct never never;
typedef struct optional__never optional__never;
typedef struct BOOL BOOL;
typedef struct int32 int32;
typedef struct byte byte;
typedef struct code_point code_point;
typedef struct string string;

// `never` type
struct never
{
};

// `never?` type
struct optional__never
{
};

// TODO this is a hack for now, the type of `none` should be `never?`
static const void_ptr none = (void*)0;

// For now, use `BOOL` as the emitted type
// TODO C: switch `BOOL` to `bool`
// TODO C: switch `TRUE` to `true`
// TODO C: switch `FALSE` to `false`

// `bool` type
struct BOOL
{
    _Bool value;
};

static const BOOL TRUE = { 1 };
static const BOOL FALSE = { 0 };

// Function used in conditions to make them take `bool`
inline _Bool cond(BOOL cond) { return cond.value; }

// Used by runtime for converting to bool
inline BOOL bool_from(_Bool b) { return (BOOL){ b }; }

// Wrap a bool operation that is bool based
inline BOOL bool_op(_Bool b) { return (BOOL){ b }; }
// Convert the arguments of a logical operation to bool
inline _Bool bool_arg(BOOL b) { return b.value; }

inline BOOL BOOL__0op__not(BOOL b) { return (BOOL){ !b.value }; }

string bool_to_string__1(BOOL b);

// `int` type
struct int32
{
    int32_t value;
};

inline void op__add_assign(int32*_Nonnull lhs, int32 rhs) { lhs->value += rhs.value; }
inline void op__sub_assign(int32*_Nonnull lhs, int32 rhs) { lhs->value -= rhs.value; }
inline int32 int32__0op__neg(int32 v) { return (int32){-v.value}; }
inline int32 int32__0op__add(int32 lhs, int32 rhs) { return (int32){ lhs.value + rhs.value}; }
inline int32 int32__0op__sub(int32 lhs, int32 rhs) { return (int32){ lhs.value - rhs.value}; }
inline int32 int32__0op__mul(int32 lhs, int32 rhs) { return (int32){ lhs.value * rhs.value}; }
inline int32 int32__0op__div(int32 lhs, int32 rhs) { return (int32){ lhs.value / rhs.value}; }
inline int32 int32__0op__remainder(int32 lhs, int32 rhs) { return (int32){ lhs.value % rhs.value}; }
inline BOOL int32__0op__lt(int32 lhs, int32 rhs) { return bool_from(lhs.value < rhs.value); }
inline BOOL int32__0op__lte(int32 lhs, int32 rhs) { return bool_from(lhs.value <= rhs.value); }
inline BOOL int32__0op__gt(int32 lhs, int32 rhs) { return bool_from(lhs.value > rhs.value); }
inline BOOL int32__0op__gte(int32 lhs, int32 rhs) { return bool_from(lhs.value >= rhs.value); }

string int_to_string__1(int32 i);
string int_to_hex_string__1(int32 i);
int32 hex_string_to_int__1(string s);
code_point int_to_code_point__1(int32 i);

struct byte
{
    uint8_t value;
};

struct code_point
{
    // don't use something like char32_t because C's handling of chars sucks
    uint32_t value;
};

inline BOOL code_point__0op__lt(code_point lhs, code_point rhs) { return bool_from(lhs.value < rhs.value); }
inline BOOL code_point__0op__lte(code_point lhs, code_point rhs) { return bool_from(lhs.value <= rhs.value); }
inline BOOL code_point__0op__gt(code_point lhs, code_point rhs) { return bool_from(lhs.value > rhs.value); }
inline BOOL code_point__0op__gte(code_point lhs, code_point rhs) { return bool_from(lhs.value >= rhs.value); }

inline int32 code_point_as_int__1(code_point c) { return (int32){(int32_t)c.value}; }
string code_point_to_string__1(code_point c);

struct string
{
    int32 byte_length; // TODO rename to just byte_length, though there will be a byte_length
    // property in the future, it doesn't make sense to directly expose it right now because this is
    // not the correct implementation.

    // don't use chars because C's handling of chars sucks
    uint8_t const *_Nonnull Buffer; // TODO use byte and rename to `bytes`
};

string string__0new__0();
string string__0new__1(string value);
string string__0new__2(code_point c, int32 repeat);

string string__0op__add(string lhs, string rhs);
BOOL string__0op__lt(string lhs, string rhs);
BOOL string__0op__lte(string lhs, string rhs);
BOOL string__0op__gt(string lhs, string rhs);
BOOL string__0op__gte(string lhs, string rhs);
inline code_point string__0__0op__element(string value, int32 index)
{
    lib_assert(index.value >= 0 && index.value < value.byte_length.value);
    return (code_point){value.Buffer[index.value]};
}

inline int32 string_byte_length__1(string s) { return s.byte_length; }
string substring__3(string s, int32 start, int32 length);
inline string substring__2(string s, int32 start) { return substring__3(s, start, (int32){s.byte_length.value-start.value}); }
string string_replace__3(string s, string old_value, string new_value);
int32 string_index_of__2(string s, code_point c);
int32 string_last_index_of__2(string s, code_point c);

// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

inline BOOL BOOL__0op__equal(BOOL lhs, BOOL rhs)
{
    return bool_from(lhs.value == rhs.value);
}
inline BOOL int32__0op__equal(int32 lhs, int32 rhs)
{
    return bool_from(lhs.value == rhs.value);
}
inline BOOL code_point__0op__equal(code_point lhs, code_point rhs)
{
    return bool_from(lhs.value == rhs.value);
}
BOOL string__0op__equal(string lhs, string rhs);
// TODO this currently exists becuase of the compare `none`, it shouldn't exist
inline BOOL never__0op__equal(void_ptr lhs, void_ptr rhs)
{
    return bool_from(lhs == rhs);
}
inline BOOL void_ptr__0op__equal(void_ptr lhs, void_ptr rhs)
{
    return bool_from(lhs == rhs);
}

inline BOOL BOOL__0op__not_equal(BOOL lhs, BOOL rhs)
{
    return bool_from(lhs.value != rhs.value);
}
inline BOOL int32__0op__not_equal(int32 lhs, int32 rhs)
{
    return bool_from(lhs.value != rhs.value);
}
inline BOOL code_point__0op__not_equal(code_point lhs, code_point rhs)
{
    return bool_from(lhs.value != rhs.value);
}
inline BOOL string__0op__not_equal(string lhs, string rhs)
{
    return BOOL__0op__not(string__0op__equal(lhs, rhs));
}
// TODO this currently exists becuase of the compare `none`, it shouldn't exist
inline BOOL never__0op__not_equal(void_ptr lhs, void_ptr rhs)
{
    return bool_from(lhs != rhs);
}
inline BOOL void_ptr__0op__not_equal(void_ptr lhs, void_ptr rhs)
{
    return bool_from(lhs != rhs);
}

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------
// Parts of the standard library that are currently implemented in the runtime.

typedef struct string__0iter string__0iter;
typedef struct Strings__0 Strings__0;
typedef struct int__0iter int__0iter;
typedef struct Ints__0 Ints__0;
typedef struct void_ptr__0iter void_ptr__0iter;

inline void_ptr allocate__1(int32 bytes)
{
    return malloc(bytes.value);
}

inline void free__1(void_ptr object)
{
    free(object);
}

#define assert__1(condition) assert1(condition, #condition, __FILE__, __LINE__)
#define assert__2(condition, message) assert2(condition, #condition, message, __FILE__, __LINE__)
void assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line);
void assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line);

#define NOT_IMPLEMENTED__0() NOT_IMPLEMENTED0(__func__, __FILE__, __LINE__)
#define NOT_IMPLEMENTED__1(message) NOT_IMPLEMENTED1(message, __func__, __FILE__, __LINE__)
_Noreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);
_Noreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line);

#define UNREACHABLE__0() UNREACHABLE(__func__, __FILE__, __LINE__)
_Noreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);

string get_resource__1(string resource_name);
void add_resource(string name, string value);

void debug_write__1(string value);
void debug_write_line__1(string value);
void debug_write_line__0();

struct string__0iter
{
    string *_Nonnull values;
    int32_t current;
    int32_t count;

    // For now, allow implicit coversion from list iterator to string iterator
    string__0iter(void_ptr__0iter iter);
    string__0iter(string *_Nonnull values, int32_t current, int32_t count)
        : values(values), current(current), count(count) {}
};

bool string__0next(string__0iter*_Nonnull iter);
inline string string__0current(string__0iter const*_Nonnull iter)
{
    lib_assert(iter->current >= 0 && iter->current < iter->count);
    return iter->values[iter->current];
}

struct Strings__0
{
    string *_Nonnull values;
    int32 count__;
    int32 capacity__;
};

Strings__0 *_Nonnull Strings__0__0new__0(Strings__0 *_Nonnull self);
inline string Strings__0__0op__element(Strings__0 const*_Nonnull strings, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < strings->count__.value);
    return strings->values[index.value];
}
inline void clear_strings__1(Strings__0 *_Nonnull strings)
{
    strings->count__ = {0};
}
void add_string__2(Strings__0 *_Nonnull strings, string value);
inline string__0iter Strings__0__0iterate(Strings__0 *_Nonnull strings)
{
    return string__0iter(strings->values, -1, strings->count__.value);
    // {
    //     .values = strings->values,
    //     .current = -1,
    //     .count = strings->count__.value
    // };
}

struct int__0iter
{
    int32 *_Nonnull values;
    int32_t current;
    int32_t count;
};

bool int__0next(int__0iter*_Nonnull iter);
inline int32 int__0current(int__0iter const*_Nonnull iter)
{
    lib_assert(iter->current >= 0 && iter->current < iter->count);
    return iter->values[iter->current];
}

struct Ints__0
{
    int32 *_Nonnull values;
    int32 count__;
    int32 capacity__;
};

Ints__0 *_Nonnull Ints__0__0new__0(Ints__0 *_Nonnull self);
inline int32 Ints__0__0op__element(Ints__0 const*_Nonnull ints, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < ints->count__.value);
    return ints->values[index.value];
}
inline void clear_ints__1(Ints__0 *_Nonnull ints)
{
    ints->count__ = {0};
}
void add_int__2(Ints__0 *_Nonnull ints, string value);
inline int__0iter Strings__0__0iterate(Ints__0 *_Nonnull ints)
{
    return int__0iter
    {
        .values = ints->values,
        .current = -1,
        .count = ints->count__.value
    };
}

struct void_ptr__0iter
{
    void_ptr *_Nonnull values;
    int32_t current;
    int32_t count;
};

bool void_ptr__0next(void_ptr__0iter*_Nonnull iter);
inline void_ptr void_ptr__0current(void_ptr__0iter const*_Nonnull iter)
{
    lib_assert(iter->current >= 0 && iter->current < iter->count);
    return iter->values[iter->current];
}

// For now, allow implicit coversion from list iterator to string iterator
inline string__0iter::string__0iter(void_ptr__0iter iter)
    : values((string *_Nonnull)iter.values), current(iter.current), count(iter.count)
{
}

template<typename T>
struct system__collections__List__1
{
    T *_Nonnull values;
    int32 count__;
    int32 capacity__;

    // Adamant Members
    void add__1(T value);
    void clear__0() { count__ = {0}; }
};

template<typename T>
void system__collections__List__1<T>::add__1(T value)
{
    if(count__.value >= capacity__.value)
    {
        int32_t newCapacity = capacity__.value == 0 ? 16 : capacity__.value * 2;
        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)
        // Needed if T is a value type to avoid needing a default constructor
        T* newValues = (T*)new char[newCapacity * sizeof(T)];
        memcpy(newValues, values, count__.value * sizeof(T));
        if(capacity__.value != 0)
            delete[] values; // delete the old array
        values = newValues;
        capacity__ = (int32){newCapacity};
    }
    values[count__.value] = value;
    count__.value++;
}

template<typename T>
T system__collections__List__1__0op__element(system__collections__List__1<T> const*_Nonnull list, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < list->count__.value);
    return list->values[index.value];
}

template<typename T>
system__collections__List__1<T> *_Nonnull system__collections__List__1__0new__0(system__collections__List__1<T> *_Nonnull self)
{
    self->values = NULL;
    self->count__ = {0};
    self->capacity__ = {0};
    return self;
}

template<typename T>
void_ptr__0iter system__collections__List__1__0iterate(system__collections__List__1<T> const *_Nonnull list)
{
    return (void_ptr__0iter)
    {
        .values = (void_ptr*_Nonnull)list->values, // force cast could be bad if T is not a pointer
        .current = -1,
        .count = list->count__.value
    };
}

template<typename T>
void_ptr__0iter void_ptr__0iterate(system__collections__List__1<T> const *_Nonnull list)
{
    return (void_ptr__0iter)
    {
        .values = (void_ptr*_Nonnull)list->values, // force cast could be bad if T is not a pointer
        .current = -1,
        .count = list->count__.value
    };
}

inline string__0iter string__0iterate(system__collections__List__1<string> const *_Nonnull list)
{
    return string__0iter(list->values, -1, list->count__.value);
    // {
    //     .values = (void_ptr*_Nonnull)list->values, // force cast could be bad if T is not a pointer
    //     .current = -1,
    //     .count = list->count__.value
    // };
}

class system__console__Console__0
{
public:
    void Write__1(string value);
    void WriteLine__1(string value);
    void WriteLine__0();
};

struct system__console__Arguments__0
{
    string *_Nonnull values;

    system__console__Arguments__0(int argc, char const *_Nonnull const *_Nonnull argv);

    const int Count;

    // Adamant Members
    int32 op__magnitude() const { return (int32){Count}; }
};

inline string system__console__Arguments__0__0op__element(system__console__Arguments__0 const*_Nonnull arguments, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < arguments->Count);
    return arguments->values[index.value];
}

inline string__0iter system__console__Arguments__0__0iterate(system__console__Arguments__0 const*_Nonnull arguments)
{
    return string__0iter(arguments->values, -1, arguments->Count);
    // {
    //     .values = arguments->values,
    //     .current = -1,
    //     .count = arguments->Count
    // };
}

struct system__io__File_Reader__0
{
    FILE *_Nonnull file;

    string ReadToEndSync__0();
    void Close__0();
};

system__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, const string& fileName);

struct system__io__File_Writer__0
{
    FILE *_Nonnull file;

    void Write__1(const string& value);
    void Close__0();
};

system__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, const string& fileName);

struct system__text__String_Builder__0
{
    uint8_t *_Nullable buffer;
    int capacity;
    int length;
    void ensure_capacity(int needed);

    // Adamant Members
    // TODO byte_length should be a property
    int32 byte_length__0() const { return (int32){length}; }
    void Append__1(string const & value);
    void Append__1(system__text__String_Builder__0 const *_Nonnull value);
    void AppendLine__1(string const& value);
    void AppendLine__0();
    void Remove__2(int32 start, int32 length);
    void Remove__1(int32 start);
    string ToString__0();
};

inline system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__0(system__text__String_Builder__0 *_Nonnull self)
{
    self->buffer = 0;
    self->capacity = 0;
    self->length = 0;
    return self;
}

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string const & value);
system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity);
