// -*- C++ -*-
//
// IFR_BaseS_T.i,v 1.5 2001/06/02 06:39:29 othman Exp

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#if defined (ACE_HAS_USING_KEYWORD)

template <class T> ACE_INLINE
POA_CORBA_IRObject_tie<T>::POA_CORBA_IRObject_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_IRObject_tie<T>::POA_CORBA_IRObject_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_IRObject_tie<T>::POA_CORBA_IRObject_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_IRObject_tie<T>::POA_CORBA_IRObject_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_IRObject_tie<T>::~POA_CORBA_IRObject_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA_IRObject_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA_IRObject_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA_IRObject_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA_IRObject_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA_IRObject_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA_IRObject_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->POA_CORBA_IRObject::_default_POA (ACE_TRY_ENV);
}

template <class T> ACE_INLINE
CORBA::DefinitionKind POA_CORBA_IRObject_tie<T>::def_kind  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->def_kind (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_IRObject_tie<T>::destroy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
POA_CORBA_Contained_tie<T>::POA_CORBA_Contained_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_Contained_tie<T>::POA_CORBA_Contained_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_Contained_tie<T>::POA_CORBA_Contained_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_Contained_tie<T>::POA_CORBA_Contained_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_Contained_tie<T>::~POA_CORBA_Contained_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA_Contained_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA_Contained_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA_Contained_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA_Contained_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA_Contained_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA_Contained_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->POA_CORBA_Contained::_default_POA (ACE_TRY_ENV);
}

