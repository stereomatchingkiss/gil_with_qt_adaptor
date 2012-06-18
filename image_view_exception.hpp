/*
    Copyright 2012 stereomatching
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef IMAGE_VIEW_EXCEPTION_HPP
#define IMAGE_VIEW_EXCEPTION_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author stereomatching \n
///
/// \date 2012 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <exception>

namespace boost{ namespace gil { namespace qt {

class qt_image_view_exception : public std::exception
{
  public :
    qt_image_view_exception () throw() : std::exception() {}
    qt_image_view_exception (qt_image_view_exception const&) throw() {}
    qt_image_view_exception& operator= (qt_image_view_exception const &data) throw()
    { return *this; }
    virtual ~qt_image_view_exception() throw() {}
    virtual char const *what() const throw()
    {
        return "this is an invalid type\n";
    }
};

} // namespace qt
} // namespace gil
} // namespace boost

#endif // IMAGE_IVIEW_EXCEPTION_HPP
