#include <Python.h>

void print_python_list(PyObject *p)
{
    Py_ssize_t size;
    Py_ssize_t i;
    PyObject *item;

    size = PyList_Size(p);

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

void print_python_bytes(PyObject *p)
{
    Py_ssize_t size;
    Py_ssize_t i;

    if (!PyBytes_Check(p))
    {
        printf("[.] bytes object info\n");
        printf("[ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", PyBytes_AsString(p));
    printf("  first %ld bytes:", size < 10 ? size : 10);

    for (i = 0; i < size && i < 10; i++)
        printf(" %02x", (unsigned char)PyBytes_AsString(p)[i]);
    printf("\n");
}

