/*
    Copyright 2008 stereomatching
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef IS_CONST_VIEW_HPP
#define IS_CONST_VIEW_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author stereomatching \n
///
/// \date 2008 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <boost/gil/typedefs.hpp>

#include <boost/mpl/bool.hpp>

namespace boost{ namespace gil {

/*
 * a type traits to determine the view should be const or mutable
 *
 * @param :
 *  View : the view of GIL you want to create
 */
template<typename View>
struct is_const_view
{
  typedef boost::mpl::false_ type;
};


#define GIL_DEFINE_IS_CONST_VIEW(VIEW)          \
template<>                                      \
struct is_const_view<boost::gil::VIEW##_view_t> \
{                                               \
  typedef boost::mpl::true_ type;               \
};

GIL_DEFINE_IS_CONST_VIEW(gray8c)
GIL_DEFINE_IS_CONST_VIEW(gray16c)
GIL_DEFINE_IS_CONST_VIEW(gray32c)
GIL_DEFINE_IS_CONST_VIEW(gray8sc)
GIL_DEFINE_IS_CONST_VIEW(gray16sc)
GIL_DEFINE_IS_CONST_VIEW(gray32sc)
GIL_DEFINE_IS_CONST_VIEW(gray32fc)

GIL_DEFINE_IS_CONST_VIEW(rgb8c)
GIL_DEFINE_IS_CONST_VIEW(rgb16c)
GIL_DEFINE_IS_CONST_VIEW(rgb32c)
GIL_DEFINE_IS_CONST_VIEW(rgb8sc)
GIL_DEFINE_IS_CONST_VIEW(rgb16sc)
GIL_DEFINE_IS_CONST_VIEW(rgb32sc)
GIL_DEFINE_IS_CONST_VIEW(rgb32fc)

GIL_DEFINE_IS_CONST_VIEW(rgba8c)
GIL_DEFINE_IS_CONST_VIEW(rgba16c)
GIL_DEFINE_IS_CONST_VIEW(rgba32c)
GIL_DEFINE_IS_CONST_VIEW(rgba8sc)
GIL_DEFINE_IS_CONST_VIEW(rgba16sc)
GIL_DEFINE_IS_CONST_VIEW(rgba32sc)
GIL_DEFINE_IS_CONST_VIEW(rgba32fc)

GIL_DEFINE_IS_CONST_VIEW(argb8c)
GIL_DEFINE_IS_CONST_VIEW(argb16c)
GIL_DEFINE_IS_CONST_VIEW(argb32c)
GIL_DEFINE_IS_CONST_VIEW(argb8sc)
GIL_DEFINE_IS_CONST_VIEW(argb16sc)
GIL_DEFINE_IS_CONST_VIEW(argb32sc)
GIL_DEFINE_IS_CONST_VIEW(argb32fc)

GIL_DEFINE_IS_CONST_VIEW(cmyk8c)
GIL_DEFINE_IS_CONST_VIEW(cmyk16c)
GIL_DEFINE_IS_CONST_VIEW(cmyk32c)
GIL_DEFINE_IS_CONST_VIEW(cmyk8sc)
GIL_DEFINE_IS_CONST_VIEW(cmyk16sc)
GIL_DEFINE_IS_CONST_VIEW(cmyk32sc)
GIL_DEFINE_IS_CONST_VIEW(cmyk32fc)

} // namespace opencv
} // namespace gil

#endif // // IS_CONST_VIEW_HPP