template <class T> ACE_INLINE
char * POA_CORBA_Contained_tie<T>::id  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->id (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_Contained_tie<T>::id  (
    const char * id,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->id (
id,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
char * POA_CORBA_Contained_tie<T>::name  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->name (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_Contained_tie<T>::name  (
    const char * name,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->name (
name,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
char * POA_CORBA_Contained_tie<T>::version  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->version (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_Contained_tie<T>::version  (
    const char * version,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->version (
version,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_Container_ptr POA_CORBA_Contained_tie<T>::defined_in  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->defined_in (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
char * POA_CORBA_Contained_tie<T>::absolute_name  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->absolute_name (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_Repository_ptr POA_CORBA_Contained_tie<T>::containing_repository  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->containing_repository (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_Contained::Description * POA_CORBA_Contained_tie<T>::describe  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->describe (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_Contained_tie<T>::move  (
    CORBA_Container_ptr new_container,
    const char * new_name,
    const char * new_version,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->move (
new_container,
    new_name,
    new_version,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::DefinitionKind POA_CORBA_Contained_tie<T>::def_kind  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->def_kind (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_Contained_tie<T>::destroy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
POA_CORBA_Container_tie<T>::POA_CORBA_Container_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_Container_tie<T>::POA_CORBA_Container_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_Container_tie<T>::POA_CORBA_Container_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_Container_tie<T>::POA_CORBA_Container_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_Container_tie<T>::~POA_CORBA_Container_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA_Container_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA_Container_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA_Container_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA_Container_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA_Container_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA_Container_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->POA_CORBA_Container::_default_POA (ACE_TRY_ENV);
}

template <class T> ACE_INLINE
CORBA_Contained_ptr POA_CORBA_Container_tie<T>::lookup  (
    const char * search_name,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->lookup (
search_name,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_ContainedSeq * POA_CORBA_Container_tie<T>::contents  (
    CORBA::DefinitionKind limit_type,
    CORBA::Boolean exclude_inherited,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->contents (
limit_type,
    exclude_inherited,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_ContainedSeq * POA_CORBA_Container_tie<T>::lookup_name  (
    const char * search_name,
    CORBA::Long levels_to_search,
    CORBA::DefinitionKind limit_type,
    CORBA::Boolean exclude_inherited,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->lookup_name (
search_name,
    levels_to_search,
    limit_type,
    exclude_inherited,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_Container::DescriptionSeq * POA_CORBA_Container_tie<T>::describe_contents  (
    CORBA::DefinitionKind limit_type,
    CORBA::Boolean exclude_inherited,
    CORBA::Long max_returned_objs,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->describe_contents (
limit_type,
    exclude_inherited,
    max_returned_objs,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_ModuleDef_ptr POA_CORBA_Container_tie<T>::create_module  (
    const char * id,
    const char * name,
    const char * version,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_module (
id,
    name,
    version,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_ConstantDef_ptr POA_CORBA_Container_tie<T>::create_constant  (
    const char * id,
    const char * name,
    const char * version,
    CORBA_IDLType_ptr type,
    const CORBA::Any & value,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_constant (
id,
    name,
    version,
    type,
    value,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_StructDef_ptr POA_CORBA_Container_tie<T>::create_struct  (
    const char * id,
    const char * name,
    const char * version,
    const CORBA_StructMemberSeq & members,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_struct (
id,
    name,
    version,
    members,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_UnionDef_ptr POA_CORBA_Container_tie<T>::create_union  (
    const char * id,
    const char * name,
    const char * version,
    CORBA_IDLType_ptr discriminator_type,
    const CORBA_UnionMemberSeq & members,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_union (
id,
    name,
    version,
    discriminator_type,
    members,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_EnumDef_ptr POA_CORBA_Container_tie<T>::create_enum  (
    const char * id,
    const char * name,
    const char * version,
    const CORBA_EnumMemberSeq & members,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_enum (
id,
    name,
    version,
    members,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_AliasDef_ptr POA_CORBA_Container_tie<T>::create_alias  (
    const char * id,
    const char * name,
    const char * version,
    CORBA_IDLType_ptr original_type,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_alias (
id,
    name,
    version,
    original_type,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_InterfaceDef_ptr POA_CORBA_Container_tie<T>::create_interface  (
    const char * id,
    const char * name,
    const char * version,
    const CORBA_InterfaceDefSeq & base_interfaces,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_interface (
id,
    name,
    version,
    base_interfaces,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_ValueDef_ptr POA_CORBA_Container_tie<T>::create_value  (
    const char * id,
    const char * name,
    const char * version,
    CORBA::Boolean is_custom,
    CORBA::Boolean is_abstract,
    CORBA_ValueDef_ptr base_value,
    CORBA::Boolean is_truncatable,
    const CORBA_ValueDefSeq & abstract_base_values,
    const CORBA_InterfaceDefSeq & supported_interfaces,
    const CORBA_InitializerSeq & initializers,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_value (
id,
    name,
    version,
    is_custom,
    is_abstract,
    base_value,
    is_truncatable,
    abstract_base_values,
    supported_interfaces,
    initializers,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_ValueBoxDef_ptr POA_CORBA_Container_tie<T>::create_value_box  (
    const char * id,
    const char * name,
    const char * version,
    CORBA_IDLType_ptr original_type_def,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_value_box (
id,
    name,
    version,
    original_type_def,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_ExceptionDef_ptr POA_CORBA_Container_tie<T>::create_exception  (
    const char * id,
    const char * name,
    const char * version,
    const CORBA_StructMemberSeq & members,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_exception (
id,
    name,
    version,
    members,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_NativeDef_ptr POA_CORBA_Container_tie<T>::create_native  (
    const char * id,
    const char * name,
    const char * version,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_native (
id,
    name,
    version,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_AbstractInterfaceDef_ptr POA_CORBA_Container_tie<T>::create_abstract_interface  (
    const char * id,
    const char * name,
    const char * version,
    const CORBA_AbstractInterfaceDefSeq & base_interfaces,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_abstract_interface (
id,
    name,
    version,
    base_interfaces,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_LocalInterfaceDef_ptr POA_CORBA_Container_tie<T>::create_local_interface  (
    const char * id,
    const char * name,
    const char * version,
    const CORBA_InterfaceDefSeq & base_interfaces,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->create_local_interface (
id,
    name,
    version,
    base_interfaces,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::DefinitionKind POA_CORBA_Container_tie<T>::def_kind  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->def_kind (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_Container_tie<T>::destroy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
POA_CORBA_IDLType_tie<T>::POA_CORBA_IDLType_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_IDLType_tie<T>::POA_CORBA_IDLType_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_IDLType_tie<T>::POA_CORBA_IDLType_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_IDLType_tie<T>::POA_CORBA_IDLType_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_IDLType_tie<T>::~POA_CORBA_IDLType_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA_IDLType_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA_IDLType_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA_IDLType_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA_IDLType_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA_IDLType_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA_IDLType_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->POA_CORBA_IDLType::_default_POA (ACE_TRY_ENV);
}

template <class T> ACE_INLINE
CORBA::TypeCode_ptr POA_CORBA_IDLType_tie<T>::type  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->type (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::DefinitionKind POA_CORBA_IDLType_tie<T>::def_kind  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->def_kind (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_IDLType_tie<T>::destroy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
POA_CORBA_TypedefDef_tie<T>::POA_CORBA_TypedefDef_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_TypedefDef_tie<T>::POA_CORBA_TypedefDef_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA_TypedefDef_tie<T>::POA_CORBA_TypedefDef_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_TypedefDef_tie<T>::POA_CORBA_TypedefDef_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA_TypedefDef_tie<T>::~POA_CORBA_TypedefDef_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA_TypedefDef_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA_TypedefDef_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA_TypedefDef_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA_TypedefDef_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA_TypedefDef_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA_TypedefDef_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->POA_CORBA_TypedefDef::_default_POA (ACE_TRY_ENV);
}

template <class T> ACE_INLINE
char * POA_CORBA_TypedefDef_tie<T>::id  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->id (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_TypedefDef_tie<T>::id  (
    const char * id,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->id (
id,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
char * POA_CORBA_TypedefDef_tie<T>::name  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->name (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_TypedefDef_tie<T>::name  (
    const char * name,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->name (
name,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
char * POA_CORBA_TypedefDef_tie<T>::version  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->version (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_TypedefDef_tie<T>::version  (
    const char * version,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->version (
version,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_Container_ptr POA_CORBA_TypedefDef_tie<T>::defined_in  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->defined_in (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
char * POA_CORBA_TypedefDef_tie<T>::absolute_name  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->absolute_name (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_Repository_ptr POA_CORBA_TypedefDef_tie<T>::containing_repository  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->containing_repository (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA_Contained::Description * POA_CORBA_TypedefDef_tie<T>::describe  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->describe (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_TypedefDef_tie<T>::move  (
    CORBA_Container_ptr new_container,
    const char * new_name,
    const char * new_version,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->move (
new_container,
    new_name,
    new_version,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::TypeCode_ptr POA_CORBA_TypedefDef_tie<T>::type  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->type (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
CORBA::DefinitionKind POA_CORBA_TypedefDef_tie<T>::def_kind  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->def_kind (
ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_CORBA_TypedefDef_tie<T>::destroy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */