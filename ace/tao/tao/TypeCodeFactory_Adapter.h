// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file    TypeCodeFactory_Adapter.h
 *
 *  TypeCodeFactory_Adapter.h,v 1.2 2001/04/04 13:41:32 bala Exp
 *
 *  @author  Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_TYPECODEFACTORY_ADAPTER_H
#define TAO_TYPECODEFACTORY_ADAPTER_H
#include "ace/pre.h"

#include "tao/Exception.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Object.h"

/**
 * @class TAO_TypeCodeFactory_Adapter
 *
 * @brief TAO_TypeCodeFactory_Adapter.
 *
 * Class that adapts the CORBA::ORB create_*_tc functions
 * to use the TypeCodeFactory. This is a base class for 
 * the actual implementation in the TypeCodeFactory_DLL library.
 */
class TAO_Export TAO_TypeCodeFactory_Adapter : public ACE_Service_Object
{
public:
  virtual ~TAO_TypeCodeFactory_Adapter (void);

  virtual CORBA::TypeCode_ptr create_struct_tc (
      const char *id,
      const char *name,
      const CORBA_StructMemberSeq &members,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_union_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr discriminator_type,
      const CORBA_UnionMemberSeq &members,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_enum_tc (
      const char *id,
      const char *name,
      const CORBA_EnumMemberSeq &members,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_alias_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr original_type,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_exception_tc (
      const char *id,
      const char *name,
      const CORBA_StructMemberSeq &members,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_interface_tc (
      const char *id,
      const char *name,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_string_tc (
      CORBA::ULong bound,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_wstring_tc (
      CORBA::ULong bound,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_fixed_tc (
      CORBA::UShort digits,
      CORBA::UShort scale,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_sequence_tc (
      CORBA::ULong bound,
      CORBA::TypeCode_ptr element_type,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_array_tc (
      CORBA::ULong length,
      CORBA::TypeCode_ptr element_type,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_value_tc (
      const char *id,
      const char *name,
      CORBA::ValueModifier type_modifier,
      CORBA::TypeCode_ptr concrete_base,
      const CORBA_ValueMemberSeq &members,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_value_box_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr boxed_type,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_native_tc (
      const char *id,
      const char *name,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_recursive_tc (
      const char *id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_abstract_interface_tc (
      const char *id,
      const char *name,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_local_interface_tc (
      const char *id,
      const char *name,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )  
    ACE_THROW_SPEC ((CORBA::SystemException));
};

#include "ace/post.h"
#endif /* TAO_TYPECODEFACTORY_ADAPTER_H */
