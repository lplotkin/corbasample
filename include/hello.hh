// This file is generated by omniidl (C++ backend)- omniORB_4_2. Do not edit.
#ifndef __hello_hh__
#define __hello_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_hello
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_hello
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_hello
#endif






#ifdef USE_stub_in_nt_dll
# ifndef USE_core_stub_in_nt_dll
#  define USE_core_stub_in_nt_dll
# endif
# ifndef USE_dyn_stub_in_nt_dll
#  define USE_dyn_stub_in_nt_dll
# endif
#endif

#ifdef _core_attr
# error "A local CPP macro _core_attr has already been defined."
#else
# ifdef  USE_core_stub_in_nt_dll
#  define _core_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _core_attr
# endif
#endif

#ifdef _dyn_attr
# error "A local CPP macro _dyn_attr has already been defined."
#else
# ifdef  USE_dyn_stub_in_nt_dll
#  define _dyn_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _dyn_attr
# endif
#endif



#ifndef __hello__
#define __hello__
class hello;
class _objref_hello;
class _impl_hello;

typedef _objref_hello* hello_ptr;
typedef hello_ptr helloRef;

class hello_Helper {
public:
  typedef hello_ptr _ptr_type;

  static _ptr_type _nil();
  static _CORBA_Boolean is_nil(_ptr_type);
  static void release(_ptr_type);
  static void duplicate(_ptr_type);
  static void marshalObjRef(_ptr_type, cdrStream&);
  static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var<_objref_hello, hello_Helper> hello_var;
typedef _CORBA_ObjRef_OUT_arg<_objref_hello,hello_Helper > hello_out;

#endif

// interface hello
class hello {
public:
  // Declarations for this interface type.
  typedef hello_ptr _ptr_type;
  typedef hello_var _var_type;

  static _ptr_type _duplicate(_ptr_type);
  static _ptr_type _narrow(::CORBA::Object_ptr);
  static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
  
  static _ptr_type _nil();

  static inline void _marshalObjRef(_ptr_type, cdrStream&);

  static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
    omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
    if (o)
      return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
    else
      return _nil();
  }

  static inline _ptr_type _fromObjRef(omniObjRef* o) {
    if (o)
      return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
    else
      return _nil();
  }

  static _core_attr const char* _PD_repoId;

  // Other IDL defined within this scope.
  
};

class _objref_hello :
  public virtual ::CORBA::Object,
  public virtual omniObjRef
{
public:
  // IDL operations
  char* sayHello(const char* msg);

  // Constructors
  inline _objref_hello()  { _PR_setobj(0); }  // nil
  _objref_hello(omniIOR*, omniIdentity*);

protected:
  virtual ~_objref_hello();

  
private:
  virtual void* _ptrToObjRef(const char*);

  _objref_hello(const _objref_hello&);
  _objref_hello& operator = (const _objref_hello&);
  // not implemented

  friend class hello;
};

class _pof_hello : public _OMNI_NS(proxyObjectFactory) {
public:
  inline _pof_hello() : _OMNI_NS(proxyObjectFactory)(hello::_PD_repoId) {}
  virtual ~_pof_hello();

  virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
  virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_hello :
  public virtual omniServant
{
public:
  virtual ~_impl_hello();

  virtual char* sayHello(const char* msg) = 0;
  
public:  // Really protected, workaround for xlC
  virtual _CORBA_Boolean _dispatch(omniCallHandle&);

private:
  virtual void* _ptrToInterface(const char*);
  virtual const char* _mostDerivedRepoId();
  
};




class POA_hello :
  public virtual _impl_hello,
  public virtual ::PortableServer::ServantBase
{
public:
  virtual ~POA_hello();

  inline ::hello_ptr _this() {
    return (::hello_ptr) _do_this(::hello::_PD_repoId);
  }
};







#undef _core_attr
#undef _dyn_attr



inline void
hello::_marshalObjRef(::hello_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}



#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_hello
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_hello
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_hello
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_hello
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_hello
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_hello
#endif

#endif  // __hello_hh__

