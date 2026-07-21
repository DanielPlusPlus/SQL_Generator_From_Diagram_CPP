#pragma once

#include <QMessageBox>


class ConfirmationDialogView : public QMessageBox {
    Q_OBJECT
public:
    explicit ConfirmationDialogView(
        QWidget* parent,
        const QString& title,
        const QString& text
    );
    bool displayDialog();
};