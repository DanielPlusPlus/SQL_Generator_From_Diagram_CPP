#include "views/MenuBarView.hpp"

#include <QAction>
#include <QIcon>
#include <QMenu>


MenuBarView::MenuBarView(
        QWidget* parent
    ) : QMenuBar(parent),
        actionImportOracleSQL(nullptr),
        actionImportMySQL(nullptr),
        actionImportMSSSQL(nullptr),
        actionImportPostgreSQL(nullptr),

        actionExportDiagram(nullptr),
        actionGenerateSQL(nullptr),
        actionQuit(nullptr),

        actionZoomIn(nullptr),
        actionZoomOut(nullptr),
        actionResetZoom(nullptr),

        actionDefaultTheme(nullptr),
        actionAuroraTheme(nullptr),
        actionDarculaTheme(nullptr),
        actionSakuraTheme(nullptr),
        actionNeonTheme(nullptr),

        actionCreateTable(nullptr),

        actionCreate_1_1_Rel(nullptr),
        actionCreate_1_n_Rel(nullptr),
        actionCreate_n_n_Rel(nullptr),

        actionCreateInheritance(nullptr),

        menuFile(nullptr),
        menuImportSQL(nullptr),
        menuView(nullptr),
        menuThemes(nullptr),
        menuTables(nullptr),
        menuConnections(nullptr),
        menuRelationships(nullptr) {
    setObjectName("MenuBar");
}

void MenuBarView::setupUI() {
    menuFile = new QMenu("File", this);
    menuImportSQL = new QMenu("Import SQL File", this);
    menuView = new QMenu("View", this);
    menuThemes = new QMenu("Themes", this);
    menuTables = new QMenu("Tables", this);
    menuConnections = new QMenu("Connections", this);
    menuRelationships = new QMenu("Relationships", this);
    menuRelationships->setIcon(QIcon("icons/relationship.png"));

    actionImportOracleSQL = new QAction("Import Oracle SQL File",
                                        this);
    actionImportMySQL = new QAction("Import MySQL File", 
                                    this);
    actionImportMSSSQL = new QAction("Import Microsoft Server SQL File",
                                     this);
    actionImportPostgreSQL = new QAction("Import PostgreSQL File",
                                         this);
    
    actionExportDiagram = new QAction("Export Diagram",
                                      this);
    actionGenerateSQL = new QAction("Generate SQL Code",
                                    this);
    actionQuit = new QAction("Quit", 
                             this);
    
    actionZoomIn = new QAction("Zoom In", this);
    actionZoomOut = new QAction("Zoom Out", this);
    actionResetZoom = new QAction("Reset Zoom", this);

    actionDefaultTheme = new QAction("Default", this);
    actionAuroraTheme = new QAction("Aurora", this);
    actionDarculaTheme = new QAction("Darcula", this);
    actionSakuraTheme = new QAction("Sakura", this);
    actionNeonTheme = new QAction("Neon", this);

    actionCreateTable = new QAction(QIcon("icons/table.png"),
                                    "Create Table", this);
    
    actionCreate_1_1_Rel = new QAction(QIcon("icons/1_1_rel.png"),
                                       "Create 1:1 Relationship",
                                       this);
    actionCreate_1_n_Rel = new QAction(QIcon("icons/1_n_rel.png"),
                                       "Create 1:n Relationship",
                                       this);
    actionCreate_n_n_Rel = new QAction(QIcon("icons/n_n_rel.png"),
                                       "Create n:n Relationship",
                                       this);
    
    actionCreateInheritance = new QAction(QIcon("icons/inheritance.png"),
                                          "Create Inheritance Relationship",
                                          this);

    menuFile->addMenu(menuImportSQL);
    menuImportSQL->addAction(actionImportOracleSQL);
    menuImportSQL->addAction(actionImportMySQL);
    menuImportSQL->addAction(actionImportMSSSQL);
    menuImportSQL->addAction(actionImportPostgreSQL);
    menuFile->addAction(actionExportDiagram);
    menuFile->addAction(actionGenerateSQL);
    menuFile->addAction(actionQuit);

    menuView->addAction(actionZoomIn);
    menuView->addAction(actionZoomOut);
    menuView->addAction(actionResetZoom);
    menuView->addMenu(menuThemes);
    menuThemes->addAction(actionDefaultTheme);
    menuThemes->addAction(actionAuroraTheme);
    menuThemes->addAction(actionDarculaTheme);
    menuThemes->addAction(actionSakuraTheme);
    menuThemes->addAction(actionNeonTheme);

    menuTables->addAction(actionCreateTable);

    menuConnections->addMenu(menuRelationships);
    menuRelationships->addAction(actionCreate_1_1_Rel);
    menuRelationships->addAction(actionCreate_1_n_Rel);
    menuRelationships->addAction(actionCreate_n_n_Rel);
    menuConnections->addAction(actionCreateInheritance);
    
    addMenu(menuFile);
    addMenu(menuView);
    addMenu(menuTables);
    addMenu(menuConnections);
}