#include <boost/gil/extension/dynamic_image/algorithm.hpp>

#include "format_table.hpp"
#include "iview_factory_unit_test.hpp"

static format_table table;

void read_bit_aligned_image()
{   
  int value[] = {1};
  std::vector<int> const bit_aligned_format(value, value + sizeof(value) /sizeof(int));

  namespace gil = boost::gil;
  namespace qt = gil::qt;
  typedef boost::mpl::vector<qt::gray1_view_t> type;
  boost::mpl::for_each<type>(copy_bit_aligned_image(bit_aligned_format, table.get_bit_aligned_table()) );
}

void read_packed_aligned_image()
{        
    int value[] = {3, 4, 5, 6, 7, 11, 14, 15};
    std::vector<int> const packed_aligned_format(value, value + sizeof(value) /sizeof(int));

    namespace gil = boost::gil;
    namespace qt = gil::qt;
    typedef boost::mpl::vector<gil::gray8_view_t, gil::bgra8_view_t, gil::bgra8_view_t, gil::bgra8_view_t,
                               qt::rgb565_view_t, qt::rgb655_view_t, qt::bgra4444_view_t, qt::bgra4444_view_t> type;   
    boost::mpl::for_each<type>(copy_packed_aligned_image(packed_aligned_format, table.get_packed_aligned_table()) );
}

void qt_packed_aligned_view_test_dy(int format_num, std::map<int, QString> &table)
{
    QImage src("../GIL_with_Qt/images_00/lena/lena.jpg");
    src = src.convertToFormat(QImage::Format(format_num) );
    QImage dst(src);

    //this line will cause the program crash when the format is "Format_Indexed8"
    //still don't know the reason yet(a bug of QImage, not GIL)
    //QImage dst(src.width(), src.height(), src.format());

    namespace qt = boost::gil::qt;
    boost::gil::copy_pixels(qt::create_qt_iview_dy<qt::qt_packed_view>(src), qt::create_qt_iview_dy<qt::qt_packed_view>(dst) );
    bool equal = src == dst;
    QString const img_name = "lena_" + table[format_num] + ".jpg";

    if(equal)
        qDebug() << "the result of [" << img_name << "] is correct";
    else
        qDebug() << "the result of [" << img_name << "] is incorrect";

    dst.save("../GIL_with_Qt/images_00/lena/" + img_name);
}

void read_packed_aligned_image_dy()
{
    int value[] = {3, 4, 5, 6, 7, 11, 14, 15};
    std::vector<int> const packed_aligned_format(value, value + sizeof(value) /sizeof(int));

    namespace gil = boost::gil;
    namespace qt = gil::qt;
    for(int i = 0; i != packed_aligned_format.size(); ++i)
        qt_packed_aligned_view_test_dy(packed_aligned_format[i], table.get_packed_aligned_table());
}
