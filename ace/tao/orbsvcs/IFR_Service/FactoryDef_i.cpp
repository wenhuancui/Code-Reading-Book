/* -*- C++ -*- */
// FactoryDef_i.cpp,v 1.5 2001/03/30 16:43:15 parsons Exp

#include "Repository_i.h"
#include "FactoryDef_i.h"

ACE_RCSID(IFR_Service, FactoryDef_i, "FactoryDef_i.cpp,v 1.5 2001/03/30 16:43:15 parsons Exp")

TAO_FactoryDef_i::TAO_FactoryDef_i (
    TAO_Repository_i *repo,
    ACE_Configuration_Section_Key section_key
  )
  : TAO_IRObject_i (repo, section_key),
    TAO_Contained_i (repo, section_key),
    TAO_OperationDef_i (repo, section_key)
{
}

TAO_FactoryDef_i::~TAO_FactoryDef_i (void)
{
}

CORBA::DefinitionKind
TAO_FactoryDef_i::def_kind (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::dk_Factory;
}

void 
TAO_FactoryDef_i::destroy (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->destroy_i (ACE_TRY_ENV);
}

void 
TAO_FactoryDef_i::destroy_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
}

CORBA_Contained::Description *
TAO_FactoryDef_i::describe (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->describe_i (ACE_TRY_ENV);
}

CORBA_Contained::Description *
TAO_FactoryDef_i::describe_i (CORBA::Environment & /* ACE_TRY_ENV */ )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

