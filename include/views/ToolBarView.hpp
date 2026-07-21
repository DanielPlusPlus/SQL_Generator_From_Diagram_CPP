#pragma once

#include <QToolBar>


class QAction;

class ToolBarView : public QToolBar {
    Q_OBJECT
public:
    QAction* actionCreateTable;
    QAction* actionCreate_1_1_Rel;
    QAction* actionCreate_1_n_Rel;
    QAction* actionCreate_n_n_Rel;
    QAction* actionCreateInheritance;
    QAction* actionExportDiagram;
    QAction* actionGenerateSQL;

    explicit ToolBarView(QWidget* parent = nullptr);
    void setupUI();
};