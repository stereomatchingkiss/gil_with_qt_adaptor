/*
    Copyright 2012 stereomatching
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef IVIEW_FACTORY_HPP
#define IVIEW_FACTORY_HPP

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

#include <boost/gil/extension/dynamic_image/any_image_view.hpp>

#include <QtGui/QImage>

#include "is_const_source.hpp"
#include "image_view_exception.hpp"
#include "image_view_typedef.hpp"

namespace boost{ namespace gil { namespace qt {

/*
 * Create the interleaved view of the GIL, you must specify the type you
 * want to create by the template parameter "View".
 *
 * @param :
 *  View : the view of GIL you want to create
 *  Image : the type of the image(ex : QImage of Qt)
 */
template<typename View, typename Source = QImage>
class qt_iview_factory;

template<typename View>
class qt_iview_factory<View, QImage const&>
{       
  public :
    static View const create_iview(QImage const &img)
    {
        typedef typename View::value_type pixel_type;
        return interleaved_view(img.width(), img.height(), (pixel_type*)img.constBits(),
                                img.bytesPerLine());
    }
};

template<typename View>
class qt_iview_factory<View, QImage&>
{    
  public :
    static View const create_iview(QImage &img)
    {
        typedef typename View::value_type pixel_type;
        return interleaved_view(img.width(), img.height(), (pixel_type*)img.bits(),
                                img.bytesPerLine());
    }
};

/*
 * easy function for qt_iview_factory
 */
template<typename View>
inline View const create_qt_iview(typename is_const_source<View, QImage>::type img)
{
    return qt_iview_factory<View, typename is_const_source<View, QImage>::type>::create_iview(img);
}

/*
 * easy function for creating those view which type is determined
 * at run time(do not support all of the format of the QImage yet)
 *
 * @exception
 *  will throw qt_image_view_exception(inherit std::exception)
 *  if it is an invalid format
 */
template<typename AnyView>
boost::gil::any_image_view<AnyView> const create_qt_iview_dy(QImage &img)
{
    using namespace boost::gil;

    switch(img.format())
    {
      case QImage::Format_Indexed8 :
        return any_image_view<AnyView>(create_qt_iview<gray8_view_t>(img));
        break;

      case QImage::Format_RGB32 :
        return any_image_view<AnyView>(create_qt_iview<bgra8_view_t>(img));
        break;

      case QImage::Format_ARGB32 :
        return any_image_view<AnyView>(create_qt_iview<bgra8_view_t>(img));
        break;     

      case QImage::Format_ARGB32_Premultiplied :
        return any_image_view<AnyView>(create_qt_iview<bgra8_view_t>(img));
        break;

      case QImage::Format_RGB16 :
        return any_image_view<AnyView>(create_qt_iview<rgb565_view_t>(img));
        break;

      case QImage::Format_RGB555 :
        return any_image_view<AnyView>(create_qt_iview<rgb655_view_t>(img));
        break;

      case QImage::Format_RGB444 :
        return any_image_view<AnyView>(create_qt_iview<bgra4444_view_t>(img));
        break;

      case QImage::Format_ARGB4444_Premultiplied :
        return any_image_view<AnyView>(create_qt_iview<bgra4444_view_t>(img));
        break;

      case QImage::Format_Invalid :
        throw qt_image_view_exception();
        break;
    }
}

} // namespace qt
} // namespace gil
} // namespace boost

#endif // IVIEW_FACTORY_HPP
