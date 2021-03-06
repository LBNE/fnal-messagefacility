#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "messagefacility/Utilities/UnixSignalHandlers.h"
#include "messagefacility/Utilities/DebugMacros.h"

namespace mf {

#define MUST_BE_ZERO(fun) if((fun) != 0)                                        \
      { perror("UnixSignalHandlers::setupSignal: sig function failed"); abort(); }

//--------------------------------------------------------------

    void disableAllSigs( sigset_t* oldset )
    {
      sigset_t myset;
      // all blocked for now
      MUST_BE_ZERO(sigfillset(&myset));
      MUST_BE_ZERO(pthread_sigmask(SIG_SETMASK,&myset,oldset));
    }

//--------------------------------------------------------------

} // end of namespace mf
