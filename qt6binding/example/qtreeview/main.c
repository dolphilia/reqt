#include "qt6.h"
#include <stdio.h>

void onClicked(void* index) {
    printf("Item clicked\n");
}

void onDoubleClicked(void* index) {
    printf("Item double clicked\n");
}

void onExpanded(void* index) {
    printf("Item expanded\n");
}

void onCollapsed(void* index) {
    printf("Item collapsed\n");
}

void onSelectionChanged() {
    printf("Selection changed\n");
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QMainWindow_create(NULL);
    QWidget_resize(window, 400, 300);
    QWidget_setWindowTitle(window, "QTreeView Example");
    
    // Create tree view
    void *tree_view = QTreeView_create(window);
    QTreeView_setAnimated(tree_view, true);
    QTreeView_setAllColumnsShowFocus(tree_view, true);
    QTreeView_setExpandsOnDoubleClick(tree_view, true);
    QTreeView_setIndentation(tree_view, 20);
    QTreeView_setItemsExpandable(tree_view, true);
    QTreeView_setSortingEnabled(tree_view, true);

    // Create model and add items
    void *model = QStandardItemModel_create(0, 1, NULL);
    void *root_item = QStandardItem_create("Root");
    
    // Add child items to root
    void *child1 = QStandardItem_create("Child 1");
    void *child2 = QStandardItem_create("Child 2");
    void *child3 = QStandardItem_create("Child 3");
    
    // Add grandchild items
    void *grandchild1 = QStandardItem_create("Grandchild 1");
    void *grandchild2 = QStandardItem_create("Grandchild 2");
    
    // Build tree structure
    QStandardItem_appendRow(child1, grandchild1);
    QStandardItem_appendRow(child1, grandchild2);
    QStandardItem_appendRow(root_item, child1);
    QStandardItem_appendRow(root_item, child2);
    QStandardItem_appendRow(root_item, child3);
    
    // Set model root item
    QStandardItemModel_setItem(model, root_item, 0, 0);
    
    // Set model to tree view
    QTreeView_setModel(tree_view, model);
    
    // Set callbacks
    QTreeView_setClickedCallback(tree_view, onClicked);
    QTreeView_setDoubleClickedCallback(tree_view, onDoubleClicked);
    QTreeView_setExpandedCallback(tree_view, onExpanded);
    QTreeView_setCollapsedCallback(tree_view, onCollapsed);
    QTreeView_setSelectionChangedCallback(tree_view, onSelectionChanged);
    
    // Set tree view as central widget
    QMainWindow_setCentralWidget(window, tree_view);
    
    // Show window
    QWidget_show(window);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QStandardItem_delete(grandchild1);
    QStandardItem_delete(grandchild2);
    QStandardItem_delete(child1);
    QStandardItem_delete(child2);
    QStandardItem_delete(child3);
    QStandardItem_delete(root_item);
    QStandardItemModel_delete(model);
    QWidget_delete(tree_view);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
