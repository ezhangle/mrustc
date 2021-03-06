/*
 * High-level intermediate representation
 */
#pragma once

namespace HIR {

class Crate;

class CratePtr
{
    Crate*  m_ptr;

public:
    CratePtr();
    CratePtr(Crate c);
    CratePtr(CratePtr&& x):
        m_ptr( x.m_ptr )
    {
        x.m_ptr = nullptr;
    }
    CratePtr& operator=(CratePtr&& x)
    {
        this->~CratePtr();
        m_ptr = x.m_ptr;
        x.m_ptr = nullptr;
        return *this;
    }
    ~CratePtr();

          Crate& operator*()       { return *m_ptr; }
    const Crate& operator*() const { return *m_ptr; }
          Crate* operator->()       { return m_ptr; }
    const Crate* operator->() const { return m_ptr; }
};

}   // namespace HIR

