// rettype_is.cpp,v 1.4 1999/08/17 02:16:12 parsons Exp

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    rettype.cpp
//
// = DESCRIPTION
//    Visitor generating code for return type of the Operation node
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include	"idl.h"
#include	"idl_extern.h"
#include	"be.h"

#include "be_visitor_operation.h"

ACE_RCSID(be_visitor_operation, rettype_is, "rettype_is.cpp,v 1.4 1999/08/17 02:16:12 parsons Exp")


// ****************************************************************************
// Operation visitor for return types. This generates the mapping for a return
// type in an operation signature
// ****************************************************************************

be_visitor_operation_rettype_is::be_visitor_operation_rettype_is (be_visitor_context
                                                            *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_operation_rettype_is::~be_visitor_operation_rettype_is (void)
{
}

int
be_visitor_operation_rettype_is::visit_array (be_array *)
{


  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream
  *os << "return 0;" <<be_nl;
  return 0;
}

int
be_visitor_operation_rettype_is::visit_enum (be_enum *)
{

  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream
  *os << "return 0;" <<be_nl;
  return 0;
}

int
be_visitor_operation_rettype_is::visit_interface (be_interface *)
{

  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream
   *os << "return 0;" <<be_nl;
  return 0;
}

int
be_visitor_operation_rettype_is::visit_interface_fwd (be_interface_fwd *)
{

  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream

  *os << "return 0;" <<be_nl;
  return 0;
}

int
be_visitor_operation_rettype_is::visit_native (be_native *)
{

  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream

  *os << "return 0;" <<be_nl;
  return 0;
}

int
be_visitor_operation_rettype_is::visit_predefined_type (be_predefined_type *node)
{

  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream

  switch (node->pt ())
    {
    case AST_PredefinedType::PT_void:
        *os << "return;" <<be_nl;
        break;
    default:
      *os << "return 0;" <<be_nl;
      break;
    }

  return 0;
}

int
be_visitor_operation_rettype_is::visit_sequence (be_sequence *)
{


  // we should never directly be here because anonymous sequence return types
  // are not allowed
  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream

  *os << "return 0;" <<be_nl;
  return 0;
}

int
be_visitor_operation_rettype_is::visit_string (be_string *)
{

  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream


  *os << "return 0;" <<be_nl;
  return 0;
}

int
be_visitor_operation_rettype_is::visit_structure (be_structure *)
{

  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream
  
  *os << "return 0;" <<be_nl;
  return 0;
}

int
be_visitor_operation_rettype_is::visit_typedef (be_typedef *node)
{

  this->ctx_->alias (node); // set the alias node
  if (node->primitive_base_type ()->accept (this) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_operation_rettype::"
                         "visit_typedef - "
                         "accept on primitive type failed\n"),
                        -1);
    }
  this->ctx_->alias (0);
  return 0;
}

int
be_visitor_operation_rettype_is::visit_union (be_union *)
{

  TAO_OutStream *os = this->ctx_->stream (); // grab the out stream

  *os << "return 0;" <<be_nl;

  return 0;
}
