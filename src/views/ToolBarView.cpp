#include "views/ToolBarView.hpp"

#include <QAction>
#include <QIcon>
#include <QSize>


ToolBarView::ToolBarView(
        QWidget* parent
    ) : QToolBar("Tools", parent),
        actionCreateTable(nullptr),
        actionCreate_1_1_Rel(nullptr),
        actionCreate_1_n_Rel(nullptr),
        actionCreate_n_n_Rel(nullptr),
        actionCreateInheritance(nullptr),
        actionExportDiagram(nullptr),
        actionGenerateSQL(nullptr) {}

void ToolBarView::setupUI() {
    setIconSize(QSize(48, 48));

    actionCreateTable = new QAction(QIcon("icons/table.png"), 
                                    "Create Table", this);
    addAction(actionCreateTable);

    actionCreate_1_1_Rel = new QAction(QIcon("icons/1_1_rel.png"), 
                                       "Create 1:1 Relationship", this);
    addAction(actionCreate_1_1_Rel);

    actionCreate_1_n_Rel = new QAction(QIcon("icons/1_n_rel.png"),
                                       "Create 1:n Relationship", this);
    addAction(actionCreate_1_n_Rel);

    actionCreate_n_n_Rel = new QAction(QIcon("icons/n_n_rel.png"),
                                       "Create n:n Relationship", this);
    addAction(actionCreate_n_n_Rel);

    actionCreateInheritance = new QAction(QIcon("icons/inheritance.png"),
                                          "Create Inheritance Relationship", this);
    addAction(actionCreateInheritance);

    actionExportDiagram = new QAction(QIcon("icons/saveDiagram.png"),
                                      "Export Diagram", this);
    addAction(actionExportDiagram);

    actionGenerateSQL = new QAction(QIcon("icons/generateSQL.png"), 
                                    "Generate SQL Code", this);
    addAction(actionGenerateSQL);
}