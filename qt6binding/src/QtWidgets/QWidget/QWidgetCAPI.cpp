#include "qwidget.h"
#include "QWidgetBind.h"
#include <QWidget>
#include <QLayout>
#include <QWindow>
#include <QLocale>

extern "C" {

void* QWidget_create(void* parent)
{
    return new QWidgetBind(reinterpret_cast<QWidget*>(parent));
}

void QWidget_delete(void* widget)
{
    delete static_cast<QWidgetBind*>(widget);
}

void QWidget_resize(void* widget, int w, int h)
{
    static_cast<QWidgetBind*>(widget)->resize(w, h);
}

void QWidget_move(void* widget, int x, int y)
{
    static_cast<QWidgetBind*>(widget)->move(x, y);
}

int QWidget_x(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->x();
}

int QWidget_y(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->y();
}

int QWidget_width(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->width();
}

int QWidget_height(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->height();
}

void QWidget_setFixedSize(void* widget, int w, int h)
{
    static_cast<QWidgetBind*>(widget)->setFixedSize(w, h);
}

void QWidget_setFixedHeight(void* widget, int height)
{
    static_cast<QWidgetBind*>(widget)->setFixedHeight(height);
}

void QWidget_setFixedWidth(void* widget, int width)
{
    static_cast<QWidgetBind*>(widget)->setFixedWidth(width);
}

void QWidget_show(void* widget)
{
    static_cast<QWidgetBind*>(widget)->show();
}

void QWidget_hide(void* widget)
{
    static_cast<QWidgetBind*>(widget)->hide();
}

bool QWidget_isVisible(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isVisible();
}

void QWidget_setVisible(void* widget, bool visible)
{
    static_cast<QWidgetBind*>(widget)->setVisible(visible);
}

void QWidget_setWindowTitle(void* widget, const char* title)
{
    static_cast<QWidgetBind*>(widget)->setWindowTitle(QString::fromUtf8(title));
}

const char* QWidget_windowTitle(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->windowTitle().toUtf8().constData();
}

void QWidget_setStyleSheet(void* widget, const char* styleSheet)
{
    static_cast<QWidgetBind*>(widget)->setStyleSheet(QString::fromUtf8(styleSheet));
}

const char* QWidget_styleSheet(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->styleSheet().toUtf8().constData();
}

void QWidget_setCursor(void* widget, void* cursor)
{
    static_cast<QWidgetBind*>(widget)->setCursor(*static_cast<QCursor*>(cursor));
}

void QWidget_setAutoFillBackground(void* widget, bool enabled)
{
    static_cast<QWidgetBind*>(widget)->setAutoFillBackground(enabled);
}

bool QWidget_autoFillBackground(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->autoFillBackground();
}

void QWidget_setBackgroundRole(void* widget, int role)
{
    static_cast<QWidgetBind*>(widget)->setBackgroundRole(static_cast<QPalette::ColorRole>(role));
}

int QWidget_backgroundRole(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->backgroundRole());
}

void QWidget_setForegroundRole(void* widget, int role)
{
    static_cast<QWidgetBind*>(widget)->setForegroundRole(static_cast<QPalette::ColorRole>(role));
}

int QWidget_foregroundRole(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->foregroundRole());
}

void QWidget_setLayout(void* widget, void* layout)
{
    static_cast<QWidgetBind*>(widget)->setLayout(static_cast<QLayout*>(layout));
}

// Static Public Members

void* QWidget_createWindowContainer(void* window, void* parent, int flags)
{
    return QWidget::createWindowContainer(
        static_cast<QWindow*>(window),
        static_cast<QWidget*>(parent),
        static_cast<Qt::WindowFlags>(flags)
    );
}

void* QWidget_find(unsigned long id)
{
    return QWidget::find(static_cast<WId>(id));
}

void* QWidget_keyboardGrabber()
{
    return QWidget::keyboardGrabber();
}

void* QWidget_mouseGrabber()
{
    return QWidget::mouseGrabber();
}

void QWidget_setTabOrder(void* first, void* second)
{
    QWidget::setTabOrder(
        static_cast<QWidget*>(first),
        static_cast<QWidget*>(second)
    );
}

// Properties

bool QWidget_acceptDrops(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->acceptDrops();
}

void QWidget_setAcceptDrops(void* widget, bool on)
{
    static_cast<QWidgetBind*>(widget)->setAcceptDrops(on);
}

const char* QWidget_accessibleDescription(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->accessibleDescription().toUtf8().constData();
}

void QWidget_setAccessibleDescription(void* widget, const char* description)
{
    static_cast<QWidgetBind*>(widget)->setAccessibleDescription(QString::fromUtf8(description));
}

const char* QWidget_accessibleName(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->accessibleName().toUtf8().constData();
}

