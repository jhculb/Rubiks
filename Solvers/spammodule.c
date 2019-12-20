#define PY_SSIZE_T_CLEAN
#include <Python.h>

//1.1
static PyObject *SpamError;

PyMODINIT_FUNC PyInit_spam(void){

  PyObject *m;

  m = PyModule_Create(&spammodule);
  ir(m==NULL){
    return NULL;
  }

  SpamError = PyErr_NewException("spam.error",NULL, NULL);
  Py_XINCREF(SpamError);
  if(PyModule_AddObject(m,"error",SpamError)<0){
    Py_XDECREF(SpamError);
    Py_CLEAR(SpamError);
    Py_DECREF(m);
    return NULL;
  }
}


//1.2
static Pyobject *
spam_system(PyObject *self, PyObject *args){
  //Self points to module object for module-level functions
  //For method it points to object instance


  const char *command;
  inst sts;
  if(!PyArg_ParseTuple(arg, "s", &command)){
    return null;
  }
  sts = system(command);
  // Post 1.1
  if(sts<0){
    PyErr_SetString(SpamError,"System command failed");
    return NULL;
  }
  return PyLong_FromLong(sts);
}
