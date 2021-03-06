/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:404
 */

#ifndef __Cache_DirEntry_HH__
#define __Cache_DirEntry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/NetDest.hh"
#include "mem/ruby/protocol/MachineID.hh"
#include "mem/ruby/protocol/Cache_State.hh"
#include "mem/ruby/protocol/AbstractCacheEntry.hh"
namespace gem5
{

namespace ruby
{

class Cache_DirEntry :  public AbstractCacheEntry
{
  public:
    Cache_DirEntry
()
		{
        // m_sharers has no default
        // m_owner has no default
        m_ownerExists = false; // default for this field
        m_ownerIsExcl = false; // default for this field
        m_state = Cache_State_null;
         // default value of Cache_State
    }
    Cache_DirEntry(const Cache_DirEntry&) = default;
    Cache_DirEntry
    &operator=(const Cache_DirEntry&) = default;
    Cache_DirEntry(const NetDest& local_sharers, const MachineID& local_owner, const bool& local_ownerExists, const bool& local_ownerIsExcl, const Cache_State& local_state)
        : AbstractCacheEntry()
    {
        m_sharers = local_sharers;
        m_owner = local_owner;
        m_ownerExists = local_ownerExists;
        m_ownerIsExcl = local_ownerIsExcl;
        m_state = local_state;
    }
    Cache_DirEntry*
    clone() const
    {
         return new Cache_DirEntry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for sharers field.
     *  \return sharers field
     */
    const NetDest&
    getsharers() const
    {
        return m_sharers;
    }
    /** \brief Const accessor method for owner field.
     *  \return owner field
     */
    const MachineID&
    getowner() const
    {
        return m_owner;
    }
    /** \brief Const accessor method for ownerExists field.
     *  \return ownerExists field
     */
    const bool&
    getownerExists() const
    {
        return m_ownerExists;
    }
    /** \brief Const accessor method for ownerIsExcl field.
     *  \return ownerIsExcl field
     */
    const bool&
    getownerIsExcl() const
    {
        return m_ownerIsExcl;
    }
    /** \brief Const accessor method for state field.
     *  \return state field
     */
    const Cache_State&
    getstate() const
    {
        return m_state;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for sharers field.
     *  \return sharers field
     */
    NetDest&
    getsharers()
    {
        return m_sharers;
    }
    /** \brief Non-const accessor method for owner field.
     *  \return owner field
     */
    MachineID&
    getowner()
    {
        return m_owner;
    }
    /** \brief Non-const accessor method for ownerExists field.
     *  \return ownerExists field
     */
    bool&
    getownerExists()
    {
        return m_ownerExists;
    }
    /** \brief Non-const accessor method for ownerIsExcl field.
     *  \return ownerIsExcl field
     */
    bool&
    getownerIsExcl()
    {
        return m_ownerIsExcl;
    }
    /** \brief Non-const accessor method for state field.
     *  \return state field
     */
    Cache_State&
    getstate()
    {
        return m_state;
    }
    // Mutator methods for each field
    /** \brief Mutator method for sharers field */
    void
    setsharers(const NetDest& local_sharers)
    {
        m_sharers = local_sharers;
    }
    /** \brief Mutator method for owner field */
    void
    setowner(const MachineID& local_owner)
    {
        m_owner = local_owner;
    }
    /** \brief Mutator method for ownerExists field */
    void
    setownerExists(const bool& local_ownerExists)
    {
        m_ownerExists = local_ownerExists;
    }
    /** \brief Mutator method for ownerIsExcl field */
    void
    setownerIsExcl(const bool& local_ownerIsExcl)
    {
        m_ownerIsExcl = local_ownerIsExcl;
    }
    /** \brief Mutator method for state field */
    void
    setstate(const Cache_State& local_state)
    {
        m_state = local_state;
    }
    void print(std::ostream& out) const;
  //private:
    /** All upstream controllers that have this line (includes ownwer) */
    NetDest m_sharers;
    /** Controller that has the line in UD,UC, or SD state */
    MachineID m_owner;
    /** true if owner exists */
    bool m_ownerExists;
    /** true if owner is UD or UC */
    bool m_ownerIsExcl;
    /** SLICC line state */
    Cache_State m_state;
};
inline ::std::ostream&
operator<<(::std::ostream& out, const Cache_DirEntry& obj)
{
    obj.print(out);
    out << ::std::flush;
    return out;
}

} // namespace ruby
} // namespace gem5

#endif // __Cache_DirEntry_HH__