void QWidget_setAccessibleName(void* widget, const char* name)
{
    static_cast<QWidgetBind*>(widget)->setAccessibleName(QString::fromUtf8(name));
}

void QWidget_setBaseSize(void* widget, int width, int height)
{
    static_cast<QWidgetBind*>(widget)->setBaseSize(width, height);
}

int QWidget_baseSizeWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->baseSize().width();
}

int QWidget_baseSizeHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->baseSize().height();
}

int QWidget_childrenRectX(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->childrenRect().x();
}

int QWidget_childrenRectY(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->childrenRect().y();
}

int QWidget_childrenRectWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->childrenRect().width();
}

int QWidget_childrenRectHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->childrenRect().height();
}

void* QWidget_childrenRegion(void* widget)
{
    QRegion* region = new QRegion(static_cast<QWidgetBind*>(widget)->childrenRegion());
    return region;
}

int QWidget_contextMenuPolicy(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->contextMenuPolicy());
}

void QWidget_setContextMenuPolicy(void* widget, int policy)
{
    static_cast<QWidgetBind*>(widget)->setContextMenuPolicy(static_cast<Qt::ContextMenuPolicy>(policy));
}

bool QWidget_isEnabled(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isEnabled();
}

void QWidget_setEnabled(void* widget, bool enable)
{
    static_cast<QWidgetBind*>(widget)->setEnabled(enable);
}

bool QWidget_hasFocus(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->hasFocus();
}

int QWidget_focusPolicy(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->focusPolicy());
}

void QWidget_setFocusPolicy(void* widget, int policy)
{
    static_cast<QWidgetBind*>(widget)->setFocusPolicy(static_cast<Qt::FocusPolicy>(policy));
}

void* QWidget_font(void* widget)
{
    QFont* font = new QFont(static_cast<QWidgetBind*>(widget)->font());
    return font;
}

void QWidget_setFont(void* widget, void* font)
{
    static_cast<QWidgetBind*>(widget)->setFont(*static_cast<QFont*>(font));
}

int QWidget_frameGeometryX(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->frameGeometry().x();
}

int QWidget_frameGeometryY(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->frameGeometry().y();
}

int QWidget_frameGeometryWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->frameGeometry().width();
}

int QWidget_frameGeometryHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->frameGeometry().height();
}

int QWidget_frameSizeWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->frameSize().width();
}

int QWidget_frameSizeHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->frameSize().height();
}

bool QWidget_isFullScreen(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isFullScreen();
}

void QWidget_setGeometry(void* widget, int x, int y, int width, int height)
{
    static_cast<QWidgetBind*>(widget)->setGeometry(x, y, width, height);
}

int QWidget_inputMethodHints(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->inputMethodHints());
}

void QWidget_setInputMethodHints(void* widget, int hints)
{
    static_cast<QWidgetBind*>(widget)->setInputMethodHints(static_cast<Qt::InputMethodHints>(hints));
}

bool QWidget_isActiveWindow(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isActiveWindow();
}

int QWidget_layoutDirection(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->layoutDirection());
}

void QWidget_setLayoutDirection(void* widget, int direction)
{
    static_cast<QWidgetBind*>(widget)->setLayoutDirection(static_cast<Qt::LayoutDirection>(direction));
}

void* QWidget_locale(void* widget)
{
    QLocale* locale = new QLocale(static_cast<QWidgetBind*>(widget)->locale());
    return locale;
}

void QWidget_setLocale(void* widget, void* locale)
{
    static_cast<QWidgetBind*>(widget)->setLocale(*static_cast<QLocale*>(locale));
}

bool QWidget_isMaximized(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isMaximized();
}

int QWidget_maximumHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->maximumHeight();
}

void QWidget_setMaximumHeight(void* widget, int maxh)
{
    static_cast<QWidgetBind*>(widget)->setMaximumHeight(maxh);
}

int QWidget_maximumWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->maximumWidth();
}

void QWidget_setMaximumWidth(void* widget, int maxw)
{
    static_cast<QWidgetBind*>(widget)->setMaximumWidth(maxw);
}

void QWidget_setMaximumSize(void* widget, int maxw, int maxh)
{
    static_cast<QWidgetBind*>(widget)->setMaximumSize(maxw, maxh);
}

bool QWidget_isMinimized(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isMinimized();
}

int QWidget_minimumHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->minimumHeight();
}

void QWidget_setMinimumHeight(void* widget, int minh)
{
    static_cast<QWidgetBind*>(widget)->setMinimumHeight(minh);
}

int QWidget_minimumWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->minimumWidth();
}

void QWidget_setMinimumWidth(void* widget, int minw)
{
    static_cast<QWidgetBind*>(widget)->setMinimumWidth(minw);
}

