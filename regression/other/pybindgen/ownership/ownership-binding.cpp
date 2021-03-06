/* This file was generated by PyBindGen 0.0.0.0 */
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stddef.h>


#if PY_VERSION_HEX < 0x020400F0

#define PyEval_ThreadsInitialized() 1

#define Py_CLEAR(op)				\
        do {                            	\
                if (op) {			\
                        PyObject *tmp = (PyObject *)(op);	\
                        (op) = NULL;		\
                        Py_DECREF(tmp);		\
                }				\
        } while (0)


#define Py_VISIT(op)							\
        do { 								\
                if (op) {						\
                        int vret = visit((PyObject *)(op), arg);	\
                        if (vret)					\
                                return vret;				\
                }							\
        } while (0)

#endif



#if PY_VERSION_HEX < 0x020500F0

typedef int Py_ssize_t;
# define PY_SSIZE_T_MAX INT_MAX
# define PY_SSIZE_T_MIN INT_MIN
typedef inquiry lenfunc;
typedef intargfunc ssizeargfunc;
typedef intobjargproc ssizeobjargproc;

#endif


#ifndef PyVarObject_HEAD_INIT
#define PyVarObject_HEAD_INIT(type, size) \
        PyObject_HEAD_INIT(type) size,
#endif


#if PY_VERSION_HEX >= 0x03000000
#if PY_VERSION_HEX >= 0x03050000
typedef PyAsyncMethods* cmpfunc;
#else
typedef void* cmpfunc;
#endif
#define PyCObject_FromVoidPtr(a, b) PyCapsule_New(a, NULL, b)
#define PyCObject_AsVoidPtr(a) PyCapsule_GetPointer(a, NULL)
#define PyString_FromString(a) PyBytes_FromString(a)
#define Py_TPFLAGS_CHECKTYPES 0 /* this flag doesn't exist in python 3 */
#endif


#if     __GNUC__ > 2
# define PYBINDGEN_UNUSED(param) param __attribute__((__unused__))
#elif     __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
# define PYBINDGEN_UNUSED(param) __attribute__((__unused__)) param
#else
# define PYBINDGEN_UNUSED(param) param
#endif  /* !__GNUC__ */

#ifndef _PyBindGenWrapperFlags_defined_
#define _PyBindGenWrapperFlags_defined_
typedef enum _PyBindGenWrapperFlags {
   PYBINDGEN_WRAPPER_FLAG_NONE = 0,
   PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED = (1<<0),
} PyBindGenWrapperFlags;
#endif


#include "ownership.hpp"
/* --- forward declarations --- */


typedef struct {
    PyObject_HEAD
    Foo *obj;
    PyBindGenWrapperFlags flags:8;
} PyFoo;


extern PyTypeObject PyFoo_Type;



#include <map>
#include <string>
#include <typeinfo>
#if defined(__GNUC__) && __GNUC__ >= 3 && !defined(__clang__)
# include <cxxabi.h>
#endif

#define PBG_TYPEMAP_DEBUG 0

namespace pybindgen {

class TypeMap
{
   std::map<std::string, PyTypeObject *> m_map;

public:

   TypeMap() {}

   void register_wrapper(const std::type_info &cpp_type_info, PyTypeObject *python_wrapper)
   {

#if PBG_TYPEMAP_DEBUG
   std::cerr << "register_wrapper(this=" << this << ", type_name=" << cpp_type_info.name()
             << ", python_wrapper=" << python_wrapper->tp_name << ")" << std::endl;
#endif

       m_map[std::string(cpp_type_info.name())] = python_wrapper;
   }



   PyTypeObject * lookup_wrapper(const std::type_info &cpp_type_info, PyTypeObject *fallback_wrapper)
   {

#if PBG_TYPEMAP_DEBUG
   std::cerr << "lookup_wrapper(this=" << this << ", type_name=" << cpp_type_info.name() << ")" << std::endl;
#endif

       PyTypeObject *python_wrapper = m_map[cpp_type_info.name()];
       if (python_wrapper)
           return python_wrapper;
       else {
#if defined(__GNUC__) && __GNUC__ >= 3 && !defined(__clang__)

           // Get closest (in the single inheritance tree provided by cxxabi.h)
           // registered python wrapper.
           const abi::__si_class_type_info *_typeinfo =
               dynamic_cast<const abi::__si_class_type_info*> (&cpp_type_info);
#if PBG_TYPEMAP_DEBUG
          std::cerr << "  -> looking at C++ type " << _typeinfo->name() << std::endl;
#endif
           while (_typeinfo && (python_wrapper = m_map[std::string(_typeinfo->name())]) == 0) {
               _typeinfo = dynamic_cast<const abi::__si_class_type_info*> (_typeinfo->__base_type);
#if PBG_TYPEMAP_DEBUG
               std::cerr << "  -> looking at C++ type " << _typeinfo->name() << std::endl;
#endif
           }

#if PBG_TYPEMAP_DEBUG
          if (python_wrapper) {
              std::cerr << "  -> found match " << std::endl;
          } else {
              std::cerr << "  -> return fallback wrapper" << std::endl;
          }
#endif

           return python_wrapper? python_wrapper : fallback_wrapper;

#else // non gcc 3+ compilers can only match against explicitly registered classes, not hidden subclasses
           return fallback_wrapper;
#endif
       }
   }
};

}


