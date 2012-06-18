#include "format_table.hpp"

format_table::format_table()
{
    bit_aligned_table.insert(std::make_pair(1, "Format_Mono"));
    bit_aligned_table.insert(std::make_pair(2, "Format_MonoLSB"));
    bit_aligned_table.insert(std::make_pair(8, "Format_ARGB8565_Premultiplied"));
    bit_aligned_table.insert(std::make_pair(9, "Format_RGB666"));
    bit_aligned_table.insert(std::make_pair(10, "Format_ARGB6666_Premultiplied"));
    bit_aligned_table.insert(std::make_pair(12, "Format_ARGB8555_Premultiplied"));
    bit_aligned_table.insert(std::make_pair(13, "Format_RGB888"));

    packed_aligned_table.insert(std::make_pair(3, "Format_Indexed8")); //gray8_view_t
    packed_aligned_table.insert(std::make_pair(4, "Format_RGB32")); //bgra8_view_t
    packed_aligned_table.insert(std::make_pair(5, "Format_ARGB32")); //bgra8_view_t
    packed_aligned_table.insert(std::make_pair(6, "Format_ARGB32_Premultiplied")); //bgra8_view_t
    packed_aligned_table.insert(std::make_pair(7, "Format_RGB16")); //rgb565_view_t
    packed_aligned_table.insert(std::make_pair(11, "Format_RGB555")); //rgb655_view_t
    packed_aligned_table.insert(std::make_pair(14, "Format_RGB444")); //bgra4444_view_t
    packed_aligned_table.insert(std::make_pair(15, "Format_ARGB4444_Premultiplied")); //bgra4444_view_t
}
