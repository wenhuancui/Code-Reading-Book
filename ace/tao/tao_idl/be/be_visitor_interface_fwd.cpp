//
// be_visitor_interface_fwd.cpp,v 1.8 2001/04/24 13:44:30 parsons Exp
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_visitor_interface_fwd.cpp
//
// = DESCRIPTION
//    Visitors for generation of code for Interface_Fwd
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include	"idl.h"
#include	"idl_extern.h"
#include	"be.h"

#include "be_visitor_interface_fwd.h"

// include all the individual files
#include "be_visitor_interface_fwd/interface_fwd_ch.cpp"
#include "be_visitor_interface_fwd/interface_fwd_ci.cpp"
#include "be_visitor_interface_fwd/cdr_op_ch.cpp"
#include "be_visitor_interface_fwd/cdr_op_ci.cpp"
#include "be_visitor_interface_fwd/any_op_ch.cpp"

ACE_RCSID(be, be_visitor_interface_fwd, "be_visitor_interface_fwd.cpp,v 1.8 2001/04/24 13:44:30 parsons Exp")
