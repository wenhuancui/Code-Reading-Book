// Time_Service_Server.cpp,v 1.2 1999/06/30 03:00:17 coryan Exp

#include "Server_i.h"

ACE_RCSID(TimeService, Time_Service_Server, "Time_Service_Server.cpp,v 1.2 1999/06/30 03:00:17 coryan Exp")

// This is the main driver program for the Time Service server.

int
main (int argc, char *argv[])
{
  Server_i server;

  ACE_DEBUG ((LM_DEBUG,
              "[SERVER] Process/Thread Id : (%P/%t) Time Service server\n"));

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      int r = server.init (argc, argv, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (r == -1)
        return 1;
      else
        {
          server.run (ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }
    }
  ACE_CATCH (CORBA::SystemException, sysex)
    {
      ACE_PRINT_EXCEPTION (sysex, "System Exception");
      return -1;
    }
  ACE_CATCH (CORBA::UserException, userex)
    {
      ACE_PRINT_EXCEPTION (userex, "User Exception");
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}
