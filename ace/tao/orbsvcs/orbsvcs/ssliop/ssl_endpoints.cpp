/* -*- C++ -*- ssl_endpoints.cpp,v 1.2 2000/09/26 03:53:02 marina Exp */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "ssl_endpoints.h"

#if !defined (__ACE_INLINE__)
#include "ssl_endpoints.i"
#endif /* !defined INLINE */


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_TAO_SSLENDPOINTSEQUENCE_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_TAO_SSLENDPOINTSEQUENCE_CS_

  void
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::_allocate_buffer (CORBA::ULong length)
  {
    SSLIOP::SSL* tmp = 0;
    tmp = _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::allocbuf (length);

    if (this->buffer_ != 0)
    {
      SSLIOP::SSL *old = ACE_reinterpret_cast (SSLIOP::SSL *,this->buffer_);

      for (CORBA::ULong i = 0; i < this->length_; ++i)
        tmp[i] = old[i];

      if (this->release_)
        _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::freebuf (old);

    }
    this->buffer_ = tmp;
  }

  void
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::_deallocate_buffer (void)
  {
    if (this->buffer_ == 0 || this->release_ == 0)
      return;

    SSLIOP::SSL *tmp = ACE_reinterpret_cast (SSLIOP::SSL *,this->buffer_);

    _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::freebuf (tmp);
    this->buffer_ = 0;
  }

  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::~_TAO_Unbounded_Sequence_TAO_SSLEndpointSequence (void) // Dtor.
  {
    this->_deallocate_buffer ();
  }


#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_TAO_SSLENDPOINTSEQUENCE_CS_)
#define _TAO_SSLENDPOINTSEQUENCE_CS_

// *************************************************************
// TAO_SSLEndpointSequence
// *************************************************************

TAO_SSLEndpointSequence::TAO_SSLEndpointSequence (void)
{}
TAO_SSLEndpointSequence::TAO_SSLEndpointSequence (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<SSLIOP::SSL>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
TAO_SSLEndpointSequence::TAO_SSLEndpointSequence (CORBA::ULong max, CORBA::ULong length, SSLIOP::SSL *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<SSLIOP::SSL>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
TAO_SSLEndpointSequence::TAO_SSLEndpointSequence (const TAO_SSLEndpointSequence &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<SSLIOP::SSL>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
TAO_SSLEndpointSequence::~TAO_SSLEndpointSequence (void) // dtor
{}
void TAO_SSLEndpointSequence::_tao_any_destructor (void *x)
{
  TAO_SSLEndpointSequence *tmp = ACE_static_cast (TAO_SSLEndpointSequence*,x);
  delete tmp;
}


#endif /* end #if !defined */

static const CORBA::Long _oc_TAO_SSLEndpointSequence[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  32, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x53534c45), ACE_NTOHL (0x6e64706f), ACE_NTOHL (0x696e7453), ACE_NTOHL (0x65717565), ACE_NTOHL (0x6e63653a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:TAO_SSLEndpointSequence:1.0
  24, ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x53534c45), ACE_NTOHL (0x6e64706f), ACE_NTOHL (0x696e7453), ACE_NTOHL (0x65717565), ACE_NTOHL (0x6e636500),  // name = TAO_SSLEndpointSequence
  CORBA::tk_sequence, // typecode kind
  296, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
    280, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      27, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x53534c49), ACE_NTOHL (0x4f502f53), ACE_NTOHL (0x534c3a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/SSLIOP/SSL:1.0
      4, ACE_NTOHL (0x53534c00),  // name = SSL
      3, // member count
      16, ACE_NTOHL (0x74617267), ACE_NTOHL (0x65745f73), ACE_NTOHL (0x7570706f), ACE_NTOHL (0x72747300),  // name = target_supports
      CORBA::tk_alias, // typecode kind for typedefs
      80, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        44, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x53656375), ACE_NTOHL (0x72697479), ACE_NTOHL (0x2f417373), ACE_NTOHL (0x6f636961), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x4f707469), ACE_NTOHL (0x6f6e733a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/Security/AssociationOptions:1.0
        19, ACE_NTOHL (0x4173736f), ACE_NTOHL (0x63696174), ACE_NTOHL (0x696f6e4f), ACE_NTOHL (0x7074696f), ACE_NTOHL (0x6e730000),  // name = AssociationOptions
        CORBA::tk_ushort,


      16, ACE_NTOHL (0x74617267), ACE_NTOHL (0x65745f72), ACE_NTOHL (0x65717569), ACE_NTOHL (0x72657300),  // name = target_requires
      CORBA::tk_alias, // typecode kind for typedefs
      80, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        44, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x53656375), ACE_NTOHL (0x72697479), ACE_NTOHL (0x2f417373), ACE_NTOHL (0x6f636961), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x4f707469), ACE_NTOHL (0x6f6e733a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/Security/AssociationOptions:1.0
        19, ACE_NTOHL (0x4173736f), ACE_NTOHL (0x63696174), ACE_NTOHL (0x696f6e4f), ACE_NTOHL (0x7074696f), ACE_NTOHL (0x6e730000),  // name = AssociationOptions
        CORBA::tk_ushort,


      5, ACE_NTOHL (0x706f7274), ACE_NTOHL (0x0),  // name = port
      CORBA::tk_ushort,


    0U,

};
static CORBA::TypeCode _tc_TAO_tc_TAO_SSLEndpointSequence (CORBA::tk_alias, sizeof (_oc_TAO_SSLEndpointSequence), (char *) &_oc_TAO_SSLEndpointSequence, 0, sizeof (TAO_SSLEndpointSequence));
CORBA::TypeCode_ptr _tc_TAO_SSLEndpointSequence = &_tc_TAO_tc_TAO_SSLEndpointSequence;

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_SSLEndpointSequence &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm << _tao_sequence[i]);
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO_SSLEndpointSequence &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // If length is 0 we return true.
    if (0 >= _tao_seq_len)
      return 1;
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm >> _tao_sequence[i]);
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}