void QWidget_setMinimumSize(void* widget, int minw, int minh)
{
    static_cast<QWidgetBind*>(widget)->setMinimumSize(minw, minh);
}

int QWidget_minimumSizeHintWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->minimumSizeHint().width();
}

int QWidget_minimumSizeHintHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->minimumSizeHint().height();
}

bool QWidget_isModal(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isModal();
}

bool QWidget_hasMouseTracking(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->hasMouseTracking();
}

void QWidget_setMouseTracking(void* widget, bool enable)
{
    static_cast<QWidgetBind*>(widget)->setMouseTracking(enable);
}

int QWidget_normalGeometryX(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->normalGeometry().x();
}

int QWidget_normalGeometryY(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->normalGeometry().y();
}

int QWidget_normalGeometryWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->normalGeometry().width();
}

int QWidget_normalGeometryHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->normalGeometry().height();
}

void* QWidget_palette(void* widget)
{
    QPalette* palette = new QPalette(static_cast<QWidgetBind*>(widget)->palette());
    return palette;
}

void QWidget_setPalette(void* widget, void* palette)
{
    static_cast<QWidgetBind*>(widget)->setPalette(*static_cast<QPalette*>(palette));
}

int QWidget_posX(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->pos().x();
}

int QWidget_posY(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->pos().y();
}

int QWidget_rectX(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->rect().x();
}

int QWidget_rectY(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->rect().y();
}

int QWidget_rectWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->rect().width();
}

int QWidget_rectHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->rect().height();
}

int QWidget_sizeWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->size().width();
}

int QWidget_sizeHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->size().height();
}

int QWidget_sizeHintWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->sizeHint().width();
}

int QWidget_sizeHintHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->sizeHint().height();
}

int QWidget_sizeIncrementWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->sizeIncrement().width();
}

int QWidget_sizeIncrementHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->sizeIncrement().height();
}

void QWidget_setSizeIncrement(void* widget, int w, int h)
{
    static_cast<QWidgetBind*>(widget)->setSizeIncrement(w, h);
}

int QWidget_sizePolicy(void* widget)
{
    QSizePolicy policy = static_cast<QWidgetBind*>(widget)->sizePolicy();
    return (static_cast<int>(policy.horizontalPolicy()) << 16) | static_cast<int>(policy.verticalPolicy());
}

void QWidget_setSizePolicy(void* widget, int horizontal, int vertical)
{
    static_cast<QWidgetBind*>(widget)->setSizePolicy(
        static_cast<QSizePolicy::Policy>(horizontal),
        static_cast<QSizePolicy::Policy>(vertical)
    );
}

const char* QWidget_statusTip(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->statusTip().toUtf8().constData();
}

void QWidget_setStatusTip(void* widget, const char* statusTip)
{
    static_cast<QWidgetBind*>(widget)->setStatusTip(QString::fromUtf8(statusTip));
}

bool QWidget_hasTabletTracking(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->hasTabletTracking();
}

void QWidget_setTabletTracking(void* widget, bool enable)
{
    static_cast<QWidgetBind*>(widget)->setTabletTracking(enable);
}

const char* QWidget_toolTip(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->toolTip().toUtf8().constData();
}

void QWidget_setToolTip(void* widget, const char* toolTip)
{
    static_cast<QWidgetBind*>(widget)->setToolTip(QString::fromUtf8(toolTip));
}

int QWidget_toolTipDuration(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->toolTipDuration();
}

void QWidget_setToolTipDuration(void* widget, int msec)
{
    static_cast<QWidgetBind*>(widget)->setToolTipDuration(msec);
}

bool QWidget_updatesEnabled(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->updatesEnabled();
}

void QWidget_setUpdatesEnabled(void* widget, bool enable)
{
    static_cast<QWidgetBind*>(widget)->setUpdatesEnabled(enable);
}

const char* QWidget_whatsThis(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->whatsThis().toUtf8().constData();
}

void QWidget_setWhatsThis(void* widget, const char* whatsThis)
{
    static_cast<QWidgetBind*>(widget)->setWhatsThis(QString::fromUtf8(whatsThis));
}

const char* QWidget_windowFilePath(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->windowFilePath().toUtf8().constData();
}

void QWidget_setWindowFilePath(void* widget, const char* filePath)
{
    static_cast<QWidgetBind*>(widget)->setWindowFilePath(QString::fromUtf8(filePath));
}

int QWidget_windowFlags(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->windowFlags());
}

void QWidget_setWindowFlags(void* widget, int flags)
{
    static_cast<QWidgetBind*>(widget)->setWindowFlags(static_cast<Qt::WindowFlags>(flags));
}

void* QWidget_windowIcon(void* widget)
{
    QIcon* icon = new QIcon(static_cast<QWidgetBind*>(widget)->windowIcon());
    return icon;
}

