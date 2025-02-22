#ifndef QAPPLICATION_C_H
#define QAPPLICATION_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QApplication
void* QApplication_create(int argc, char* argv[]);
void QApplication_delete(void* app);
int QApplication_exec(void* app);

#ifdef __cplusplus
}
#endif

#endif // QAPPLICATION_C_H
