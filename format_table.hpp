/*
    Copyright 2012 stereomatching
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef FORMAT_TABLE_HPP
#define FORMAT_TABLE_HPP

////////////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief
/// \author stereomatching \n
///
/// \date 2012 \n
///
////////////////////////////////////////////////////////////////////////////////////////

#include <map>

#include <QtCore/QString>

/*
 * A mapping table of the format number of QImage and the associative description
 */
class format_table
{
  public :
    format_table();
    std::map<int, QString> &get_bit_aligned_table() { return _bit_aligned_table; }
    std::map<int, QString> &get_packed_aligned_table() { return _packed_aligned_table; }
    std::map<int, QString> const &get_bit_aligned_table() const { return _bit_aligned_table; }
    std::map<int, QString> const &get_packed_aligned_table() const { return _packed_aligned_table; }

  private :
    format_table(format_table const&);
    format_table operator=(format_table const&);

  private :
    std::map<int, QString> _bit_aligned_table;
    std::map<int, QString> _packed_aligned_table;
};

#endif // FORMAT_TABLE_HPP
