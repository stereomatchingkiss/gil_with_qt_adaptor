/*
    Copyright 2008 stereomatching
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef IMAGE_VIEW_TYPEDEF_HPP
#define IMAGE_VIEW_TYPEDEF_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author stereomatching \n
///
/// \date 2008 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <cstdint>

#include <boost/gil/packed_pixel.hpp>
#include <boost/gil/typedefs.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>

namespace boost{ namespace gil { namespace qt {

typedef bit_aligned_image1_type<1, gray_layout_t>::type gray1_image_t;
typedef gray1_image_t::view_t gray1_view_t;

typedef packed_pixel_type<bits16, boost::mpl::vector3_c<unsigned, 5, 6, 5>, bgr_layout_t>::type rgb565_pixel_t;
typedef image<rgb565_pixel_t, false> rgb565_image_t;
typedef rgb565_image_t::view_t rgb565_view_t;
typedef rgb565_image_t::const_view_t rgb565c_view_t;

typedef packed_pixel_type<bits16, boost::mpl::vector3_c<unsigned, 6, 5, 5>, rgb_layout_t>::type rgb655_pixel_t;
typedef image<rgb655_pixel_t, false> rgb655_image_t;
typedef rgb655_image_t::view_t rgb655_view_t;
typedef rgb655_image_t::const_view_t rgb655c_view_t;

typedef packed_pixel_type<bits16, boost::mpl::vector4_c<unsigned, 4, 4, 4, 4>, bgr_layout_t>::type bgra4444_pixel_t;
typedef image<bgra4444_pixel_t, false> bgra4444_image_t;
typedef rgb565_image_t::view_t bgra4444_view_t;
typedef rgb565_image_t::const_view_t bgra4444c_view_t;

typedef boost::mpl::vector<gray8_view_t, bgra8_view_t, rgb8_view_t> qt_view_lazy;
typedef boost::mpl::vector<gray8c_view_t, bgra8c_view_t, rgb8c_view_t> qt_c_view_lazy;

} // namespace opencv
} // namespace gil
} // namespace boost

#endif // IMAGE_VIEW_TYPEDEF_HPP
