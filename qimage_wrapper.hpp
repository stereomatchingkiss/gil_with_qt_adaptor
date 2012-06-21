/*
    Copyright 2012 stereomatching
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef QIMAGE_WRAPPER_HPP
#define QIMAGE_WRAPPER_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author stereomatching \n
///
/// \date 2012 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <boost/gil/image_view_factory.hpp>
#include <boost/gil/typedefs.hpp>

#include <boost/mpl/bool.hpp>

#include <QtGui/QImage>

#include "image_view_typedef.hpp"

namespace boost{ namespace gil { namespace qt {

/*
 * A compile time mapping table of the gil::view and QImage::Format
 */
template < typename View> struct qimage_channel_type : boost::mpl::false_ {};

template<> struct qimage_channel_type<boost::gil::gray8_view_t>
{
  static const QImage::Format format = QImage::Format_Indexed8;
  static int const depth = 8;
};

/*
 * There are three kind of QImage could be present by bgra8_view_t.
 * They are "QImage::Format_RGB32", "QImage::Format_ARGB32" and
 * "QImage::Format_ARGB32_Premultiplied".
 *
 * Now the qimage_channel_type only support "QImage::Format_ARGB32"
 * Other format will be supported after default template parameter
 * of function is supported by vc
 */
template<> struct qimage_channel_type<boost::gil::bgra8_view_t>
{
  static const QImage::Format format = QImage::Format_ARGB32;
  static int const depth = 32;
};

template<> struct qimage_channel_type<rgb565_view_t>
{
  static const QImage::Format format = QImage::Format_RGB16;
  static int const depth = 16;
};

template<> struct qimage_channel_type<rgb655_view_t>
{
  static const QImage::Format format = QImage::Format_RGB555;
  static int const depth = 16;
};

/*
 * There are three kind of QImage could be present by bgra8_view_t
 * they are "QImage::Format_ARGB444_Premultiplied" and "QImage::Format_RGB444".
 *
 * Now the qimage_channel_type only support "QImage::Format_RGB444"
 * Other format will be supported after default template parameter
 * of function is supported by vc
 */
template<> struct qimage_channel_type<bgra4444_view_t>
{
  static const QImage::Format format = QImage::Format_RGB444;
  static int const depth = 16;
};

/*
 * Create a shallow QImage from view, the QImage referenced by the view
 * must remain valid throughout the life of the QImage.You can make a
 * deep copy if concatenate with ".copy()".
 *
 * QImage is an implicit share object, so we don't need shared_ptr
 * to wrap it.
 *
 * When the View is "bgra8_view_t", the QImage will always be
 * QImage::Format_ARGB32.
 * When the View is "bgra4444_view_t", the QImage will always be
 * QImage::Format_RGB444.
 *
 * Other format will be supported after default template parameter
 * of function is supported by vc
 */
template<typename View>
inline QImage const create_qimage( View const &view )
{
    namespace gil = boost::gil;
    typedef gil::qt::qimage_channel_type<View> ctype;
    return QImage(gil::interleaved_view_get_raw_data(view),
                  view.width(),
                  view.height(),
                  ((view.width() * ctype::depth + 31) / 32) * 4, //bytes per line
                  ctype::format);    
}

} // namespace qt
} // namespace gil
} // namespace boost

#endif // QIMAGE_WRAPPER_HPP