void QWidget_setWindowIcon(void* widget, void* icon)
{
    static_cast<QWidgetBind*>(widget)->setWindowIcon(*static_cast<QIcon*>(icon));
}

int QWidget_windowModality(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->windowModality());
}

void QWidget_setWindowModality(void* widget, int modality)
{
    static_cast<QWidgetBind*>(widget)->setWindowModality(static_cast<Qt::WindowModality>(modality));
}

bool QWidget_isWindowModified(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isWindowModified();
}

double QWidget_windowOpacity(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->windowOpacity();
}

void QWidget_setWindowOpacity(void* widget, double level)
{
    static_cast<QWidgetBind*>(widget)->setWindowOpacity(level);
}

// Public Functions

void* QWidget_actions(void* widget)
{
    // QListは直接返せないので、ポインタの配列を作成して返す
    QList<QAction*> actions = static_cast<QWidgetBind*>(widget)->actions();
    QAction** actionArray = new QAction*[actions.size() + 1];
    for (int i = 0; i < actions.size(); i++) {
        actionArray[i] = actions[i];
    }
    actionArray[actions.size()] = nullptr; // 終端
    return actionArray;
}

void QWidget_activateWindow(void* widget)
{
    static_cast<QWidgetBind*>(widget)->activateWindow();
}

void QWidget_addAction(void* widget, void* action)
{
    static_cast<QWidgetBind*>(widget)->addAction(static_cast<QAction*>(action));
}

void* QWidget_addActionWithText(void* widget, const char* text)
{
    return static_cast<QWidgetBind*>(widget)->addAction(QString::fromUtf8(text));
}

void* QWidget_addActionWithIconAndText(void* widget, void* icon, const char* text)
{
    return static_cast<QWidgetBind*>(widget)->addAction(
        *static_cast<QIcon*>(icon),
        QString::fromUtf8(text)
    );
}

void* QWidget_addActionWithTextAndShortcut(void* widget, const char* text, int shortcut)
{
    return static_cast<QWidgetBind*>(widget)->addAction(
        QString::fromUtf8(text),
        QKeySequence(shortcut)
    );
}

void* QWidget_addActionWithIconTextAndShortcut(void* widget, void* icon, const char* text, int shortcut)
{
    return static_cast<QWidgetBind*>(widget)->addAction(
        *static_cast<QIcon*>(icon),
        QString::fromUtf8(text),
        QKeySequence(shortcut)
    );
}

void QWidget_addActions(void* widget, void* actions)
{
    QList<QAction*> actionList;
    QAction** actionArray = static_cast<QAction**>(actions);
    int i = 0;
    while (actionArray[i] != nullptr) {
        actionList.append(actionArray[i]);
        i++;
    }
    static_cast<QWidgetBind*>(widget)->addActions(actionList);
}

void QWidget_adjustSize(void* widget)
{
    static_cast<QWidgetBind*>(widget)->adjustSize();
}

void* QWidget_backingStore(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->backingStore();
}

void* QWidget_childAt(void* widget, int x, int y)
{
    return static_cast<QWidgetBind*>(widget)->childAt(x, y);
}

void* QWidget_childAtPoint(void* widget, int x, int y)
{
    return static_cast<QWidgetBind*>(widget)->childAt(QPoint(x, y));
}

void* QWidget_childAtPointF(void* widget, double x, double y)
{
    return static_cast<QWidgetBind*>(widget)->childAt(QPointF(x, y));
}

void QWidget_clearFocus(void* widget)
{
    static_cast<QWidgetBind*>(widget)->clearFocus();
}

void QWidget_clearMask(void* widget)
{
    static_cast<QWidgetBind*>(widget)->clearMask();
}

void QWidget_getContentsMargins(void* widget, int* left, int* top, int* right, int* bottom)
{
    QMargins margins = static_cast<QWidgetBind*>(widget)->contentsMargins();
    *left = margins.left();
    *top = margins.top();
    *right = margins.right();
    *bottom = margins.bottom();
}

int QWidget_contentsRectX(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->contentsRect().x();
}

int QWidget_contentsRectY(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->contentsRect().y();
}

int QWidget_contentsRectWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->contentsRect().width();
}

int QWidget_contentsRectHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->contentsRect().height();
}

unsigned long QWidget_effectiveWinId(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->effectiveWinId();
}

void QWidget_ensurePolished(void* widget)
{
    static_cast<QWidgetBind*>(widget)->ensurePolished();
}

void* QWidget_focusProxy(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->focusProxy();
}

void* QWidget_focusWidget(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->focusWidget();
}

void* QWidget_fontInfo(void* widget)
{
    QFontInfo* fontInfo = new QFontInfo(static_cast<QWidgetBind*>(widget)->fontInfo());
    return fontInfo;
}