extern pybindgen::TypeMap PyFoo__typeid_map;


typedef struct {
    PyObject_HEAD
    Zbr *obj;
    PyBindGenWrapperFlags flags:8;
} PyZbr;


extern PyTypeObject PyZbr_Type;
extern PyTypeObject PyZbrMeta_Type;


typedef struct {
    PyObject_HEAD
    SomeObject *obj;
    PyObject *inst_dict;
    PyBindGenWrapperFlags flags:8;
} PySomeObject;


extern PyTypeObject PySomeObject_Type;

/* --- module functions --- */


PyObject *
_wrap_foo_store_zbr(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyZbr *zbr;
    Zbr *zbr_ptr;
    const char *keywords[] = {"zbr", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyZbr_Type, &zbr)) {
        return NULL;
    }
    zbr_ptr = (zbr ? zbr->obj : NULL);
    if (zbr) {
        zbr->obj->Ref();
    }
    store_zbr(zbr_ptr);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}
PyObject * _wrap_foo_store_zbr(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);


PyObject *
_wrap_foo_invoke_zbr(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int retval;
    int x;
    const char *keywords[] = {"x", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &x)) {
        return NULL;
    }
    retval = invoke_zbr(x);
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}
PyObject * _wrap_foo_invoke_zbr(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);


PyObject *
_wrap_foo_delete_stored_zbr()
{
    PyObject *py_retval;

    delete_stored_zbr();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}
PyObject * _wrap_foo_delete_stored_zbr();

