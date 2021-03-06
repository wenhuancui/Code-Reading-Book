/* -*- C++ -*- */
// ComponentDef_i.cpp,v 1.8 2001/03/31 01:15:52 parsons Exp

#include "Repository_i.h"
#include "ComponentDef_i.h"

ACE_RCSID(IFR_Service, ComponentDef_i, "ComponentDef_i.cpp,v 1.8 2001/03/31 01:15:52 parsons Exp")

TAO_ComponentDef_i::TAO_ComponentDef_i (
    TAO_Repository_i *repo,
    ACE_Configuration_Section_Key section_key
  )
  : TAO_IRObject_i (repo, section_key),
    TAO_Container_i (repo, section_key),
    TAO_Contained_i (repo, section_key),
    TAO_IDLType_i (repo, section_key),
    TAO_InterfaceDef_i (repo, section_key)
{
}

TAO_ComponentDef_i::~TAO_ComponentDef_i (void)
{
}

CORBA::DefinitionKind
TAO_ComponentDef_i::def_kind (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::dk_Component;
}

void 
TAO_ComponentDef_i::destroy (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->destroy_i (ACE_TRY_ENV);
}

void 
TAO_ComponentDef_i::destroy_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
}

CORBA_Contained::Description *
TAO_ComponentDef_i::describe (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->describe_i (ACE_TRY_ENV);
}

CORBA_Contained::Description *
TAO_ComponentDef_i::describe_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

CORBA::TypeCode_ptr 
TAO_ComponentDef_i::type (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (CORBA::TypeCode::_nil ());

  return this->type_i (ACE_TRY_ENV);
}

CORBA::TypeCode_ptr 
TAO_ComponentDef_i::type_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

CORBA_InterfaceDefSeq *
TAO_ComponentDef_i::supported_interfaces (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->supported_interfaces_i (ACE_TRY_ENV);
}

CORBA_InterfaceDefSeq *
TAO_ComponentDef_i::supported_interfaces_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

void 
TAO_ComponentDef_i::supported_interfaces (
    const CORBA_InterfaceDefSeq &supported_interfaces,
    CORBA::Environment &ACE_TRY_ENV
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->supported_interfaces_i (supported_interfaces,
                                ACE_TRY_ENV);
}

void 
TAO_ComponentDef_i::supported_interfaces_i (
    const CORBA_InterfaceDefSeq & /* supported_interfaces */,
    CORBA::Environment & /* ACE_TRY_ENV */
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
}

IR::ComponentDef_ptr 
TAO_ComponentDef_i::base_component (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (IR::ComponentDef::_nil ());

  return this->base_component_i (ACE_TRY_ENV);
}

IR::ComponentDef_ptr 
TAO_ComponentDef_i::base_component_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::ProvidesDefSeq *
TAO_ComponentDef_i::provides_interfaces (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->provides_interfaces_i (ACE_TRY_ENV);
}

IR::ProvidesDefSeq *
TAO_ComponentDef_i::provides_interfaces_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::UsesDefSeq *
TAO_ComponentDef_i::uses_interfaces (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->uses_interfaces_i (ACE_TRY_ENV);
}

IR::UsesDefSeq *
TAO_ComponentDef_i::uses_interfaces_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::EmitsDefSeq *
TAO_ComponentDef_i::emits_events (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->emits_events_i (ACE_TRY_ENV);
}

IR::EmitsDefSeq *
TAO_ComponentDef_i::emits_events_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::PublishesDefSeq *
TAO_ComponentDef_i::publishes_events (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->publishes_events_i (ACE_TRY_ENV);
}

IR::PublishesDefSeq *
TAO_ComponentDef_i::publishes_events_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::ConsumesDefSeq *
TAO_ComponentDef_i::consumes_events (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->consumes_events_i (ACE_TRY_ENV);
}

IR::ConsumesDefSeq *
TAO_ComponentDef_i::consumes_events_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

CORBA::Boolean 
TAO_ComponentDef_i::is_basic (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::ProvidesDef_ptr 
TAO_ComponentDef_i::create_provides (
    const char *id,
    const char *name,
    const char *version,
    CORBA_InterfaceDef_ptr interface_type,
    CORBA::Environment &ACE_TRY_ENV
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD_RETURN (IR::ProvidesDef::_nil ());

  return this->create_provides_i (id,
                                  name,
                                  version,
                                  interface_type,
                                  ACE_TRY_ENV);
}

IR::ProvidesDef_ptr 
TAO_ComponentDef_i::create_provides_i (
    const char * /* id */,
    const char * /* name */,
    const char * /* version */,
    CORBA_InterfaceDef_ptr  /* interface_type */,
    CORBA::Environment & /* ACE_TRY_ENV */
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::UsesDef_ptr 
TAO_ComponentDef_i::create_uses (const char *id,
                                 const char *name,
                                 const char *version,
                                 CORBA_InterfaceDef_ptr interface_type,
                                 CORBA::Boolean is_multiple,
                                 CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD_RETURN (IR::UsesDef::_nil ());

  return this->create_uses_i (id,
                              name,
                              version,
                              interface_type,
                              is_multiple,
                              ACE_TRY_ENV);
}

IR::UsesDef_ptr 
TAO_ComponentDef_i::create_uses_i (const char * /* id */,
                                   const char * /* name */,
                                   const char * /* version */,
                                   CORBA_InterfaceDef_ptr  /* interface_type */,
                                   CORBA::Boolean /* is_multiple */,
                                   CORBA::Environment & /* ACE_TRY_ENV */ )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::EmitsDef_ptr 
TAO_ComponentDef_i::create_emits (const char *id,
                                  const char *name,
                                  const char *version,
                                  CORBA_ValueDef_ptr value,
                                  CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD_RETURN (IR::EmitsDef::_nil ());

  return this->create_emits_i (id,
                               name,
                               version,
                               value,
                                ACE_TRY_ENV);
}

IR::EmitsDef_ptr 
TAO_ComponentDef_i::create_emits_i (const char * /* id */,
                                    const char * /* name */,
                                    const char * /* version */,
                                    CORBA_ValueDef_ptr  /* value */,
                                    CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::PublishesDef_ptr 
TAO_ComponentDef_i::create_publishes (const char *id,
                                      const char *name,
                                      const char *version,
                                      CORBA_ValueDef_ptr value,
                                      CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD_RETURN (IR::PublishesDef::_nil ());

  return this->create_publishes_i (id,
                                   name,
                                   version,
                                   value,
                                   ACE_TRY_ENV);
}

IR::PublishesDef_ptr 
TAO_ComponentDef_i::create_publishes_i (const char * /* id */,
                                        const char * /* name */,
                                        const char * /* version */,
                                        CORBA_ValueDef_ptr  /* value */,
                                        CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::ConsumesDef_ptr 
TAO_ComponentDef_i::create_consumes (const char *id,
                                     const char *name,
                                     const char *version,
                                     CORBA_ValueDef_ptr value,
                                     CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD_RETURN (IR::ConsumesDef::_nil ());

  return this->create_consumes_i (id,
                                  name,
                                  version,
                                  value,
                                  ACE_TRY_ENV);
}

IR::ConsumesDef_ptr 
TAO_ComponentDef_i::create_consumes_i (const char * /* id */,
                                       const char * /* name */,
                                       const char * /* version */,
                                       CORBA_ValueDef_ptr  /* value */,
                                       CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