void* QWidget_fontMetrics(void* widget)
{
    QFontMetrics* fontMetrics = new QFontMetrics(static_cast<QWidgetBind*>(widget)->fontMetrics());
    return fontMetrics;
}

int QWidget_geometryX(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->geometry().x();
}

int QWidget_geometryY(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->geometry().y();
}

int QWidget_geometryWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->geometry().width();
}

int QWidget_geometryHeight(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->geometry().height();
}

void* QWidget_grab(void* widget, int x, int y, int width, int height)
{
    QRect rect;
    if (width == -1 && height == -1) {
        rect = QRect(QPoint(x, y), QSize(-1, -1));
    } else {
        rect = QRect(x, y, width, height);
    }
    QPixmap* pixmap = new QPixmap(static_cast<QWidgetBind*>(widget)->grab(rect));
    return pixmap;
}

void QWidget_grabGesture(void* widget, int gesture, int flags)
{
    static_cast<QWidgetBind*>(widget)->grabGesture(
        static_cast<Qt::GestureType>(gesture),
        static_cast<Qt::GestureFlags>(flags)
    );
}

void QWidget_grabKeyboard(void* widget)
{
    static_cast<QWidgetBind*>(widget)->grabKeyboard();
}

void QWidget_grabMouse(void* widget)
{
    static_cast<QWidgetBind*>(widget)->grabMouse();
}

void QWidget_grabMouseWithCursor(void* widget, void* cursor)
{
    static_cast<QWidgetBind*>(widget)->grabMouse(*static_cast<QCursor*>(cursor));
}

int QWidget_grabShortcut(void* widget, int key, int context)
{
    return static_cast<QWidgetBind*>(widget)->grabShortcut(
        QKeySequence(key),
        static_cast<Qt::ShortcutContext>(context)
    );
}

void* QWidget_graphicsEffect(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->graphicsEffect();
}

void* QWidget_graphicsProxyWidget(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->graphicsProxyWidget();
}

// hasEditFocus is not available in this Qt version
bool QWidget_hasEditFocus(void* widget)
{
    // Fallback to hasFocus
    return static_cast<QWidgetBind*>(widget)->hasFocus();
}

bool QWidget_hasHeightForWidth(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->hasHeightForWidth();
}

int QWidget_heightForWidth(void* widget, int w)
{
    return static_cast<QWidgetBind*>(widget)->heightForWidth(w);
}

void* QWidget_inputMethodQuery(void* widget, int query)
{
    QVariant result = static_cast<QWidgetBind*>(widget)->inputMethodQuery(static_cast<Qt::InputMethodQuery>(query));
    QVariant* variant = new QVariant(result);
    return variant;
}

void QWidget_insertAction(void* widget, void* before, void* action)
{
    static_cast<QWidgetBind*>(widget)->insertAction(
        static_cast<QAction*>(before),
        static_cast<QAction*>(action)
    );
}

void QWidget_insertActions(void* widget, void* before, void* actions)
{
    QList<QAction*> actionList;
    QAction** actionArray = static_cast<QAction**>(actions);
    int i = 0;
    while (actionArray[i] != nullptr) {
        actionList.append(actionArray[i]);
        i++;
    }
    static_cast<QWidgetBind*>(widget)->insertActions(
        static_cast<QAction*>(before),
        actionList
    );
}

bool QWidget_isAncestorOf(void* widget, void* child)
{
    return static_cast<QWidgetBind*>(widget)->isAncestorOf(static_cast<QWidget*>(child));
}

bool QWidget_isEnabledTo(void* widget, void* ancestor)
{
    return static_cast<QWidgetBind*>(widget)->isEnabledTo(static_cast<QWidget*>(ancestor));
}

bool QWidget_isVisibleTo(void* widget, void* ancestor)
{
    return static_cast<QWidgetBind*>(widget)->isVisibleTo(static_cast<QWidget*>(ancestor));
}

bool QWidget_isWindow(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->isWindow();
}

void* QWidget_layout(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->layout();
}

void* QWidget_mask(void* widget)
{
    QRegion* region = new QRegion(static_cast<QWidgetBind*>(widget)->mask());
    return region;
}

void QWidget_moveToPoint(void* widget, int x, int y)
{
    static_cast<QWidgetBind*>(widget)->move(x, y);
}

void QWidget_moveToQPoint(void* widget, int x, int y)
{
    static_cast<QWidgetBind*>(widget)->move(QPoint(x, y));
}

int QWidget_mapFromX(void* widget, void* parent, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapFrom(
        static_cast<QWidget*>(parent),
        QPoint(x, y)
    );
    return pos.x();
}

int QWidget_mapFromY(void* widget, void* parent, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapFrom(
        static_cast<QWidget*>(parent),
        QPoint(x, y)
    );
    return pos.y();
}

