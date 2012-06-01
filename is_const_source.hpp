/*
    Copyright 2008 stereomatching
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef IS_CONST_SOURCE_HPP
#define IS_CONST_SOURCE_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author stereomatching \n
///
/// \date 2008 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <boost/gil/typedefs.hpp>

#include <boost/type_traits.hpp>

#include "is_const_view.hpp"

namespace boost{ namespace gil {

/*
 * determine the source should be Image& or Image const&
 *
 * @param :
 *  View : the view of GIL you want to create
 *  Image : the type of the image(ex : QImage of Qt)
 */
template<typename View, typename Image>
struct is_const_source
{
  private :
    typedef typename is_const_view<View>::type true_or_false;

  public :
    typedef typename boost::conditional<
                                         true_or_false::value,
                                         boost::add_reference<Image const>,
                                         boost::add_reference<Image>
                                       >::type::type type;
};

} // namespace opencv
} // namespace gil


#endif // IS_CONST_SOURCE_HPP
