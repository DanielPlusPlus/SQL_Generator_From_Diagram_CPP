#include "views/ConfirmationDialogView.hpp"


ConfirmationDialogView::ConfirmationDialogView(
        QWidget* parent,
        const QString& title,
        const QString& text
    ) : QMessageBox(parent) {
    setWindowTitle(title);
    setText(text);
    setIcon(QMessageBox::Warning);
    setStandardButtons(
        QMessageBox::Yes |
        QMessageBox::No
    );
    setDefaultButton(QMessageBox::No);
}

bool ConfirmationDialogView::displayDialog() {
    int result = exec();
    return result == QMessageBox::Yes;
}