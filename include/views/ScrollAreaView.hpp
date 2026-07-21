#pragma once

#include <QScrollArea>


class ScrollAreaView : public QScrollArea {
    Q_OBJECT
public:
    explicit ScrollAreaView(QWidget* parent = nullptr);
    void setupUI(QWidget* drawingAreaView);
};