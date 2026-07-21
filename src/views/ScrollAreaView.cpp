#include "views/ScrollAreaView.hpp"


ScrollAreaView::ScrollAreaView(
        QWidget* parent
    ) : QScrollArea(parent) {}

void ScrollAreaView::setupUI(QWidget* drawingAreaView) {
    setWidget(drawingAreaView);
    setWidgetResizable(true);
}