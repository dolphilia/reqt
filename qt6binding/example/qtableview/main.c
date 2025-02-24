#include "qt6.h"
#include <stdio.h>

void onClicked(void* index) {
    printf("Cell clicked\n");
}

void onDoubleClicked(void* index) {
    printf("Cell double clicked\n");
}

void onSelectionChanged() {
    printf("Selection changed\n");
}

void onHorizontalHeaderClicked(int section) {
    printf("Horizontal header clicked: %d\n", section);
}

void onVerticalHeaderClicked(int section) {
    printf("Vertical header clicked: %d\n", section);
}

int main(int argc, char *argv[]) {
    // Initialize application
    void *app = QApplication_create(argc, argv);
    
    // Create main window
    void *window = QMainWindow_create(NULL);
    QWidget_resize(window, 600, 400);
    QWidget_setWindowTitle(window, "QTableView Example");
    
    // Create table view
    void *table_view = QTableView_create(window);
    QTableView_setShowGrid(table_view, true);
    QTableView_setGridStyle(table_view, QTABLEVIEW_GRID_SOLID);
    QTableView_setSortingEnabled(table_view, true);
    QTableView_setWordWrap(table_view, true);
    QTableView_setCornerButtonEnabled(table_view, true);

    // Create model
    void *model = QStandardItemModel_create(5, 3, NULL);

    // Add header items
    void *header1 = QStandardItem_create("Name");
    void *header2 = QStandardItem_create("Age");
    void *header3 = QStandardItem_create("City");
    QStandardItemModel_setItem(model, header1, 0, 0);
    QStandardItemModel_setItem(model, header2, 0, 1);
    QStandardItemModel_setItem(model, header3, 0, 2);

    // Add data items
    const char* names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    const char* ages[] = {"25", "30", "35", "28", "32"};
    const char* cities[] = {"New York", "London", "Paris", "Tokyo", "Berlin"};

    for (int i = 0; i < 5; i++) {
        void *name_item = QStandardItem_create(names[i]);
        void *age_item = QStandardItem_create(ages[i]);
        void *city_item = QStandardItem_create(cities[i]);
        
        QStandardItemModel_setItem(model, name_item, i + 1, 0);
        QStandardItemModel_setItem(model, age_item, i + 1, 1);
        QStandardItemModel_setItem(model, city_item, i + 1, 2);
    }

    // Set model to table view
    QTableView_setModel(table_view, model);

    // Set column widths
    QTableView_setColumnWidth(table_view, 0, 150);
    QTableView_setColumnWidth(table_view, 1, 100);
    QTableView_setColumnWidth(table_view, 2, 150);

    // Set callbacks
    QTableView_setClickedCallback(table_view, onClicked);
    QTableView_setDoubleClickedCallback(table_view, onDoubleClicked);
    QTableView_setSelectionChangedCallback(table_view, onSelectionChanged);
    QTableView_setHorizontalHeaderClickedCallback(table_view, onHorizontalHeaderClicked);
    QTableView_setVerticalHeaderClickedCallback(table_view, onVerticalHeaderClicked);

    // Set table view as central widget
    QMainWindow_setCentralWidget(window, table_view);
    
    // Show window
    QWidget_show(window);
    
    // Run application
    int result = QApplication_exec(app);
    
    // Cleanup
    QStandardItem_delete(header1);
    QStandardItem_delete(header2);
    QStandardItem_delete(header3);
    QStandardItemModel_delete(model);
    QWidget_delete(table_view);
    QWidget_delete(window);
    QApplication_delete(app);
    
    return result;
}
