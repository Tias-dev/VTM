#ifndef SCREENTOOLS_H
#define SCREENTOOLS_H

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QSize>
#include <QSlider>
#include <QToolButton>

#define REF_DPI 196.0f

class ScreenTools : public QObject {
    Q_OBJECT

   private:
    qreal mDpi;
    QSize size, size2;
    QSize net;
    size_t _font_size;
    int cvtMm2Px(qreal mm);
    int cvtInch2Px(qreal in);

   public:
    ScreenTools();
    void ResizeButton(QToolButton* btn);
    void ResizeButtonBig(QToolButton* btn);
    void ResizeButton(QPushButton* btn);
    // void ResizeLabel(QLabel *label);
    // void ResizeSlider(QSlider *sld);
    // void ResizeFrame(QFrame *frame);
    void ResizePropertyPanel(QFrame* frame);
    const QSize& GetImageSize();
    const QSize& GetCellSize();
    const QSize& GetBigButtonSize();
    size_t GetFontSize();
};

#endif  // SCREENTOOLS_H
