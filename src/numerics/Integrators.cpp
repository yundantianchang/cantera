//! @file Integrators.cpp

// This file is part of Cantera. See License.txt in the top-level directory or
// at https://cantera.org/license.txt for license and copyright information.

#include "cantera/base/ct_defs.h"
#include "cantera/numerics/Integrator.h"
#include "cantera/numerics/CVodesIntegrator.h"
#include "cantera/numerics/IdasIntegrator.h"

namespace Cantera
{

Integrator* newIntegrator(const std::string& itype)
{
    if (itype == "CVODE") {
        return new CVodesIntegrator();
    } else if (itype == "IDA") {
        return new IdasIntegrator();
    } else {
        throw CanteraError("newIntegrator",
                           "unknown integrator: "+itype);
    }
    return 0;
}

}
