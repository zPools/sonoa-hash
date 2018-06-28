#include <Python.h>

#include "sonoa.h"

static PyObject *sonoa_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    sonoa_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    sonoa_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef SonoAMethods[] = {
    { "getPoWHash", sonoa_getpowhash, METH_VARARGS, "Returns the proof of work hash using sonoa hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef SonoAModule = {
    PyModuleDef_HEAD_INIT,
    "sonoa_hash",
    "...",
    -1,
    SonoAMethods
};

PyMODINIT_FUNC PyInit_sonoa_hash(void) {
    return PyModule_Create(&SonoAModule);
}

#else

PyMODINIT_FUNC initsonoa_hash(void) {
    (void) Py_InitModule("sonoa_hash", SonoAMethods);
}
#endif
