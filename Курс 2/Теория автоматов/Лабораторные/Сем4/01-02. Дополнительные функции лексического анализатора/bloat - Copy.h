// xstring internal header

// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef _XSTRING_
#define _XSTRING_
#include <yvals_core.h>
#if _STL_COMPILER_PREPROCESSOR
#include <__msvc_sanitizer_annotate_container.hpp>
#include <__msvc_string_view.hpp>
#include <iosfwd>
#include <xmemory>

#if _HAS_CXX17
#include <xpolymorphic_allocator.h>
#endif // _HAS_CXX17

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

_STD_BEGIN
template <class _Mystr>
class _String_const_iterator : public _Iterator_base {
public:
#if _HAS_CXX20
    using iterator_concept = contiguous_iterator_tag;
#endif // _HAS_CXX20
    using iterator_category = random_access_iterator_tag;
    using value_type        = typename _Mystr::value_type;
    using difference_type   = typename _Mystr::difference_type;
    using pointer           = typename _Mystr::const_pointer;
    using reference         = const value_type&;

    _CONSTEXPR20 _String_const_iterator() noexcept : _Ptr() {}

    _CONSTEXPR20 _String_const_iterator(pointer _Parg, const _Container_base* _Pstring) noexcept : _Ptr(_Parg) {
        this->_Adopt(_Pstring);
    }

    _NODISCARD _CONSTEXPR20 reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL >= 1
        _STL_VERIFY(_Ptr, "cannot dereference value-initialized string iterator");
        const auto _Mycont = static_cast<const _Mystr*>(this->_Getcont());
        _STL_VERIFY(_Mycont, "cannot dereference string iterator because the iterator was "
                             "invalidated (e.g. reallocation occurred, or the string was destroyed)");
        const auto _Contptr = _Mycont->_Myptr();
        const auto _Rawptr  = _Unfancy(_Ptr);
        _STL_VERIFY(_Contptr <= _Rawptr && _Rawptr < _Contptr + _Mycont->_Mysize,
            "cannot dereference string iterator because it is out of range (e.g. an end iterator)");
#endif // _ITERATOR_DEBUG_LEVEL >= 1

        _Analysis_assume_(_Ptr);
        return *_Ptr;
    }

    _NODISCARD _CONSTEXPR20 pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _CONSTEXPR20 _String_const_iterator& operator++() noexcept {
#if _ITERATOR_DEBUG_LEVEL >= 1
        _STL_VERIFY(_Ptr, "cannot increment value-initialized string iterator");
        const auto _Mycont = static_cast<const _Mystr*>(this->_Getcont());
        _STL_VERIFY(_Mycont, "cannot increment string iterator because the iterator was "
                             "invalidated (e.g. reallocation occurred, or the string was destroyed)");
        _STL_VERIFY(_Unfancy(_Ptr) < _Mycont->_Myptr() + _Mycont->_Mysize, "cannot increment string iterator past end");
#endif // _ITERATOR_DEBUG_LEVEL >= 1

        ++_Ptr;
        return *this;
    }

    _CONSTEXPR20 _String_const_iterator operator++(int) noexcept {
        _String_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _CONSTEXPR20 _String_const_iterator& operator--() noexcept {
#if _ITERATOR_DEBUG_LEVEL >= 1
        _STL_VERIFY(_Ptr, "cannot decrement value-initialized string iterator");
        const auto _Mycont = static_cast<const _Mystr*>(this->_Getcont());
        _STL_VERIFY(_Mycont, "cannot decrement string iterator because the iterator was "
                             "invalidated (e.g. reallocation occurred, or the string was destroyed)");
        _STL_VERIFY(_Mycont->_Myptr() < _Unfancy(_Ptr), "cannot decrement string iterator before begin");
#endif // _ITERATOR_DEBUG_LEVEL >= 1

        --_Ptr;
        return *this;
    }

    _CONSTEXPR20 _String_const_iterator operator--(int) noexcept {
        _String_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }
