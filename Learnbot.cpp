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

#include "Learnbot.h"
#include <IceE/LocalException.h>
#include <IceE/ObjectFactory.h>
#include <IceE/BasicStream.h>
#include <IceE/Iterator.h>

#ifndef ICEE_IGNORE_VERSION
#   if ICEE_INT_VERSION / 100 != 103
#       error IceE version mismatch!
#   endif
#   if ICEE_INT_VERSION % 100 < 0
#       error IceE patch level mismatch!
#   endif
#endif

static const ::std::string __LearnBotComponent__LearnBot__getUltraSound_name = "getUltraSound";

::Ice::Object* IceInternal::upCast(::LearnBotComponent::LearnBot* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::LearnBotComponent::LearnBot* p) { return p; }

void
LearnBotComponent::__read(::IceInternal::BasicStream* __is, ::LearnBotComponent::LearnBotPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::LearnBotComponent::LearnBot;
        v->__copyFrom(proxy);
    }
}

static const ::std::string __LearnBotComponent__LearnBot_ids[2] =
{
    "::Ice::Object",
    "::LearnBotComponent::LearnBot"
};

bool
LearnBotComponent::LearnBot::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__LearnBotComponent__LearnBot_ids, __LearnBotComponent__LearnBot_ids + 2, _s);
}

::std::vector< ::std::string>
LearnBotComponent::LearnBot::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__LearnBotComponent__LearnBot_ids[0], &__LearnBotComponent__LearnBot_ids[2]);
}

const ::std::string&
LearnBotComponent::LearnBot::ice_id(const ::Ice::Current&) const
{
    return __LearnBotComponent__LearnBot_ids[1];
}

const ::std::string&
LearnBotComponent::LearnBot::ice_staticId()
{
    return __LearnBotComponent__LearnBot_ids[1];
}

#ifndef ICEE_PURE_CLIENT
::Ice::DispatchStatus
LearnBotComponent::LearnBot::___getUltraSound(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = getUltraSound(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
static ::std::string __LearnBotComponent__LearnBot_all[] =
{
    "getUltraSound",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
LearnBotComponent::LearnBot::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__LearnBotComponent__LearnBot_all, __LearnBotComponent__LearnBot_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __LearnBotComponent__LearnBot_all)
    {
        case 0:
        {
            return ___getUltraSound(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}
#endif // ICEE_PURE_CLIENT

void
LearnBotComponent::LearnBot::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
    ::Ice::Object::__write(__os);
}

void
LearnBotComponent::LearnBot::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
    ::Ice::Object::__read(__is, true);
}


bool
LearnBotComponent::operator==(const ::LearnBotComponent::LearnBot& l, const ::LearnBotComponent::LearnBot& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
LearnBotComponent::operator<(const ::LearnBotComponent::LearnBot& l, const ::LearnBotComponent::LearnBot& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

void 
LearnBotComponent::__patch__LearnBotPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::LearnBotComponent::LearnBotPtr* p = static_cast< ::LearnBotComponent::LearnBotPtr*>(__addr);
    assert(p);
    *p = ::LearnBotComponent::LearnBotPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::LearnBotComponent::LearnBot::ice_staticId(), v->ice_id());
    }
}

::std::string
IceProxy::LearnBotComponent::LearnBot::getUltraSound(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::RequestHandlerPtr __handler;
        try
        {
            __checkTwowayOnly(__LearnBotComponent__LearnBot__getUltraSound_name);
            __handler = __getRequestHandler();
            ::IceInternal::Outgoing __outS(__handler.get(), _reference.get(), __LearnBotComponent__LearnBot__getUltraSound_name, ::Ice::Normal, __ctx);
            bool __ok = __outS.invoke();
            try
            {
                if(!__ok)
                {
                    __outS.is()->throwUnknownUserException();
                }
                ::std::string __ret;
                ::IceInternal::BasicStream* __is = __outS.is();
                __is->read(__ret);
                return __ret;
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
            catch(...)
            {
                throw;
            }
#endif
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__handler, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__handler, __ex, __cnt);
        }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
        catch(...)
        {
            throw;
        }
#endif
    }
}

const ::std::string&
IceProxy::LearnBotComponent::LearnBot::ice_staticId()
{
    return __LearnBotComponent__LearnBot_ids[1];
}

::IceProxy::Ice::Object*
IceProxy::LearnBotComponent::LearnBot::__newInstance() const
{
    return new LearnBot;
}
