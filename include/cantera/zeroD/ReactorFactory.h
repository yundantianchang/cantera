//! @file ReactorFactory.h

// This file is part of Cantera. See License.txt in the top-level directory or
// at https://cantera.org/license.txt for license and copyright information.

#ifndef REACTOR_FACTORY_H
#define REACTOR_FACTORY_H

#include "cantera/zeroD/ReactorBase.h"
#include "cantera/base/FactoryBase.h"

namespace Cantera
{

//! Factory class to create reactor objects
//!
//! This class is mainly used via the newReactor() function, for example:
//!
//! ```cpp
//!     unique_ptr<ReactorBase> r1(newReactor("IdealGasReactor"));
//! ```
//!
//! @ingroup ZeroD
class ReactorFactory : public Factory<ReactorBase>
{
public:
    static ReactorFactory* factory();

    virtual void deleteFactory();

    //! Create a new reactor by type name.
    /*!
     * @param reactorType the type to be created.
     */
    virtual ReactorBase* newReactor(const std::string& reactorType);

private:
    static ReactorFactory* s_factory;
    static std::mutex reactor_mutex;
    ReactorFactory();
};

//! Create a Reactor object of the specified type
//! @ingroup ZeroD
ReactorBase* newReactor(const string& model);

}

#endif
