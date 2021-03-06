/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   CEC_ProxyPullSupplier.h
 *
 *  CEC_ProxyPullSupplier.h,v 1.12 2001/09/18 19:10:38 coryan Exp
 *
 *  @author Carlos O'Ryan (coryan@cs.wustl.edu)
 */
//=============================================================================


#ifndef TAO_CEC_PROXYPULLSUPPLIER_H
#define TAO_CEC_PROXYPULLSUPPLIER_H
#include "ace/pre.h"

#include "orbsvcs/CosEventChannelAdminS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Message_Queue.h"
#include "event_export.h"

class TAO_CEC_EventChannel;
class TAO_CEC_ProxyPullConsumer;

/**
 * @class TAO_CEC_ProxyPullSupplier
 *
 * @brief ProxyPullSupplier
 *
 * Implement the CosEventChannelAdmin::ProxyPullSupplier interface,
 * remember that this class is used to communicate with a
 * PullConsumer, so, in effect, this is the ambassador for a
 * consumer inside the event channel.
 * = MEMORY MANAGMENT
 * It does not assume ownership of the TAO_CEC_Dispatching object.
 * It makes a copy of the ConsumerQOS and the consumer object
 * reference.
 * = LOCKING
 * Locking is strategized, the event channel acts as a factory for
 * the locking strategies.
 */
class TAO_Event_Export TAO_CEC_ProxyPullSupplier : public POA_CosEventChannelAdmin::ProxyPullSupplier
{
public:
  typedef CosEventChannelAdmin::ProxyPullSupplier_ptr _ptr_type;
  typedef CosEventChannelAdmin::ProxyPullSupplier_var _var_type;

  /// constructor...
  TAO_CEC_ProxyPullSupplier (TAO_CEC_EventChannel* event_channel);

  /// destructor...
  virtual ~TAO_CEC_ProxyPullSupplier (void);

  /// Activate in the POA
  virtual CosEventChannelAdmin::ProxyPullSupplier_ptr activate (CORBA::Environment &ACE_TRY_ENV) ACE_THROW_SPEC ((CORBA::SystemException));

  /// Deactivate from the POA
  virtual void deactivate (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return 0 if no consumer is connected...
  CORBA::Boolean is_connected (void) const;

  /**
   * Return the consumer object reference. It returns nil() if it has
   * not connected yet.
   * NOTE: This method does not return a new reference!!! Doing so
   * will increase the locking overhead on the critical path.
   */
  CosEventComm::PullConsumer_ptr consumer (void) const;

  /// The event channel is shutting down
  virtual void shutdown (CORBA::Environment &env);

  /**
   * Invoke the _non_existent() pseudo-operation on the consumer. If
   * it is disconnected then it returns true and sets the
   * <disconnected> flag.
   */
  CORBA::Boolean consumer_non_existent (CORBA::Boolean_out disconnected,
                                        CORBA::Environment &ACE_TRY_ENV);

  /// Push an event into the queue.
  void push (const CORBA::Any &event,
             CORBA::Environment &ACE_TRY_ENV);

  // = The CosEventChannelAdmin::ProxyPullSupplier methods...
  virtual void connect_pull_consumer (
                CosEventComm::PullConsumer_ptr pull_consumer,
                CORBA::Environment &)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       CosEventChannelAdmin::AlreadyConnected));
  virtual CORBA::Any * pull (CORBA::Environment &)
      ACE_THROW_SPEC ((CORBA::SystemException,CosEventComm::Disconnected));
  virtual CORBA::Any * try_pull (CORBA::Boolean_out has_event,
                                 CORBA::Environment &)
      ACE_THROW_SPEC ((CORBA::SystemException,CosEventComm::Disconnected));
  virtual void disconnect_pull_supplier (CORBA::Environment &)
      ACE_THROW_SPEC ((CORBA::SystemException));

  /// Increment and decrement the reference count.
  CORBA::ULong _incr_refcnt (void);
  CORBA::ULong _decr_refcnt (void);

  // = The Servant methods
  virtual PortableServer::POA_ptr _default_POA (CORBA::Environment &env);
  virtual void _add_ref (CORBA_Environment &ACE_TRY_ENV);
  virtual void _remove_ref (CORBA_Environment &ACE_TRY_ENV);

protected:
  /// Set the consumer, used by some implementations to change the
  /// policies used when invoking operations on the consumer.
  void consumer (CosEventComm::PullConsumer_ptr consumer);
  void consumer_i (CosEventComm::PullConsumer_ptr consumer);

  /// The private version (without locking) of is_connected().
  CORBA::Boolean is_connected_i (void) const;

  /// Release the child and the consumer
  void cleanup_i (void);

private:
  /// The Event Channel that owns this object.
  TAO_CEC_EventChannel* event_channel_;

  /// The locking strategy.
  ACE_Lock* lock_;

  /// The reference count.
  CORBA::ULong refcount_;

  /// The consumer....
  CosEventComm::PullConsumer_var consumer_;

  /// If the flag is not zero then we are connected, notice that the
  /// consumer can be nil.
  int connected_;

  /// Store the default POA.
  PortableServer::POA_var default_POA_;

  /// Use a message queue to pass the
  TAO_SYNCH_MUTEX queue_lock_;
  TAO_SYNCH_CONDITION wait_not_empty_;
  ACE_Unbounded_Queue<CORBA::Any> queue_;
};

#if defined (__ACE_INLINE__)
#include "CEC_ProxyPullSupplier.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_CEC_PROXYPULLSUPPLIER_H */
