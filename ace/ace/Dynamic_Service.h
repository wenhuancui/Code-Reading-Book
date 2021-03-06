/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Dynamic_Service.h
 *
 *  Dynamic_Service.h,v 4.13 2001/10/01 00:44:54 schmidt Exp
 *
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_DYNAMIC_SERVICE_H
#define ACE_DYNAMIC_SERVICE_H
#include "ace/pre.h"

#include "ace/OS.h"

#include "ace/Dynamic_Service_Base.h"

/**
 * @class ACE_Dynamic_Service
 *
 * @brief Provides a general interface to retrieve arbitrary objects
 * from the ACE service repository.
 *
 * Uses "name" for lookup in the ACE service repository. Obtains
 * the object and returns it as the appropriate type.
 */
template <class TYPE>
class ACE_Dynamic_Service : public ACE_Dynamic_Service_Base
{
public:
  /// Return instance using <name> to search the Service_Repository.
  static TYPE*instance (const ACE_TCHAR *name);
};

#if defined (__ACE_INLINE__)
#include "ace/Dynamic_Service.i"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
# include "ace/Dynamic_Service.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
# pragma implementation ("Dynamic_Service.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include "ace/post.h"
#endif /* ACE_DYNAMIC_SERVICE_H */
