#pragma once

#include <QMenuBar>


class QAction;
class QMenu;

class MenuBarView : public QMenuBar {
    Q_OBJECT
private:
    QMenu* menuFile;
    QMenu* menuImportSQL;

    QMenu* menuView;
    QMenu* menuThemes;

    QMenu* menuTables;

    QMenu* menuConnections;
    QMenu* menuRelationships;
public:
    QAction* actionImportOracleSQL;
    QAction* actionImportMySQL;
    QAction* actionImportMSSSQL;
    QAction* actionImportPostgreSQL;

    QAction* actionExportDiagram;
    QAction* actionGenerateSQL;
    QAction* actionQuit;

    QAction* actionZoomIn;
    QAction* actionZoomOut;
    QAction* actionResetZoom;

    QAction* actionDefaultTheme;
    QAction* actionAuroraTheme;
    QAction* actionDarculaTheme;
    QAction* actionSakuraTheme;
    QAction* actionNeonTheme;

    QAction* actionCreateTable;

    QAction* actionCreate_1_1_Rel;
    QAction* actionCreate_1_n_Rel;
    QAction* actionCreate_n_n_Rel;

    QAction* actionCreateInheritance;

    explicit MenuBarView(QWidget* parent = nullptr);
    void setupUI();
};