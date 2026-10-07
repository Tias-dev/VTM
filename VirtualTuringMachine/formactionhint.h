#ifndef FORMACTIONHINT_H
#define FORMACTIONHINT_H

#include <QPixmap>
#include <QString>
#include <QWidget>

namespace Ui {
class FormActionHint;
}

class FormActionHint : public QWidget {
    Q_OBJECT

   public:
    explicit FormActionHint(const QString& txt, QPixmap& img,
                            QWidget* parent = 0);
    ~FormActionHint();

   private:
    Ui::FormActionHint* ui;
};

#endif  // FORMACTIONHINT_H
