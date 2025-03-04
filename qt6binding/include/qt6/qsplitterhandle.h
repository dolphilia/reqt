#ifndef QT6_QSPLITTERHANDLE_H
#define QT6_QSPLITTERHANDLE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief QSplitterHandle_create creates a new QSplitterHandle
 * @param orientation the orientation of the splitter handle
 * @param parent the parent QSplitter
 * @return a pointer to the created QSplitterHandle
 */
void* QSplitterHandle_create(int orientation, void* parent);

/**
 * @brief QSplitterHandle_delete deletes a QSplitterHandle
 * @param splitterHandle the QSplitterHandle to delete
 */
void QSplitterHandle_delete(void* splitterHandle);

/**
 * @brief QSplitterHandle_opaqueResize returns whether the splitter handle has opaque resize
 * @param splitterHandle the QSplitterHandle
 * @return 1 if opaque resize is enabled, 0 otherwise
 */
int QSplitterHandle_opaqueResize(void* splitterHandle);

/**
 * @brief QSplitterHandle_setOpaqueResize sets whether the splitter handle has opaque resize
 * @param splitterHandle the QSplitterHandle
 * @param opaque 1 to enable opaque resize, 0 to disable
 */
void QSplitterHandle_setOpaqueResize(void* splitterHandle, bool opaque);

/**
 * @brief QSplitterHandle_orientation returns the orientation of the splitter handle
 * @param splitterHandle the QSplitterHandle
 * @return the orientation (1 for horizontal, 2 for vertical)
 */
int QSplitterHandle_orientation(void* splitterHandle);

/**
 * @brief QSplitterHandle_setOrientation sets the orientation of the splitter handle
 * @param splitterHandle the QSplitterHandle
 * @param orientation the orientation (1 for horizontal, 2 for vertical)
 */
void QSplitterHandle_setOrientation(void* splitterHandle, int orientation);

/**
 * @brief QSplitterHandle_splitter returns the parent splitter
 * @param splitterHandle the QSplitterHandle
 * @return a pointer to the parent QSplitter
 */
void* QSplitterHandle_splitter(void* splitterHandle);

/**
 * @brief Callback function type for the moved signal
 */
typedef void (*QSplitterHandle_MovedCallback)(void*);

/**
 * @brief Callback function type for the pressed signal
 */
typedef void (*QSplitterHandle_PressedCallback)(void*);

/**
 * @brief Callback function type for the released signal
 */
typedef void (*QSplitterHandle_ReleasedCallback)(void*);

/**
 * @brief QSplitterHandle_setMovedCallback sets the callback for the moved signal
 * @param splitterHandle the QSplitterHandle
 * @param callback the callback function
 */
void QSplitterHandle_setMovedCallback(void* splitterHandle, QSplitterHandle_MovedCallback callback);

/**
 * @brief QSplitterHandle_setPressedCallback sets the callback for the pressed signal
 * @param splitterHandle the QSplitterHandle
 * @param callback the callback function
 */
void QSplitterHandle_setPressedCallback(void* splitterHandle, QSplitterHandle_PressedCallback callback);

/**
 * @brief QSplitterHandle_setReleasedCallback sets the callback for the released signal
 * @param splitterHandle the QSplitterHandle
 * @param callback the callback function
 */
void QSplitterHandle_setReleasedCallback(void* splitterHandle, QSplitterHandle_ReleasedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // QT6_QSPLITTERHANDLE_H
