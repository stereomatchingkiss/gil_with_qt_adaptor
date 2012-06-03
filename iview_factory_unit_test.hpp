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

#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include <boost/gil/algorithm.hpp>
#include <boost/gil/typedefs.hpp>

#include <boost/mpl/for_each.hpp>
#include <boost/mpl/vector.hpp>

#include <QtCore/QDebug>
#include <QtGui/QImage>

#include "iview_factory.hpp"

/*
 * Test the factory function "create_qt_iview" could work or not
 * This test only aim for bit_aligned_images and haven't finish yet
 *
 * @param :
 *  SrcType : view type of the source image
 *  DstType : view type of the destination image
 *  format_num : number of the format(htp://qt-project.org/doc/qt-4.8/qimage.html#Format-enum)
 *  table : a mapping table of the enumerator number to the format of QImage
 */
template<typename SrcType, typename DstType = SrcType>
static void qt_bit_aligned_view_test(int format_num, std::map<int, QString> &table)
{
    QImage src("../GIL_with_Qt/images_00/lena/lena.jpg");
    src = src.convertToFormat(QImage::Format(format_num) );
    QImage dst(src.width(), src.height(), src.format());

    namespace qt = boost::gil::qt;
    unsigned char *it = src.bits();
    qDebug()<<*it;
    std::bitset<8> bitData(*it);
    std::cout<<bitData<<std::endl;
}

/*
 * test the factory function "create_qt_iview" could work or not
 * This test only aim for packed_aligned_images
 *
 * @param :
 *  SrcType : view type of the source image
 *  DstType : view type of the destination image
 *  format_num : number of the format(htp://qt-project.org/doc/qt-4.8/qimage.html#Format-enum)
 *  table : a mapping table of the enumerator number to the format of QImage
 */
template<typename SrcType, typename DstType = SrcType>
static void qt_packed_aligned_view_test(int format_num, std::map<int, QString> &table)
{                
    QImage src("../GIL_with_Qt/images_00/lena/lena.jpg");
    src = src.convertToFormat(QImage::Format(format_num) );
    QImage dst(src);

    //this will cause the program crash when the format is "Format_Indexed8"
    //still still don't know the reason yet
    //QImage dst(src.width(), src.height(), src.format());

    namespace qt = boost::gil::qt;
    boost::gil::copy_pixels(qt::create_qt_iview<SrcType>(src), qt::create_qt_iview<DstType>(dst) );
    bool equal = src == dst;
    QString const img_name = "lena_" + table[format_num] + ".jpg";

    if(equal)
        qDebug() << "the result of [" << img_name << "] is correct";
    else
        qDebug() << "the result of [" << img_name << "] is incorrect";

    dst.save("../GIL_with_Qt/images_00/lena/" + img_name);
}

/*
 * copy the contents of the bit aligned image(view), this functor is designed to
 * cooperate with boost::mpl::for_each
 */
struct copy_bit_aligned_image
{    
    copy_bit_aligned_image(std::vector<int> const &format_num, std::map<int, QString> &table)
        : format_num_(format_num), table_(table), i(0) {}

    template<typename T>
    void operator()(T const&)
    {
        qt_bit_aligned_view_test<T>(format_num_[i++], table_);
    }

private :
    std::vector<int> const &format_num_; //save the key you want to fetch into the table_
    std::map<int, QString> &table_; //table of format number and its details
    int i; //index of format_num_
};

/*
 * copy the contents of the packed aligned image(view), this functor is designed to
 * cooperate with boost::mpl::for_each
 */
struct copy_packed_aligned_image
{
    copy_packed_aligned_image(std::vector<int> const &format_num, std::map<int, QString> &table)
        : format_num_(format_num), table_(table), i(0) {}

    template<typename T>
    void operator()(T const&)
    {
        qt_packed_aligned_view_test<T>(format_num_[i++], table_);
    }

private :
    std::vector<int> const &format_num_; //save the key you want to fetch into the table_
    std::map<int, QString> &table_; //table of format number and its details
    int i; //index of format_num_
};

/*
 * Haven't finished yet
 */
void read_bit_aligned_image();

/*
 * read the bit aligned image and copy
 * the contents of it
 */
void read_packed_aligned_image();

#endif // IVIEW_FACTORY_UNIT_TEST_HPP
