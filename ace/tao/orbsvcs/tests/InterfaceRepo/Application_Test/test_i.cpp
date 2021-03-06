// -*- C++ -*-
// test_i.cpp,v 1.1 2001/01/02 22:53:08 parsons Exp

#include "test_i.h"

ACE_RCSID(Application_Test, test_i, "test_i.cpp,v 1.1 2001/01/02 22:53:08 parsons Exp")

CORBA::Boolean
inventory_i::getCDinfo (const char * artist,
                        char *& title,
                        CORBA::Float_out price,
                        CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Boolean in_stock = 0;
  price = 0.0f;
  ACE_CString name_key ("Beatles");
  ACE_CString name (artist);

  if (name.strstr (name_key) != -1)
    {
      ACE_CString title_key ("Sgt. Pepper");
      ACE_CString working_title (title);

      if (working_title.strstr (title_key) != -1)
        {
          title = 
            CORBA::string_dup ("Sgt. Pepper's Lonely Hearts Club Band");

          price = 13.49f;

          in_stock = 1;
        }
      else
        {
          title = CORBA::string_dup ("not found");
        }
    }
  else
    {
      title = CORBA::string_dup ("not found");
    }

  return in_stock;
}