int QWidget_mapFromFX(void* widget, void* parent, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapFrom(
        static_cast<QWidget*>(parent),
        QPointF(x, y)
    );
    return static_cast<int>(pos.x());
}

int QWidget_mapFromFY(void* widget, void* parent, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapFrom(
        static_cast<QWidget*>(parent),
        QPointF(x, y)
    );
    return static_cast<int>(pos.y());
}

int QWidget_mapFromGlobalX(void* widget, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapFromGlobal(QPoint(x, y));
    return pos.x();
}

int QWidget_mapFromGlobalY(void* widget, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapFromGlobal(QPoint(x, y));
    return pos.y();
}

int QWidget_mapFromGlobalFX(void* widget, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapFromGlobal(QPointF(x, y));
    return static_cast<int>(pos.x());
}

int QWidget_mapFromGlobalFY(void* widget, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapFromGlobal(QPointF(x, y));
    return static_cast<int>(pos.y());
}

int QWidget_mapFromParentX(void* widget, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapFromParent(QPoint(x, y));
    return pos.x();
}

int QWidget_mapFromParentY(void* widget, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapFromParent(QPoint(x, y));
    return pos.y();
}

int QWidget_mapFromParentFX(void* widget, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapFromParent(QPointF(x, y));
    return static_cast<int>(pos.x());
}

int QWidget_mapFromParentFY(void* widget, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapFromParent(QPointF(x, y));
    return static_cast<int>(pos.y());
}

int QWidget_mapToX(void* widget, void* parent, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapTo(
        static_cast<QWidget*>(parent),
        QPoint(x, y)
    );
    return pos.x();
}

int QWidget_mapToY(void* widget, void* parent, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapTo(
        static_cast<QWidget*>(parent),
        QPoint(x, y)
    );
    return pos.y();
}

int QWidget_mapToFX(void* widget, void* parent, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapTo(
        static_cast<QWidget*>(parent),
        QPointF(x, y)
    );
    return static_cast<int>(pos.x());
}

int QWidget_mapToFY(void* widget, void* parent, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapTo(
        static_cast<QWidget*>(parent),
        QPointF(x, y)
    );
    return static_cast<int>(pos.y());
}

int QWidget_mapToGlobalX(void* widget, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapToGlobal(QPoint(x, y));
    return pos.x();
}

int QWidget_mapToGlobalY(void* widget, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapToGlobal(QPoint(x, y));
    return pos.y();
}

int QWidget_mapToGlobalFX(void* widget, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapToGlobal(QPointF(x, y));
    return static_cast<int>(pos.x());
}

int QWidget_mapToGlobalFY(void* widget, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapToGlobal(QPointF(x, y));
    return static_cast<int>(pos.y());
}

int QWidget_mapToParentX(void* widget, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapToParent(QPoint(x, y));
    return pos.x();
}

int QWidget_mapToParentY(void* widget, int x, int y)
{
    QPoint pos = static_cast<QWidgetBind*>(widget)->mapToParent(QPoint(x, y));
    return pos.y();
}

int QWidget_mapToParentFX(void* widget, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapToParent(QPointF(x, y));
    return static_cast<int>(pos.x());
}

int QWidget_mapToParentFY(void* widget, double x, double y)
{
    QPointF pos = static_cast<QWidgetBind*>(widget)->mapToParent(QPointF(x, y));
    return static_cast<int>(pos.y());
}

void* QWidget_nativeParentWidget(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->nativeParentWidget();
}

void* QWidget_nextInFocusChain(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->nextInFocusChain();
}

void QWidget_overrideWindowFlags(void* widget, int flags)
{
    static_cast<QWidgetBind*>(widget)->overrideWindowFlags(static_cast<Qt::WindowFlags>(flags));
}

void* QWidget_parentWidget(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->parentWidget();
}

void* QWidget_previousInFocusChain(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->previousInFocusChain();
}

void QWidget_releaseKeyboard(void* widget)
{
    static_cast<QWidgetBind*>(widget)->releaseKeyboard();
}

void QWidget_releaseMouse(void* widget)
{
    static_cast<QWidgetBind*>(widget)->releaseMouse();
}

void QWidget_releaseShortcut(void* widget, int id)
{
    static_cast<QWidgetBind*>(widget)->releaseShortcut(id);
}

void QWidget_removeAction(void* widget, void* action)
{
    static_cast<QWidgetBind*>(widget)->removeAction(static_cast<QAction*>(action));
}

void QWidget_renderToPaintDevice(void* widget, void* target, int targetOffsetX, int targetOffsetY, void* sourceRegion, int renderFlags)
{
    static_cast<QWidgetBind*>(widget)->render(
        static_cast<QPaintDevice*>(target),
        QPoint(targetOffsetX, targetOffsetY),
        *static_cast<QRegion*>(sourceRegion),
        static_cast<QWidget::RenderFlags>(renderFlags)
    );
}