static PyMethodDef foo_functions[] = {
    {(char *) "store_zbr", (PyCFunction) _wrap_foo_store_zbr, METH_KEYWORDS|METH_VARARGS, "store_zbr(zbr)\n\ntype: zbr: Zbr *" },
    {(char *) "invoke_zbr", (PyCFunction) _wrap_foo_invoke_zbr, METH_KEYWORDS|METH_VARARGS, "invoke_zbr(x)\n\ntype: x: int" },
    {(char *) "delete_stored_zbr", (PyCFunction) _wrap_foo_delete_stored_zbr, METH_NOARGS, "delete_stored_zbr()\n\n" },
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */



pybindgen::TypeMap PyFoo__typeid_map;



static int
_wrap_PyFoo__tp_init__0(PyFoo *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *datum;
    Py_ssize_t datum_len;
    const char *keywords[] = {"datum", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &datum, &datum_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new Foo(std::string(datum, datum_len));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyFoo__tp_init__1(PyFoo *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new Foo();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyFoo__tp_init__2(PyFoo *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyFoo *foo;
    const char *keywords[] = {"foo", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyFoo_Type, &foo)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new Foo(*((PyFoo *) foo)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyFoo__tp_init(PyFoo *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyFoo__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyFoo__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyFoo__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


static PyObject*
_wrap_PyFoo__copy__(PyFoo *self)
{

    PyFoo *py_copy;
    py_copy = PyObject_New(PyFoo, &PyFoo_Type);
    py_copy->obj = new Foo(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return (PyObject*) py_copy;
}

static PyMethodDef PyFoo_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyFoo__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyFoo__tp_dealloc(PyFoo *self)
{
        Foo *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

PyTypeObject PyFoo_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "foo.Foo",            /* tp_name */
    sizeof(PyFoo),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyFoo__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    NULL,
#else
    (cmpfunc)NULL,           /* tp_compare */
#endif
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    "Foo(datum)\nFoo(foo)\nFoo()",                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyFoo_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyFoo__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



static PyObject* _wrap_PyZbr__get_instance_count(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;

    py_retval = Py_BuildValue((char *) "i", Zbr::instance_count);
    return py_retval;
}
static int _wrap_PyZbr__set_instance_count(PyZbr * PYBINDGEN_UNUSED(dummy), PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;

    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &Zbr::instance_count)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef ZbrMeta__getsets[] = {
    {
        (char*) "instance_count", /* attribute name */
        (getter) _wrap_PyZbr__get_instance_count, /* C function to get the attribute */
        (setter) _wrap_PyZbr__set_instance_count, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject PyZbrMeta_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
	(char *) "ZbrMeta",		        /* tp_name */
	0,					/* tp_basicsize */
	0,					/* tp_itemsize */
	0,	 				/* tp_dealloc */
	0,					/* tp_print */
	0,					/* tp_getattr */
	0,					/* tp_setattr */
	0,					/* tp_compare */
	0,					/* tp_repr */
	0,					/* tp_as_number */
	0,					/* tp_as_sequence */
	0,		       			/* tp_as_mapping */
	0,					/* tp_hash */
	0,					/* tp_call */
	0,					/* tp_str */
	0,					/* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC|Py_TPFLAGS_BASETYPE, /* tp_flags */
 	0,					/* tp_doc */
	0,					/* tp_traverse */
 	0,					/* tp_clear */
	0,					/* tp_richcompare */
	0,					/* tp_weaklistoffset */
	0,					/* tp_iter */
	0,					/* tp_iternext */
	0,					/* tp_methods */
	0,					/* tp_members */
	ZbrMeta__getsets,				/* tp_getset */
	0,					/* tp_base */
	0,					/* tp_dict */
	0,	                                /* tp_descr_get */
	0,  		                        /* tp_descr_set */
	0,					/* tp_dictoffset */
	0,					/* tp_init */
	0,					/* tp_alloc */
	0,					/* tp_new */
	0,               			/* tp_free */
        0,                                      /* tp_is_gc */
        0,                                      /* tp_bases */
        0,                                      /* tp_mro */
        0,                                      /* tp_cache */
        0,                                      /* tp_subclasses */
        0,                                      /* tp_weaklist */
        0                                       /* tp_del */
};



static int
_wrap_PyZbr__tp_init__0(PyZbr *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new Zbr();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyZbr__tp_init__1(PyZbr *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *datum;
    Py_ssize_t datum_len;
    const char *keywords[] = {"datum", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &datum, &datum_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new Zbr(std::string(datum, datum_len));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyZbr__tp_init(PyZbr *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyZbr__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyZbr__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyZbr_get_datum(PyZbr *self)
{
    PyObject *py_retval;
    std::string retval;

    retval = self->obj->get_datum();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyZbr_get_int(PyZbr *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int retval;
    int x;
    const char *keywords[] = {"x", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &x)) {
        return NULL;
    }
    retval = self->obj->get_int(x);
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyZbr_get_value(PyZbr *self)
{
    PyObject *py_retval;
    int retval;
    int  x;

    retval = self->obj->get_value(&x);
    py_retval = Py_BuildValue((char *) "ii", retval, x);
    return py_retval;
}

static PyMethodDef PyZbr_methods[] = {
    {(char *) "get_datum", (PyCFunction) _wrap_PyZbr_get_datum, METH_NOARGS, "get_datum()\n\n" },
    {(char *) "get_int", (PyCFunction) _wrap_PyZbr_get_int, METH_KEYWORDS|METH_VARARGS, "get_int(x)\n\ntype: x: int" },
    {(char *) "get_value", (PyCFunction) _wrap_PyZbr_get_value, METH_NOARGS, "get_value(x)\n\ntype: x: int *" },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyZbr__tp_dealloc(PyZbr *self)
{
    if (self->obj) {
        Zbr *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

PyTypeObject PyZbr_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "foo.Zbr",            /* tp_name */
    sizeof(PyZbr),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyZbr__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    NULL,
#else
    (cmpfunc)NULL,           /* tp_compare */
#endif
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    "Zbr(datum)\nZbr()",                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyZbr_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyZbr__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static int
_wrap_PySomeObject__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'SomeObject' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PySomeObject_set_foo_ptr(PySomeObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyFoo *foo;
    Foo *foo_ptr;
    const char *keywords[] = {"foo", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyFoo_Type, &foo)) {
        return NULL;
    }
    foo_ptr = (foo ? foo->obj : NULL);
    self->obj->set_foo_ptr(foo_ptr);
    if (foo) {
        foo->obj = NULL;
    }
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PySomeObject_set_foo_shared_ptr(PySomeObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyFoo *foo;
    Foo *foo_ptr;
    const char *keywords[] = {"foo", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyFoo_Type, &foo)) {
        return NULL;
    }
    foo_ptr = (foo ? foo->obj : NULL);
    self->obj->set_foo_shared_ptr(foo_ptr);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PySomeObject_get_foo_shared_ptr(PySomeObject *self)
{
    PyObject *py_retval;
    Foo const *retval;
    PyFoo *py_Foo;

    retval = self->obj->get_foo_shared_ptr();
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    py_Foo = PyObject_New(PyFoo, &PyFoo_Type);
    py_Foo->obj = new Foo((*retval));
    py_Foo->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_retval = Py_BuildValue((char *) "N", py_Foo);
    return py_retval;
}


PyObject *
_wrap_PySomeObject_get_foo_ptr(PySomeObject *self)
{
    PyObject *py_retval;
    Foo *retval;
    PyFoo *py_Foo;
    PyTypeObject *wrapper_type = 0;

    retval = self->obj->get_foo_ptr();
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_type = PyFoo__typeid_map.lookup_wrapper(typeid((*retval)), &PyFoo_Type);
    py_Foo = PyObject_New(PyFoo, wrapper_type);
    py_Foo->obj = retval;
    py_Foo->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_retval = Py_BuildValue((char *) "N", py_Foo);
    return py_retval;
}

static PyMethodDef PySomeObject_methods[] = {
    {(char *) "set_foo_ptr", (PyCFunction) _wrap_PySomeObject_set_foo_ptr, METH_KEYWORDS|METH_VARARGS, "set_foo_ptr(foo)\n\ntype: foo: Foo *" },
    {(char *) "set_foo_shared_ptr", (PyCFunction) _wrap_PySomeObject_set_foo_shared_ptr, METH_KEYWORDS|METH_VARARGS, "set_foo_shared_ptr(foo)\n\ntype: foo: Foo *" },
    {(char *) "get_foo_shared_ptr", (PyCFunction) _wrap_PySomeObject_get_foo_shared_ptr, METH_NOARGS, "get_foo_shared_ptr()\n\n" },
    {(char *) "get_foo_ptr", (PyCFunction) _wrap_PySomeObject_get_foo_ptr, METH_NOARGS, "get_foo_ptr()\n\n" },
    {NULL, NULL, 0, NULL}
};

static void
PySomeObject__tp_clear(PySomeObject *self)
{
    Py_CLEAR(self->inst_dict);
        SomeObject *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PySomeObject__tp_traverse(PySomeObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);

    return 0;
}


static void
_wrap_PySomeObject__tp_dealloc(PySomeObject *self)
{
    PySomeObject__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

PyTypeObject PySomeObject_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "foo.SomeObject",            /* tp_name */
    sizeof(PySomeObject),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PySomeObject__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    NULL,
#else
    (cmpfunc)NULL,           /* tp_compare */
#endif
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    "",                        /* Documentation string */
    (traverseproc)PySomeObject__tp_traverse,     /* tp_traverse */
    (inquiry)PySomeObject__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PySomeObject_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PySomeObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PySomeObject__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef foo_moduledef = {
    PyModuleDef_HEAD_INIT,
    "foo",
    NULL,
    -1,
    foo_functions,
};
#endif


#if PY_VERSION_HEX >= 0x03000000
    #define MOD_ERROR NULL
    #define MOD_INIT(name) PyObject* PyInit_##name(void)
    #define MOD_RETURN(val) val
#else
    #define MOD_ERROR
    #define MOD_INIT(name) void init##name(void)
    #define MOD_RETURN(val)
#endif
#if defined(__cplusplus)
extern "C"
#endif
#if defined(__GNUC__) && __GNUC__ >= 4
__attribute__ ((visibility("default")))
#endif


MOD_INIT(foo)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&foo_moduledef);
    #else
    m = Py_InitModule3((char *) "foo", foo_functions, NULL);
    #endif
    if (m == NULL) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "_PyFoo__typeid_map", PyCObject_FromVoidPtr(&PyFoo__typeid_map, NULL));
    PyFoo__typeid_map.register_wrapper(typeid(Foo), &PyFoo_Type);
    /* Register the 'Foo' class */
    if (PyType_Ready(&PyFoo_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Foo", (PyObject *) &PyFoo_Type);
    /* Register the 'Zbr' class */

    PyZbrMeta_Type.tp_base = Py_TYPE(&PyBaseObject_Type);
    /* Some fields need to be manually inheritted from the parent metaclass */
    PyZbrMeta_Type.tp_traverse = Py_TYPE(&PyBaseObject_Type)->tp_traverse;
    PyZbrMeta_Type.tp_clear = Py_TYPE(&PyBaseObject_Type)->tp_clear;
    PyZbrMeta_Type.tp_is_gc = Py_TYPE(&PyBaseObject_Type)->tp_is_gc;
    /* PyType tp_setattro is too restrictive */
    PyZbrMeta_Type.tp_setattro = PyObject_GenericSetAttr;
    PyType_Ready(&PyZbrMeta_Type);

    Py_TYPE(&PyZbr_Type) = &PyZbrMeta_Type;
    if (PyType_Ready(&PyZbr_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Zbr", (PyObject *) &PyZbr_Type);
    /* Register the 'SomeObject' class */
    if (PyType_Ready(&PySomeObject_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SomeObject", (PyObject *) &PySomeObject_Type);
    return MOD_RETURN(m);
}
