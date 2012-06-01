/*
    Copyright 2008 stereomatching
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef IVIEW_FACTORY_UNIT_TEST_HPP
#define IVIEW_FACTORY_UNIT_TEST_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author stereomatching \n
///
/// \date 2008 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include <boost/gil/algorithm.hpp>
#include <boost/gil/typedefs.hpp>

#include <boost/mpl/for_each.hpp>
#include <boost/mpl/vector.hpp>

#include <QtGui/QImage>

#include "iview_factory.hpp"

/*
 * test the factory function "create_qt_iview" could work or not
 *
 * @param :
 *  SrcType : view type of the source image
 *  DstType : view type of the destination image
 *  format_num : number of the format(htp://qt-project.org/doc/qt-4.8/qimage.html#Format-enum)
 *  table : a mapping table of the enumerator number to the format of QImage
 */
template<typename SrcType, typename DstType = SrcType>
static void qt_view_test(int format_num, std::map<int, QString> &table)
{            
    QImage src("../GIL_with_Qt/images_00/lena/lena.jpg");
    src = src.convertToFormat(QImage::Format(format_num) );

    QImage dst(src.width(), src.height(), src.format());

    namespace qt = boost::gil::qt;
    boost::gil::copy_pixels(qt::create_qt_iview<SrcType>(src), qt::create_qt_iview<DstType>(dst) );
    bool equal = src == dst;
    QString const img_name = "lena_" + table[format_num] + ".png";

    if(equal)
        std::cout << "the result of [" << img_name.toStdString() << "] is correct"<<std::endl;
    else
        std::cout << "the result of [" << img_name.toStdString() << "] is incorrect"<<std::endl;

    dst.save("../GIL_with_Qt/images_00/lena/" + img_name);
}

struct copy_image
{
    copy_image(std::vector<int> const &format_num, std::map<int, QString> &table)
        : format_num_(format_num), table_(table), i(0) {}

    template<typename T>
    void operator()(T const&)
    {
        qt_view_test<T>(format_num_[i++], table_);
    }

private :
    std::vector<int> const &format_num_;
    std::map<int, QString> &table_;
    int i;
};

void read_image();

#endif // IVIEW_FACTORY_UNIT_TEST_HPP
