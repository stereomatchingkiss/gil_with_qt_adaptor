#include "iview_factory_unit_test.hpp"

void read_bit_aligned_image()
{
  std::map<int, QString> bit_aligned_table = {
        {1, "Format_Mono"},                      //
        {2, "Format_MonoLSB"},                   //
        {8, "Format_ARGB8565_Premultiplied"},    //
        {9, "Format_RGB666"},                    //
        {10, "Format_ARGB6666_Premultiplied"},   //
        {12, "Format_ARGB8555_Premultiplied"},   //
        {13, "Format_RGB888"}                    //
  };
  std::vector<int> const bit_aligned_format = {1}; //packed pixels

  namespace gil = boost::gil;
  namespace qt = gil::qt;
  typedef boost::mpl::vector<qt::gray1_view_t> type;
  boost::mpl::for_each<type>(copy_bit_aligned_image(bit_aligned_format, bit_aligned_table) );
}

void read_packed_aligned_image()
{
    std::map<int, QString> packed_aligned_table = {
        {3, "Format_Indexed8"},                //gray8_view_t
        {4, "Format_RGB32"},                   //bgra8_view_t
        {5, "Format_ARGB32"},                  //bgra8_view_t
        {6, "Format_ARGB32_Premultiplied"},    //bgra8_view_t
        {7, "Format_RGB16"},                   //rgb565_view_t
        {11, "Format_RGB555"},                 //rgb655_view_t
        {14, "Format_RGB444"},                 //bgra4444_view_t
        {15, "Format_ARGB4444_Premultiplied"}  //bgra4444_view_t
    };
    std::vector<int> const byte_aligned_format = {3, 4, 5, 6, 7, 11, 14, 15}; //packed pixels

    namespace gil = boost::gil;
    namespace qt = gil::qt;
    typedef boost::mpl::vector<gil::gray8_view_t, gil::bgra8_view_t, gil::bgra8_view_t, gil::bgra8_view_t,
                               qt::rgb565_view_t, qt::rgb655_view_t, qt::bgra4444_view_t, qt::bgra4444_view_t> type;

    boost::mpl::for_each<type>(copy_packed_aligned_image(byte_aligned_format, packed_aligned_table) );
}
