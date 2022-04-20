/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:404
 */

#ifndef __Cache_CacheEntry_HH__
#define __Cache_CacheEntry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/Cache_State.hh"
#include "mem/ruby/protocol/DataBlock.hh"
#include "mem/ruby/protocol/AbstractCacheEntry.hh"
namespace gem5
{

namespace ruby
{

class Cache_CacheEntry :  public AbstractCacheEntry
{
  public:
    Cache_CacheEntry
()
		{
        m_state = Cache_State_null;
         // default value of Cache_State
        // m_DataBlk has no default
        m_HWPrefetched = false; // default for this field
    }
    Cache_CacheEntry(const Cache_CacheEntry&) = default;
    Cache_CacheEntry
    &operator=(const Cache_CacheEntry&) = default;
    Cache_CacheEntry(const Cache_State& local_state, const DataBlock& local_DataBlk, const bool& local_HWPrefetched)
        : AbstractCacheEntry()
    {
        m_state = local_state;
        m_DataBlk = local_DataBlk;
        m_HWPrefetched = local_HWPrefetched;
    }
    Cache_CacheEntry*
    clone() const
    {
         return new Cache_CacheEntry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for state field.
     *  \return state field
     */
    const Cache_State&
    getstate() const
    {
        return m_state;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    /** \brief Const accessor method for HWPrefetched field.
     *  \return HWPrefetched field
     */
    const bool&
    getHWPrefetched() const
    {
        return m_HWPrefetched;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for state field.
     *  \return state field
     */
    Cache_State&
    getstate()
    {
        return m_state;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    /** \brief Non-const accessor method for HWPrefetched field.
     *  \return HWPrefetched field
     */
    bool&
    getHWPrefetched()
    {
        return m_HWPrefetched;
    }
    // Mutator methods for each field
    /** \brief Mutator method for state field */
    void
    setstate(const Cache_State& local_state)
    {
        m_state = local_state;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    /** \brief Mutator method for HWPrefetched field */
    void
    setHWPrefetched(const bool& local_HWPrefetched)
    {
        m_HWPrefetched = local_HWPrefetched;
    }
    void print(std::ostream& out) const;
  //private:
    /** SLICC line state */
    Cache_State m_state;
    /** data for the block */
    DataBlock m_DataBlk;
    /** Set if this cache entry was prefetched */
    bool m_HWPrefetched;
};
inline ::std::ostream&
operator<<(::std::ostream& out, const Cache_CacheEntry& obj)
{
    obj.print(out);
    out << ::std::flush;
    return out;
}

} // namespace ruby
} // namespace gem5

#endif // __Cache_CacheEntry_HH__