void QWidget_renderToPainter(void* widget, void* painter, int targetOffsetX, int targetOffsetY, void* sourceRegion, int renderFlags)
{
    static_cast<QWidgetBind*>(widget)->render(
        static_cast<QPainter*>(painter),
        QPoint(targetOffsetX, targetOffsetY),
        *static_cast<QRegion*>(sourceRegion),
        static_cast<QWidget::RenderFlags>(renderFlags)
    );
}

void QWidget_repaintRect(void* widget, int x, int y, int width, int height)
{
    static_cast<QWidgetBind*>(widget)->repaint(x, y, width, height);
}

void QWidget_repaintQRect(void* widget, int x, int y, int width, int height)
{
    static_cast<QWidgetBind*>(widget)->repaint(QRect(x, y, width, height));
}

void QWidget_repaintRegion(void* widget, void* region)
{
    static_cast<QWidgetBind*>(widget)->repaint(*static_cast<QRegion*>(region));
}

void QWidget_resizeWithSize(void* widget, int width, int height)
{
    static_cast<QWidgetBind*>(widget)->resize(QSize(width, height));
}

bool QWidget_restoreGeometry(void* widget, void* geometry, int size)
{
    QByteArray byteArray(static_cast<const char*>(geometry), size);
    return static_cast<QWidgetBind*>(widget)->restoreGeometry(byteArray);
}

void* QWidget_saveGeometry(void* widget, int* size)
{
    QByteArray byteArray = static_cast<QWidgetBind*>(widget)->saveGeometry();
    *size = byteArray.size();
    char* data = new char[*size];
    memcpy(data, byteArray.constData(), *size);
    return data;
}

void* QWidget_screen(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->screen();
}

void QWidget_setMaskBitmap(void* widget, void* bitmap)
{
    static_cast<QWidgetBind*>(widget)->setMask(*static_cast<QBitmap*>(bitmap));
}

void QWidget_setMaskRegion(void* widget, void* region)
{
    static_cast<QWidgetBind*>(widget)->setMask(*static_cast<QRegion*>(region));
}

void QWidget_setParent(void* widget, void* parent)
{
    static_cast<QWidgetBind*>(widget)->setParent(static_cast<QWidget*>(parent));
}

void QWidget_setParentWithFlags(void* widget, void* parent, int flags)
{
    static_cast<QWidgetBind*>(widget)->setParent(
        static_cast<QWidget*>(parent),
        static_cast<Qt::WindowFlags>(flags)
    );
}

void QWidget_setScreen(void* widget, void* screen)
{
    static_cast<QWidgetBind*>(widget)->setScreen(static_cast<QScreen*>(screen));
}

void QWidget_setShortcutAutoRepeat(void* widget, int id, bool enable)
{
    static_cast<QWidgetBind*>(widget)->setShortcutAutoRepeat(id, enable);
}

void QWidget_setShortcutEnabled(void* widget, int id, bool enable)
{
    static_cast<QWidgetBind*>(widget)->setShortcutEnabled(id, enable);
}

void QWidget_setSizeIncrementWithSize(void* widget, int width, int height)
{
    static_cast<QWidgetBind*>(widget)->setSizeIncrement(QSize(width, height));
}

void QWidget_setStyle(void* widget, void* style)
{
    static_cast<QWidgetBind*>(widget)->setStyle(static_cast<QStyle*>(style));
}

void QWidget_setWindowFlag(void* widget, int flag, bool on)
{
    static_cast<QWidgetBind*>(widget)->setWindowFlag(static_cast<Qt::WindowType>(flag), on);
}

void QWidget_setWindowRole(void* widget, const char* role)
{
    static_cast<QWidgetBind*>(widget)->setWindowRole(QString::fromUtf8(role));
}

void QWidget_setWindowState(void* widget, int windowState)
{
    static_cast<QWidgetBind*>(widget)->setWindowState(static_cast<Qt::WindowStates>(windowState));
}

void QWidget_setupUi(void* widget, void* targetWidget)
{
    // setupUiはQtのデザイナーが生成するコードで使用される関数で、
    // 通常はuic（User Interface Compiler）によって生成されるコードの一部です。
    // ここでは単純に何もしない実装を提供します。
    // 実際のアプリケーションでは、uicが生成したコードを使用するか、
    // 手動でUIをセットアップする必要があります。
}

void QWidget_stackUnder(void* widget, void* w)
{
    static_cast<QWidgetBind*>(widget)->stackUnder(static_cast<QWidget*>(w));
}

