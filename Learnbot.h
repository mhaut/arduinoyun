// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice-E is licensed to you under the terms described in the
// ICEE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice-E version 1.3.0
// Generated from file `Learnbot.ice'

#ifndef __Learnbot_h__
#define __Learnbot_h__

#include <IceE/ProxyF.h>
#include <IceE/ObjectF.h>
#include <IceE/Exception.h>
#include <IceE/ScopedArray.h>
#include <IceE/Proxy.h>
#include <IceE/Object.h>
#ifndef ICEE_PURE_CLIENT
#  include <IceE/Incoming.h>
#endif
#include <IceE/Outgoing.h>
#include <IceE/UndefSysMacros.h>

#ifndef ICEE_IGNORE_VERSION
#   if ICEE_INT_VERSION / 100 != 103
#       error IceE version mismatch!
#   endif
#   if ICEE_INT_VERSION % 100 < 0
#       error IceE patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace LearnBotComponent
{

class LearnBot;

}

}

namespace LearnBotComponent
{

class LearnBot;
bool operator==(const LearnBot&, const LearnBot&);
bool operator<(const LearnBot&, const LearnBot&);

}

namespace IceInternal
{

::Ice::Object* upCast(::LearnBotComponent::LearnBot*);
::IceProxy::Ice::Object* upCast(::IceProxy::LearnBotComponent::LearnBot*);

}

namespace LearnBotComponent
{

typedef ::IceInternal::Handle< ::LearnBotComponent::LearnBot> LearnBotPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::LearnBotComponent::LearnBot> LearnBotPrx;

void __read(::IceInternal::BasicStream*, LearnBotPrx&);
void __patch__LearnBotPtr(void*, ::Ice::ObjectPtr&);

}

namespace LearnBotComponent
{

}

namespace LearnBotComponent
{

class LearnBot : virtual public ::Ice::Object
{
public:

    typedef LearnBotPrx ProxyType;
    typedef LearnBotPtr PointerType;
    

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::std::string getUltraSound(const ::Ice::Current& = ::Ice::Current()) = 0;
#ifndef ICEE_PURE_CLIENT
    ::Ice::DispatchStatus ___getUltraSound(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
};

}

namespace IceProxy
{

namespace LearnBotComponent
{

class LearnBot : virtual public ::IceProxy::Ice::Object
{
public:

    ::std::string getUltraSound()
    {
        return getUltraSound(0);
    }
    ::std::string getUltraSound(const ::Ice::Context& __ctx)
    {
        return getUltraSound(&__ctx);
    }
    
private:

    ::std::string getUltraSound(const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<LearnBot> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<LearnBot> ice_secure(bool __secure) const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
#ifdef ICEE_HAS_ROUTER
    ::IceInternal::ProxyHandle<LearnBot> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
#endif // ICEE_HAS_ROUTER
    
#ifdef ICEE_HAS_LOCATOR
    ::IceInternal::ProxyHandle<LearnBot> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<LearnBot> ice_adapterId(const std::string& __id) const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
#endif // ICEE_HAS_LOCATOR
    
    ::IceInternal::ProxyHandle<LearnBot> ice_twoway() const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<LearnBot> ice_oneway() const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<LearnBot> ice_batchOneway() const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<LearnBot> ice_datagram() const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<LearnBot> ice_batchDatagram() const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<LearnBot> ice_timeout(int __timeout) const
    {
        return dynamic_cast<LearnBot*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    static const ::std::string& ice_staticId();
    
private:
    
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

#endif
