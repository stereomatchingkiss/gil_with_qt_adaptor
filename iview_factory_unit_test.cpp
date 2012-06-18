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