bool QWidget_testAttribute(void* widget, int attribute)
{
    return static_cast<QWidgetBind*>(widget)->testAttribute(static_cast<Qt::WidgetAttribute>(attribute));
}

bool QWidget_underMouse(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->underMouse();
}

void QWidget_ungrabGesture(void* widget, int gesture)
{
    static_cast<QWidgetBind*>(widget)->ungrabGesture(static_cast<Qt::GestureType>(gesture));
}

void QWidget_unsetCursor(void* widget)
{
    static_cast<QWidgetBind*>(widget)->unsetCursor();
}

void QWidget_unsetLayoutDirection(void* widget)
{
    static_cast<QWidgetBind*>(widget)->unsetLayoutDirection();
}

void QWidget_unsetLocale(void* widget)
{
    static_cast<QWidgetBind*>(widget)->unsetLocale();
}

void QWidget_updateRect(void* widget, int x, int y, int w, int h)
{
    static_cast<QWidgetBind*>(widget)->update(x, y, w, h);
}

void QWidget_updateQRect(void* widget, int x, int y, int w, int h)
{
    static_cast<QWidgetBind*>(widget)->update(QRect(x, y, w, h));
}

void QWidget_updateRegion(void* widget, void* region)
{
    static_cast<QWidgetBind*>(widget)->update(*static_cast<QRegion*>(region));
}

void QWidget_updateGeometry(void* widget)
{
    static_cast<QWidgetBind*>(widget)->updateGeometry();
}

void* QWidget_visibleRegion(void* widget)
{
    QRegion* region = new QRegion(static_cast<QWidgetBind*>(widget)->visibleRegion());
    return region;
}

unsigned long QWidget_winId(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->winId();
}

void* QWidget_window(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->window();
}

void* QWidget_windowHandle(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->windowHandle();
}

const char* QWidget_windowRole(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->windowRole().toUtf8().constData();
}

int QWidget_windowState(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->windowState());
}

int QWidget_windowType(void* widget)
{
    return static_cast<int>(static_cast<QWidgetBind*>(widget)->windowType());
}

// Public Slots

bool QWidget_close(void* widget)
{
    return static_cast<QWidgetBind*>(widget)->close();
}

void QWidget_lower(void* widget)
{
    static_cast<QWidgetBind*>(widget)->lower();
}

void QWidget_raise(void* widget)
{
    static_cast<QWidgetBind*>(widget)->raise();
}

void QWidget_repaint(void* widget)
{
    static_cast<QWidgetBind*>(widget)->repaint();
}

void QWidget_setDisabled(void* widget, bool disable)
{
    static_cast<QWidgetBind*>(widget)->setDisabled(disable);
}

void QWidget_setFocus(void* widget)
{
    static_cast<QWidgetBind*>(widget)->setFocus();
}

void QWidget_setHidden(void* widget, bool hidden)
{
    static_cast<QWidgetBind*>(widget)->setHidden(hidden);
}

void QWidget_setWindowModified(void* widget, bool modified)
{
    static_cast<QWidgetBind*>(widget)->setWindowModified(modified);
}

void QWidget_showFullScreen(void* widget)
{
    static_cast<QWidgetBind*>(widget)->showFullScreen();
}

void QWidget_showMaximized(void* widget)
{
    static_cast<QWidgetBind*>(widget)->showMaximized();
}

void QWidget_showMinimized(void* widget)
{
    static_cast<QWidgetBind*>(widget)->showMinimized();
}

void QWidget_showNormal(void* widget)
{
    static_cast<QWidgetBind*>(widget)->showNormal();
}

void QWidget_update(void* widget)
{
    static_cast<QWidgetBind*>(widget)->update();
}

// Signals

typedef void (*QWidget_CustomContextMenuRequestedCallback)(void*, const QPoint*);
typedef void (*QWidget_WindowIconChangedCallback)(void*, const QIcon*);
typedef void (*QWidget_WindowTitleChangedCallback)(void*, const QString*);

void QWidget_setCustomContextMenuRequestedCallback(void* widget, void (*callback)(void*, const void*))
{
    static_cast<QWidgetBind*>(widget)->setCustomContextMenuRequestedCallback(
        reinterpret_cast<QWidget_CustomContextMenuRequestedCallback>(callback)
    );
}

void QWidget_setWindowIconChangedCallback(void* widget, void (*callback)(void*, const void*))
{
    static_cast<QWidgetBind*>(widget)->setWindowIconChangedCallback(
        reinterpret_cast<QWidget_WindowIconChangedCallback>(callback)
    );
}

void QWidget_setWindowTitleChangedCallback(void* widget, void (*callback)(void*, const void*))
{
    static_cast<QWidgetBind*>(widget)->setWindowTitleChangedCallback(
        reinterpret_cast<QWidget_WindowTitleChangedCallback>(callback)
    );
}

}
