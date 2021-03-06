/* -*- c++ -*- */
//
// be_visitor_typedef.h,v 1.6 1999/05/28 02:16:45 coryan Exp
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_visitor_typedef.h
//
// = DESCRIPTION
//    Concrete visitor for the Typedef class
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#ifndef TAO_BE_VISITOR_TYPEDEF_H
#define TAO_BE_VISITOR_TYPEDEF_H

#include "be_visitor.h"
#include "be_visitor_scope.h"

// generic visitor
#include "be_visitor_typedef/typedef.h"
// concrete visitors
#include "be_visitor_typedef/typedef_ch.h"
#include "be_visitor_typedef/typedef_ci.h"
#include "be_visitor_typedef/typedef_cs.h"
#include "be_visitor_typedef/any_op_ch.h"
#include "be_visitor_typedef/any_op_cs.h"
#include "be_visitor_typedef/cdr_op_ch.h"
#include "be_visitor_typedef/cdr_op_ci.h"
#include "be_visitor_typedef/cdr_op_cs.h"

#endif // TAO_BE_VISITOR_TYPEDEF_H
