// -*- C++ -*-
//
// Interceptor_Type.cpp,v 1.1 2000/11/07 20:02:31 coryan Exp
//

#include "Interceptor_Type.h"
#include "ace/OS_String.h"

ACE_RCSID (Benchmark, Interceptor_Type, "Interceptor_Type.cpp,v 1.1 2000/11/07 20:02:31 coryan Exp")

void get_interceptor_type (int argc, char *argv[],
                           int &interceptor_type)
{
  interceptor_type = IT_NONE;
  for (int i = 1; i < argc - 1; ++i)
    {
      if (ACE_OS_String::strcmp (argv[i], "-r") == 0)
        {
          if (ACE_OS_String::strcmp (argv[i+1], ACE_TEXT ("none")) == 0)
            interceptor_type = IT_NONE;
          if (ACE_OS_String::strcmp (argv[i+1], ACE_TEXT ("noop")) == 0)
            interceptor_type = IT_NOOP;
          if (ACE_OS_String::strcmp (argv[i+1], ACE_TEXT ("context")) == 0)
            interceptor_type = IT_CONTEXT;
          if (ACE_OS_String::strcmp (argv[i+1], ACE_TEXT ("dynamic")) == 0)
            interceptor_type = IT_DYNAMIC;
        }
    }
}
